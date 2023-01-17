#ifndef __LEDSTRUCT_H
#define __LEDSTRUCT_H
#include "main.h"

struct t_hop{
	uint32_t last_time;
	GPIO_TypeDef * GPIOx;
	uint16_t GPIO_Pin;
	uint32_t time_led1;
	uint32_t time_led2;
	uint32_t flag;
};
void nhay_led(struct t_hop *s);
#endif
