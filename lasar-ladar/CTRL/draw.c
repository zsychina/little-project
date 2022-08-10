#include "draw.h"

#define WIDTH 1 // angle
#define LENGTH 10 // parallel lines

int64_t abs_64(int64_t num)
{
  if(num<0)return -num;
  else return num;
}


float_t tan_deg(float_t deg)
{
  if(deg==90)return 1e10;
  else if(deg<2)return tan(2*DEG2RAD);
  else if(deg>178)return tan(178*DEG2RAD);
  else return tan(deg*DEG2RAD);
}


void draw_arc(uint16_t angle,uint16_t distance)
{
  for(uint8_t x=0;x<128;x++)
  {
    for(uint8_t y=0;y<64;y++)
    {
      if(
        (abs_64((x-64)*(x-64)+(y-64)*(y-64)-distance*distance) <= 35) &&
        ((y-64)/tan_deg(angle+WIDTH)+64-LENGTH <= x) &&
        (x <= (y-64)/tan_deg(angle-WIDTH)+64+LENGTH)
      )
      {
        OLED_DrawPoint(x,y,1);
      }

    }
  }
}


void draw_bgd()
{
  // outer circle
  OLED_DrawPoint(0,59,1);
  OLED_DrawPoint(0,60,1);
  OLED_DrawPoint(0,61,1);
  OLED_DrawPoint(0,62,1);
  OLED_DrawPoint(0,63,1);
  OLED_DrawPoint(1,52,1);
  OLED_DrawPoint(1,53,1);
  OLED_DrawPoint(1,54,1);
  OLED_DrawPoint(2,48,1);
  OLED_DrawPoint(2,49,1);
  OLED_DrawPoint(3,44,1);
  OLED_DrawPoint(3,45,1);
  OLED_DrawPoint(4,42,1);
  OLED_DrawPoint(5,39,1);
  OLED_DrawPoint(6,37,1);
  OLED_DrawPoint(7,35,1);
  OLED_DrawPoint(8,33,1);
  OLED_DrawPoint(9,31,1);
  OLED_DrawPoint(10,30,1);
  OLED_DrawPoint(11,28,1);
  OLED_DrawPoint(12,27,1);
  OLED_DrawPoint(13,25,1);
  OLED_DrawPoint(14,24,1);
  OLED_DrawPoint(15,23,1);
  OLED_DrawPoint(16,22,1);
  OLED_DrawPoint(22,16,1);
  OLED_DrawPoint(23,15,1);
  OLED_DrawPoint(24,14,1);
  OLED_DrawPoint(25,13,1);
  OLED_DrawPoint(27,12,1);
  OLED_DrawPoint(28,11,1);
  OLED_DrawPoint(30,10,1);
  OLED_DrawPoint(31,9,1);
  OLED_DrawPoint(33,8,1);
  OLED_DrawPoint(35,7,1);
  OLED_DrawPoint(37,6,1);
  OLED_DrawPoint(39,5,1);
  OLED_DrawPoint(42,4,1);
  OLED_DrawPoint(44,3,1);
  OLED_DrawPoint(45,3,1);
  OLED_DrawPoint(48,2,1);
  OLED_DrawPoint(49,2,1);
  OLED_DrawPoint(52,1,1);
  OLED_DrawPoint(53,1,1);
  OLED_DrawPoint(54,1,1);
  OLED_DrawPoint(59,0,1);
  OLED_DrawPoint(60,0,1);
  OLED_DrawPoint(61,0,1);
  OLED_DrawPoint(62,0,1);
  OLED_DrawPoint(63,0,1);
  OLED_DrawPoint(64,0,1);
  OLED_DrawPoint(65,0,1);
  OLED_DrawPoint(66,0,1);
  OLED_DrawPoint(67,0,1);
  OLED_DrawPoint(68,0,1);
  OLED_DrawPoint(69,0,1);
  OLED_DrawPoint(74,1,1);
  OLED_DrawPoint(75,1,1);
  OLED_DrawPoint(76,1,1);
  OLED_DrawPoint(79,2,1);
  OLED_DrawPoint(80,2,1);
  OLED_DrawPoint(83,3,1);
  OLED_DrawPoint(84,3,1);
  OLED_DrawPoint(86,4,1);
  OLED_DrawPoint(89,5,1);
  OLED_DrawPoint(91,6,1);
  OLED_DrawPoint(93,7,1);
  OLED_DrawPoint(95,8,1);
  OLED_DrawPoint(97,9,1);
  OLED_DrawPoint(98,10,1);
  OLED_DrawPoint(100,11,1);
  OLED_DrawPoint(101,12,1);
  OLED_DrawPoint(103,13,1);
  OLED_DrawPoint(104,14,1);
  OLED_DrawPoint(105,15,1);
  OLED_DrawPoint(106,16,1);
  OLED_DrawPoint(112,22,1);
  OLED_DrawPoint(113,23,1);
  OLED_DrawPoint(114,24,1);
  OLED_DrawPoint(115,25,1);
  OLED_DrawPoint(116,27,1);
  OLED_DrawPoint(117,28,1);
  OLED_DrawPoint(118,30,1);
  OLED_DrawPoint(119,31,1);
  OLED_DrawPoint(120,33,1);
  OLED_DrawPoint(121,35,1);
  OLED_DrawPoint(122,37,1);
  OLED_DrawPoint(123,39,1);
  OLED_DrawPoint(124,42,1);
  OLED_DrawPoint(125,44,1);
  OLED_DrawPoint(125,45,1);
  OLED_DrawPoint(126,48,1);
  OLED_DrawPoint(126,49,1);
  OLED_DrawPoint(127,52,1);
  OLED_DrawPoint(127,53,1);
  OLED_DrawPoint(127,54,1);
  // inner circle
  OLED_DrawPoint(32,60,1);
  OLED_DrawPoint(32,61,1);
  OLED_DrawPoint(32,62,1);
  OLED_DrawPoint(32,63,1);
  OLED_DrawPoint(33,55,1);
  OLED_DrawPoint(33,56,1);
  OLED_DrawPoint(33,57,1);
  OLED_DrawPoint(34,52,1);
  OLED_DrawPoint(34,53,1);
  OLED_DrawPoint(35,50,1);
  OLED_DrawPoint(35,51,1);
  OLED_DrawPoint(36,48,1);
  OLED_DrawPoint(36,49,1);
  OLED_DrawPoint(37,47,1);
  OLED_DrawPoint(38,45,1);
  OLED_DrawPoint(39,44,1);
  OLED_DrawPoint(40,43,1);
  OLED_DrawPoint(41,42,1);
  OLED_DrawPoint(42,41,1);
  OLED_DrawPoint(43,40,1);
  OLED_DrawPoint(44,39,1);
  OLED_DrawPoint(45,38,1);
  OLED_DrawPoint(47,37,1);
  OLED_DrawPoint(48,36,1);
  OLED_DrawPoint(49,36,1);
  OLED_DrawPoint(50,35,1);
  OLED_DrawPoint(51,35,1);
  OLED_DrawPoint(52,34,1);
  OLED_DrawPoint(53,34,1);
  OLED_DrawPoint(55,33,1);
  OLED_DrawPoint(56,33,1);
  OLED_DrawPoint(57,33,1);
  OLED_DrawPoint(60,32,1);
  OLED_DrawPoint(61,32,1);
  OLED_DrawPoint(62,32,1);
  OLED_DrawPoint(63,32,1);
  OLED_DrawPoint(64,32,1);
  OLED_DrawPoint(65,32,1);
  OLED_DrawPoint(66,32,1);
  OLED_DrawPoint(67,32,1);
  OLED_DrawPoint(68,32,1);
  OLED_DrawPoint(71,33,1);
  OLED_DrawPoint(72,33,1);
  OLED_DrawPoint(73,33,1);
  OLED_DrawPoint(75,34,1);
  OLED_DrawPoint(76,34,1);
  OLED_DrawPoint(77,35,1);
  OLED_DrawPoint(78,35,1);
  OLED_DrawPoint(79,36,1);
  OLED_DrawPoint(80,36,1);
  OLED_DrawPoint(81,37,1);
  OLED_DrawPoint(83,38,1);
  OLED_DrawPoint(84,39,1);
  OLED_DrawPoint(85,40,1);
  OLED_DrawPoint(86,41,1);
  OLED_DrawPoint(87,42,1);
  OLED_DrawPoint(88,43,1);
  OLED_DrawPoint(89,44,1);
  OLED_DrawPoint(90,45,1);
  OLED_DrawPoint(91,47,1);
  OLED_DrawPoint(92,48,1);
  OLED_DrawPoint(92,49,1);
  OLED_DrawPoint(93,50,1);
  OLED_DrawPoint(93,51,1);
  OLED_DrawPoint(94,52,1);
  OLED_DrawPoint(94,53,1);
  OLED_DrawPoint(95,55,1);
  OLED_DrawPoint(95,56,1);
  OLED_DrawPoint(95,57,1);
  OLED_DrawPoint(96,60,1);
  OLED_DrawPoint(96,61,1);
  OLED_DrawPoint(96,62,1);
  OLED_DrawPoint(96,63,1);
  // line y=x
  OLED_DrawPoint(0,0,1);
  OLED_DrawPoint(1,1,1);
  OLED_DrawPoint(2,2,1);
  OLED_DrawPoint(3,3,1);
  OLED_DrawPoint(4,4,1);
  OLED_DrawPoint(5,5,1);
  OLED_DrawPoint(6,6,1);
  OLED_DrawPoint(7,7,1);
  OLED_DrawPoint(8,8,1);
  OLED_DrawPoint(9,9,1);
  OLED_DrawPoint(10,10,1);
  OLED_DrawPoint(11,11,1);
  OLED_DrawPoint(12,12,1);
  OLED_DrawPoint(13,13,1);
  OLED_DrawPoint(14,14,1);
  OLED_DrawPoint(15,15,1);
  OLED_DrawPoint(16,16,1);
  OLED_DrawPoint(17,17,1);
  OLED_DrawPoint(18,18,1);
  OLED_DrawPoint(19,19,1);
  OLED_DrawPoint(20,20,1);
  OLED_DrawPoint(21,21,1);
  OLED_DrawPoint(22,22,1);
  OLED_DrawPoint(23,23,1);
  OLED_DrawPoint(24,24,1);
  OLED_DrawPoint(25,25,1);
  OLED_DrawPoint(26,26,1);
  OLED_DrawPoint(27,27,1);
  OLED_DrawPoint(28,28,1);
  OLED_DrawPoint(29,29,1);
  OLED_DrawPoint(30,30,1);
  OLED_DrawPoint(31,31,1);
  OLED_DrawPoint(32,32,1);
  OLED_DrawPoint(33,33,1);
  OLED_DrawPoint(34,34,1);
  OLED_DrawPoint(35,35,1);
  OLED_DrawPoint(36,36,1);
  OLED_DrawPoint(37,37,1);
  OLED_DrawPoint(38,38,1);
  OLED_DrawPoint(39,39,1);
  OLED_DrawPoint(40,40,1);
  OLED_DrawPoint(41,41,1);
  OLED_DrawPoint(42,42,1);
  OLED_DrawPoint(43,43,1);
  OLED_DrawPoint(44,44,1);
  OLED_DrawPoint(45,45,1);
  OLED_DrawPoint(46,46,1);
  OLED_DrawPoint(47,47,1);
  OLED_DrawPoint(48,48,1);
  OLED_DrawPoint(49,49,1);
  OLED_DrawPoint(50,50,1);
  OLED_DrawPoint(51,51,1);
  OLED_DrawPoint(52,52,1);
  OLED_DrawPoint(53,53,1);
  OLED_DrawPoint(54,54,1);
  OLED_DrawPoint(55,55,1);
  OLED_DrawPoint(56,56,1);
  OLED_DrawPoint(57,57,1);
  OLED_DrawPoint(58,58,1);
  OLED_DrawPoint(59,59,1);
  OLED_DrawPoint(60,60,1);
  OLED_DrawPoint(61,61,1);
  OLED_DrawPoint(62,62,1);
  OLED_DrawPoint(63,63,1);
  // line y=-x+128
  OLED_DrawPoint(65,63,1);
  OLED_DrawPoint(66,62,1);
  OLED_DrawPoint(67,61,1);
  OLED_DrawPoint(68,60,1);
  OLED_DrawPoint(69,59,1);
  OLED_DrawPoint(70,58,1);
  OLED_DrawPoint(71,57,1);
  OLED_DrawPoint(72,56,1);
  OLED_DrawPoint(73,55,1);
  OLED_DrawPoint(74,54,1);
  OLED_DrawPoint(75,53,1);
  OLED_DrawPoint(76,52,1);
  OLED_DrawPoint(77,51,1);
  OLED_DrawPoint(78,50,1);
  OLED_DrawPoint(79,49,1);
  OLED_DrawPoint(80,48,1);
  OLED_DrawPoint(81,47,1);
  OLED_DrawPoint(82,46,1);
  OLED_DrawPoint(83,45,1);
  OLED_DrawPoint(84,44,1);
  OLED_DrawPoint(85,43,1);
  OLED_DrawPoint(86,42,1);
  OLED_DrawPoint(87,41,1);
  OLED_DrawPoint(88,40,1);
  OLED_DrawPoint(89,39,1);
  OLED_DrawPoint(90,38,1);
  OLED_DrawPoint(91,37,1);
  OLED_DrawPoint(92,36,1);
  OLED_DrawPoint(93,35,1);
  OLED_DrawPoint(94,34,1);
  OLED_DrawPoint(95,33,1);
  OLED_DrawPoint(96,32,1);
  OLED_DrawPoint(97,31,1);
  OLED_DrawPoint(98,30,1);
  OLED_DrawPoint(99,29,1);
  OLED_DrawPoint(100,28,1);
  OLED_DrawPoint(101,27,1);
  OLED_DrawPoint(102,26,1);
  OLED_DrawPoint(103,25,1);
  OLED_DrawPoint(104,24,1);
  OLED_DrawPoint(105,23,1);
  OLED_DrawPoint(106,22,1);
  OLED_DrawPoint(107,21,1);
  OLED_DrawPoint(108,20,1);
  OLED_DrawPoint(109,19,1);
  OLED_DrawPoint(110,18,1);
  OLED_DrawPoint(111,17,1);
  OLED_DrawPoint(112,16,1);
  OLED_DrawPoint(113,15,1);
  OLED_DrawPoint(114,14,1);
  OLED_DrawPoint(115,13,1);
  OLED_DrawPoint(116,12,1);
  OLED_DrawPoint(117,11,1);
  OLED_DrawPoint(118,10,1);
  OLED_DrawPoint(119,9,1);
  OLED_DrawPoint(120,8,1);
  OLED_DrawPoint(121,7,1);
  OLED_DrawPoint(122,6,1);
  OLED_DrawPoint(123,5,1);
  OLED_DrawPoint(124,4,1);
  OLED_DrawPoint(125,3,1);
  OLED_DrawPoint(126,2,1);
  OLED_DrawPoint(127,1,1);
  // line x=64
  OLED_DrawPoint(64,0,1);
  OLED_DrawPoint(64,1,1);
  OLED_DrawPoint(64,2,1);
  OLED_DrawPoint(64,3,1);
  OLED_DrawPoint(64,4,1);
  OLED_DrawPoint(64,5,1);
  OLED_DrawPoint(64,6,1);
  OLED_DrawPoint(64,7,1);
  OLED_DrawPoint(64,8,1);
  OLED_DrawPoint(64,9,1);
  OLED_DrawPoint(64,10,1);
  OLED_DrawPoint(64,11,1);
  OLED_DrawPoint(64,12,1);
  OLED_DrawPoint(64,13,1);
  OLED_DrawPoint(64,14,1);
  OLED_DrawPoint(64,15,1);
  OLED_DrawPoint(64,16,1);
  OLED_DrawPoint(64,17,1);
  OLED_DrawPoint(64,18,1);
  OLED_DrawPoint(64,19,1);
  OLED_DrawPoint(64,20,1);
  OLED_DrawPoint(64,21,1);
  OLED_DrawPoint(64,22,1);
  OLED_DrawPoint(64,23,1);
  OLED_DrawPoint(64,24,1);
  OLED_DrawPoint(64,25,1);
  OLED_DrawPoint(64,26,1);
  OLED_DrawPoint(64,27,1);
  OLED_DrawPoint(64,28,1);
  OLED_DrawPoint(64,29,1);
  OLED_DrawPoint(64,30,1);
  OLED_DrawPoint(64,31,1);
  OLED_DrawPoint(64,32,1);
  OLED_DrawPoint(64,33,1);
  OLED_DrawPoint(64,34,1);
  OLED_DrawPoint(64,35,1);
  OLED_DrawPoint(64,36,1);
  OLED_DrawPoint(64,37,1);
  OLED_DrawPoint(64,38,1);
  OLED_DrawPoint(64,39,1);
  OLED_DrawPoint(64,40,1);
  OLED_DrawPoint(64,41,1);
  OLED_DrawPoint(64,42,1);
  OLED_DrawPoint(64,43,1);
  OLED_DrawPoint(64,44,1);
  OLED_DrawPoint(64,45,1);
  OLED_DrawPoint(64,46,1);
  OLED_DrawPoint(64,47,1);
  OLED_DrawPoint(64,48,1);
  OLED_DrawPoint(64,49,1);
  OLED_DrawPoint(64,50,1);
  OLED_DrawPoint(64,51,1);
  OLED_DrawPoint(64,52,1);
  OLED_DrawPoint(64,53,1);
  OLED_DrawPoint(64,54,1);
  OLED_DrawPoint(64,55,1);
  OLED_DrawPoint(64,56,1);
  OLED_DrawPoint(64,57,1);
  OLED_DrawPoint(64,58,1);
  OLED_DrawPoint(64,59,1);
  OLED_DrawPoint(64,60,1);
  OLED_DrawPoint(64,61,1);
  OLED_DrawPoint(64,62,1);
  OLED_DrawPoint(64,63,1);
}



