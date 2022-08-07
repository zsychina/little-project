#ifndef DELAY_H
#define DELAY_H

#include "main.h"

extern TIM_HandleTypeDef htim11;

extern void delay_us(uint16_t us);
extern void delay_ms(uint16_t ms);

#endif
