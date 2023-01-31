#ifndef __LEDSTRUCT_H
#define __LEDSTRUCT_H
#include "main.h"

#define LED_SERVER 	0
#define LED_ERROR	1

typedef enum {
	LED_MODE_BLINK_FAST,
	LED_MODE_BLINK_SLOW,
	LED_MODE_ON,
	LED_MODE_OFF
} led_mode_t;

void led_init(void);

void led_main_function(void);

void led_control(uint32_t led_number, led_mode_t led_mode);

void button_control_led();

#endif
