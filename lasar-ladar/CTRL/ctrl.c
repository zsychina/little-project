#include "ctrl.h"
#include "ls53l1m.h"
#include "oled.h"

#define BUF_LEN 11

uint16_t tim1clk=0; //0~999

uint8_t ReceiveByte;
uint8_t ReceiveBuff[BUF_LEN]={0};
uint8_t ReceiveCnt=0;

uint16_t distance=0; // millimeter

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
  if(htim==&htim1) // 1kHz  NO-LOOGER THAN 1 MS
  {
    tim1clk++;
    tim1clk%=1000;
    if(tim1clk%1==1) //1kHz
    {

    }
    if(tim1clk%10==1) //100Hz
    { 
      request_distance();
    }
    if(tim1clk%200==1) //5Hz
    {
      OLED_ShowString(0,0,"designed by zsy",8);
      OLED_ShowString(0,2,"under developing...",8);
    }
  }
}


void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
	if(huart==&huart1)
	{
			ReceiveBuff[ReceiveCnt]=ReceiveByte;
			ReceiveCnt++;  //save data into ReceiveBuff
			if(ReceiveCnt==BUF_LEN)ReceiveCnt=0;
			HAL_UART_Receive_IT(&huart1,&ReceiveByte,1);
		
	}
	
}


void UART_IDLECallBack(UART_HandleTypeDef *huart)
{
	if(huart==&huart1)
	{
		if(__HAL_UART_GET_FLAG(&huart1,UART_FLAG_IDLE)!=RESET)  // IDLE interrupt happened
		{
			__HAL_UART_CLEAR_IDLEFLAG(&huart1); //clear IDLE flag
			
			// respond (do something)
			//HAL_UART_Transmit(&huart1,ReceiveBuff,BUF_LEN,0xfff);
      
			distance=ReceiveBuff[8]<<8|ReceiveBuff[9];
      
      
			// clear the buff afterwards
      ReceiveCnt=0;
			for(uint8_t i=0;i<BUF_LEN;i++)  //clear buff
			{
				ReceiveBuff[i]=0;		
			}
			
		}		
	}
}





