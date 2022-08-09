#ifndef _OLED_H_
#define _OLED_H_

#include "main.h"
#include <stdio.h>
#include <stdarg.h>

//
#define OLED_I2C_ADDRESS    0x78

#define OLED_CMD        0x00
#define OLED_DATA       0x01

//
extern void OLED_Init(void);

extern void OLED_Display_On(void);
extern void OLED_Display_Off(void);

extern void OLED_SetPos(uint8_t x, uint8_t y);
extern void OLED_Refresh_Gram(void);
extern void OLED_Clear(void);

extern void OLED_DrawPoint(uint8_t x, uint8_t y, uint8_t dot);
extern void OLED_ShowChar(uint8_t x, uint8_t y, uint8_t chr);
extern void OLED_ShowString(uint8_t x, uint8_t y, uint8_t *str);
extern void OLED_printf(uint8_t row, uint8_t col, const char *fmt,...);
extern void OLED_BMP(const unsigned char bmp[128][8]);

extern void OLED_LOGO(void);



extern const unsigned char ascii_1206[95][12];
//extern const unsigned char LOGO_ROBOMASTER[128][8];
//extern const unsigned char LOGO_DLUT[128][8];
//extern const unsigned char LOGO1_DUT0BUG[128][8];
extern const unsigned char LOGO2_DUT0BUG[128][8];
extern const unsigned char BAD_APPLE[128][8];
extern const unsigned char LOGO_DLUT[128][8];

#endif
