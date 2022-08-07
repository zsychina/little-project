#include "oled.h"
#include "oledfont.h"


//decide ctrl is a CMD header or a DATA header
void oled_write_byte(uint8_t ctrl, uint8_t data)
{
	uint8_t buff[2];
	if(ctrl==OLED_CMD)buff[0]=0x00;
	else if(ctrl==OLED_DATA)buff[0]=0x40;
	buff[1]=data;
	HAL_I2C_Master_Transmit(&hi2c1,OLED_I2C_ADDRESS,buff,2,0x1ff);
}



void OLED_Init(void)
{
	oled_write_byte(OLED_CMD,0xAE);//关闭显示
	oled_write_byte(OLED_CMD,0x40);//---set low column address
	oled_write_byte(OLED_CMD,0xB0);//---set high column address
	oled_write_byte(OLED_CMD,0xC8);//-not offset
	oled_write_byte(OLED_CMD,0x81);//设置对比度
	oled_write_byte(OLED_CMD,0xff);
	oled_write_byte(OLED_CMD,0xa1);//段重定向设置
	oled_write_byte(OLED_CMD,0xa6);//
	oled_write_byte(OLED_CMD,0xa8);//设置驱动路数
	oled_write_byte(OLED_CMD,0x1f);
	oled_write_byte(OLED_CMD,0xd3);
	oled_write_byte(OLED_CMD,0x00);
	oled_write_byte(OLED_CMD,0xd5);
	oled_write_byte(OLED_CMD,0xf0);
	oled_write_byte(OLED_CMD,0xd9);
	oled_write_byte(OLED_CMD,0x22);
	oled_write_byte(OLED_CMD,0xda);
	oled_write_byte(OLED_CMD,0x02);
	oled_write_byte(OLED_CMD,0xdb);
	oled_write_byte(OLED_CMD,0x49);
	oled_write_byte(OLED_CMD,0x8d);
	oled_write_byte(OLED_CMD,0x14);
	oled_write_byte(OLED_CMD,0xaf);
	OLED_Clear();	
}

//turn on OLED
void OLED_Display_On(void)
{
	oled_write_byte(OLED_CMD, 0x8D); 
	oled_write_byte(OLED_CMD, 0x14); //Set Charge Pump Enable
	oled_write_byte(OLED_CMD, 0xAF); //Display ON
}

//turn off OLED
void OLED_Display_Off(void)
{
	oled_write_byte(OLED_CMD, 0x8D); 
	oled_write_byte(OLED_CMD, 0x10); //Set Charge Pump Disable
	oled_write_byte(OLED_CMD, 0xAE); //Display OFF
}

//set cesor location
void OLED_SetPos(uint8_t x, uint8_t y)
{
	oled_write_byte(OLED_CMD, (0xB0+y)); //set page address y
	oled_write_byte(OLED_CMD, ((x&0xF0)>>4)|0x10); //set column high address
	oled_write_byte(OLED_CMD, (x&0x0F)); //set column low address
}



//cls
void OLED_Clear(void)
{
	uint8_t i,n;
	for(i=0;i<8;i++)
	{
		//OLED_SetPos(0,i);
		oled_write_byte(OLED_CMD,0xb0+i);
		oled_write_byte(OLED_CMD,0x00);
		oled_write_byte(OLED_CMD,0x10);
		for(n=0;n<128;n++)oled_write_byte(OLED_DATA, 0);
	}
}

void OLED_On(void)
{
	uint8_t i,n;
	for(i=0;i<8;i++)
	{
		oled_write_byte(OLED_CMD,0xb0+i);
		oled_write_byte(OLED_CMD,0x00);
		oled_write_byte(OLED_CMD,0x10);
		for(n=0;n<128;n++)oled_write_byte(OLED_DATA, 1);
	}
}

// y is page number, not pixel number
void OLED_ShowChar(uint8_t x, uint8_t y, uint8_t chr, uint8_t Char_Size)
{
	uint8_t c=0,i=0;
	c=chr-' ';
	if(x>127){x=0;y+=2;}
	if(Char_Size==16)
	{
		OLED_SetPos(x,y);
		for(i=0;i<8;i++)
		{
			oled_write_byte(OLED_DATA,F8X16[c*16+i]);
		}
		
		OLED_SetPos(x,y+1);
		for(i=0;i<8;i++)
		{
			oled_write_byte(OLED_DATA,F8X16[c*16+8+i]);
		}
	}else{
		OLED_SetPos(x,y);
		for(i=0;i<6;i++)
		{
			oled_write_byte(OLED_DATA,F6x8[c][i]);
		}
		
	}
	
}


uint32_t oled_pow(uint8_t m, uint8_t n)
{
	uint32_t result=1;
	while(n--)result*=m;
	return result;
}


//显示2个数字
//x,y :起点坐标	 
//len :数字的位数
//size:字体大小
//mode:模式	0,填充模式;1,叠加模式
//num:数值(0~4294967295);	 		  
void OLED_ShowNum(uint8_t x, uint8_t y, uint32_t num, uint8_t len, uint8_t size2)
{
	uint8_t t,temp,enshow=0;
	for(t=0;t<len;t++)
	{
		temp=(num/oled_pow(10,len-t-1))%10;
		if(enshow==0&&t<(len-1))
		{
			if(temp==0)
			{
				OLED_ShowChar(x+(size2/2)*t,y,' ',size2);
				continue;
			}else enshow=1; 
		 	 
		}
	 	OLED_ShowChar(x+(size2/2)*t,y,temp+'0',size2); 
	}	
	
}

//display string
void OLED_ShowString(uint8_t x, uint8_t y, char *str, uint8_t Char_Size)
{
	uint8_t j=0;
	while(str[j]!='\0')
	{
		OLED_ShowChar(x,y,str[j],Char_Size);
		x+=8;
		if(x>120){x=0;y+=2;}
		j++;
	}
}



void OLED_ShowCHinese(uint8_t x,uint8_t y,uint8_t no)
{      			    
	uint8_t t,adder=0;
	OLED_SetPos(x,y);	
	for(t=0;t<16;t++)
	{
		oled_write_byte(OLED_DATA, CHI[2*no][t]);
		adder+=1;
	}	
	OLED_SetPos(x,y+1);	
	for(t=0;t<16;t++)
	{	
		oled_write_byte(OLED_DATA, CHI[2*no+1][t]);
		adder+=1;
	}					
}








