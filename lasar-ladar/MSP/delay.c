#include "delay.h"


void delay_us(uint16_t us)
{
  __HAL_TIM_SET_COUNTER(&htim11,0);
  while(__HAL_TIM_GET_COUNTER(&htim11)<us);
}

void delay_ms(uint16_t ms)
{
  while(ms--)delay_us(1000);
}

