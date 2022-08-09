#ifndef CTRL_H
#define CTRL_H

#include "main.h"

extern TIM_HandleTypeDef htim1;
extern UART_HandleTypeDef huart1;
extern TIM_HandleTypeDef htim10;

uint8_t pwm_cvt(uint8_t dir)
{
  if(dir==1)return 0;
  else return 1;
}

#endif
