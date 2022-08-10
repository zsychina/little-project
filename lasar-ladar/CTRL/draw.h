#ifndef DRAW_H
#define DRAW_H

#include "main.h"
#include "oled.h"
#include "math.h"

#define DEG2RAD (3.141592653589793238462643/180.0)

// extern uint8_t OLED_GRAM[128][8];



void draw_bgd(void);
void draw_arc(uint16_t angle,uint16_t distance);



#endif
