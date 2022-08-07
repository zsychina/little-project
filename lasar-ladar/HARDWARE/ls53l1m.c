// lasar ranging module
#include "ls53l1m.h"
#define REQ_LEN 9

void request_distance()
{
  uint8_t data[REQ_LEN];
  data[0]=0x51;
  data[1]=0x0b;
  data[2]=0x00;
  data[3]=0x01;
  data[4]=0x00;
  data[5]=0x05;
  data[6]=0x02;
  data[7]=0x00;
  data[8]=0x64;
  HAL_UART_Transmit(&huart1,data,REQ_LEN,0xfff);
}


