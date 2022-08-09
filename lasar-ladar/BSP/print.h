#ifndef __PRINT_H__
#define __PRINT_H__


#include "main.h"
#include "string.h"
#include "stdio.h"
#include "stdarg.h"
#include "usart.h"



extern void usart_printf(UART_HandleTypeDef *huart,char *fmt, ...);
extern void drawPtintf(UART_HandleTypeDef *huart, uint8_t name, float value);
extern void print_string(UART_HandleTypeDef *huart,char *str);




#endif
