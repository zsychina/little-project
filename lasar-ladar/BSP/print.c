#include "print.h"


void usart_printf(UART_HandleTypeDef *huart,char *fmt, ...) 
{
  static uint8_t tx_buf[300] = {0};
  static va_list ap;
  static uint16_t len;
  va_start(ap, fmt);

  len = vsprintf((char *)tx_buf, fmt, ap);
  va_end(ap);
	
  HAL_UART_Transmit(huart,tx_buf,len,500);
}

void drawPtintf(UART_HandleTypeDef *huart, uint8_t name, float value)
{
  char buf[20];
  sprintf(buf, "Line%d=%.2f,", name, value);
  usart_printf(huart,buf);
}

void print_string(UART_HandleTypeDef *huart,char *str)
{	
	usart_printf(huart,str);
}




