#include "led_struct.h"

void nhay_led(struct t_hop *s)
{
	if(s->flag)
	{
		if(HAL_GetTick()- s->last_time >= s->time_led1)
		{
			HAL_GPIO_TogglePin(s->GPIOx, s->GPIO_Pin);
			s->flag = 0;
			s->last_time = HAL_GetTick();
		}
	}
	else
		if(HAL_GetTick()- s->last_time >= s->time_led2)
		{
			HAL_GPIO_TogglePin(s->GPIOx, s->GPIO_Pin);
			s->flag = 1;
			s->last_time = HAL_GetTick();
		}
}
