#ifndef OLED_H
#define OLED_H

#include "main.h"


//device
#define OLED_I2C_ADDRESS    0x78

//private
#define OLED_CMD        0x00
#define OLED_DATA       0x01

//rely
extern I2C_HandleTypeDef hi2c1;


//Functions
extern void oled_write_byte(uint8_t ctrl, uint8_t data);
extern void OLED_Init(void);
extern void OLED_Display_On(void);
extern void OLED_Display_Off(void);
extern void OLED_On(void);
extern void OLED_SetPos(uint8_t x, uint8_t y);
extern void OLED_Clear(void);
extern void OLED_ShowChar(uint8_t x, uint8_t y, uint8_t chr,uint8_t Char_Size);
extern void OLED_ShowNum(uint8_t x, uint8_t y, int32_t num, uint8_t len, uint8_t size2);
extern void OLED_ShowString(uint8_t x, uint8_t y, char *str, uint8_t Char_Size);
extern void OLED_ShowCHinese(uint8_t x,uint8_t y,uint8_t no);
extern void OLED_ShowNum2(uint8_t x, uint8_t y, int32_t num, uint8_t len, uint8_t size);
//API





#endif


