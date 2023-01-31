#include "led_struct.h"
#include "stm32l4xx_hal.h"

#define LED_ON 		1
#define LED_OFF 	0

typedef struct {
	uint32_t time_on;
	uint32_t time_off;
	GPIO_TypeDef* port;
	uint32_t pin;
	uint32_t status;
	uint32_t start_tick;
} led_t;


led_t led_arr[] =
{
	{5000, 1000, GPIOB, GPIO_PIN_13, 1, 0},
	{1000, 1000, GPIOA, GPIO_PIN_5, 1, 0}

};

static void led_driver(led_t *led);

void led_init(void)
{

}

void led_main_function(void)
{
	for (uint8_t i = 0; i < sizeof(led_arr)/sizeof(led_t); i++)
	{
		led_driver(&led_arr[i]);
	}
}

/*
 * Function name: led_driver
 * Brief: This function help to control leds
 * Params[1]: led_t *led
 * Return: void
 */
static void led_driver(led_t *led)
{
	// Check if led is On or Off
	if(led->status == LED_ON)
	{
		// Event when turn off led
		if((HAL_GetTick() - led->start_tick) >= led->time_on)
		{
			HAL_GPIO_WritePin(led->port, led->pin, 1);
			led->status = LED_OFF;
		}
	}
	else
	{
		if((HAL_GetTick() - led->start_tick - led->time_on) >= led->time_off)
		{
			HAL_GPIO_WritePin(led->port, led->pin, 0);
			led->status = LED_ON;
			led->start_tick = HAL_GetTick();
		}
	}
}
void led_control(uint32_t led_number, led_mode_t led_mode)
{
	switch (led_mode)
	{
	case LED_MODE_BLINK_FAST:
		led_arr[led_number].time_on = 100;
		led_arr[led_number].time_off = 100;
		break;
	case LED_MODE_BLINK_SLOW:
		led_arr[led_number].time_on = 1000;
		led_arr[led_number].time_off = 1000;
		break;
	case LED_MODE_ON:
		led_arr[led_number].time_on = 1000;
		led_arr[led_number].time_off = 0000;
		break;
	case LED_MODE_OFF:
		led_arr[led_number].time_on = 0000;
		led_arr[led_number].time_off = 1000;
		break;
	}
}
void button_control_led()
{
	if(HAL_GPIO_ReadPin(GPIOI, GPIO_PIN_11) == 0)
	{
		led_control(LED_SERVER, LED_MODE_BLINK_FAST);
	}
	else if(HAL_GPIO_ReadPin(GPIOI, GPIO_PIN_8) == 0)
		{
		led_control(LED_SERVER, LED_MODE_BLINK_SLOW);
		}
	else if (HAL_GPIO_ReadPin(GPIOI, GPIO_PIN_9) == 0)
		{
		led_control(LED_SERVER, LED_MODE_ON);
		}
	else if (HAL_GPIO_ReadPin(GPIOI, GPIO_PIN_10) == 0)
		{
		led_control(LED_SERVER, LED_MODE_OFF);
		}
}
