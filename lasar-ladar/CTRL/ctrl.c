#include "ctrl.h"


#define BUF_LEN 11
#define BUF_LEN_RC 3

#define MOTOR_STEP 3

uint16_t tim1clk=0; //0~999
uint16_t pwm_h=2500; //500~2500
uint8_t pwm_dir=0; // 1:++ , 0:--

uint8_t ReceiveByte;
uint8_t ReceiveBuff[BUF_LEN]={0};
uint8_t ReceiveCnt=0;

uint8_t ReceiveByte_rc;
uint8_t ReceiveBuff_rc[BUF_LEN_RC]={0};
uint8_t ReceiveCnt_rc=0;

uint16_t angle; // theortically 0~180
uint16_t distance; // millimeter
uint16_t result[100][2]; // [angle][distance]

uint8_t rc_order[3];
uint8_t rst_flag=0; 


void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
  if(htim==&htim1) // 1kHz  NO-LOOGER THAN 1 MS
  {
    tim1clk++;
    tim1clk%=1000;
    
    if(rst_flag==1) // reset
    {
      for(uint8_t i=0;i<100;i++)
      {
        result[i][0]=0;
        result[i][1]=0;
      }
      pwm_h=2500;
      pwm_dir=0;
      
      rst_flag=0;      
    }
    
    if(tim1clk%5==1) //200Hz
    { 
      request_distance();
      angle=(uint16_t)(180-(1800.0*(pwm_h/20000.0)-45.0));
      result[(uint8_t)(angle*(5.0/9))][0]=angle;
      result[(uint8_t)(angle*(5.0/9))][1]=distance;
      if(result[(uint8_t)(angle*(5.0/9))][1]>=1000)result[(uint8_t)(angle*(5.0/9))][1]=1000;
      if(result[(uint8_t)(angle*(5.0/9))][1]<=100)result[(uint8_t)(angle*(5.0/9))][1]=100;
    }
    if(tim1clk%20==1) //50Hz
    {
      if(rc_order[2]!=0x16) // continue
      {       
        if(pwm_dir==1)pwm_h+=MOTOR_STEP;else pwm_h-=MOTOR_STEP;
        if(pwm_h<=500){pwm_h=500;pwm_dir=pwm_cvt(pwm_dir);}
        if(pwm_h>=2500){pwm_h=2500;pwm_dir=pwm_cvt(pwm_dir);}
        __HAL_TIM_SetCompare(&htim10,TIM_CHANNEL_1,pwm_h);
      }else
      if(rc_order[0]==0x00&&
         rc_order[1]==0xff&&
         rc_order[2]==0x16) // halt
      {
        __HAL_TIM_SetCompare(&htim10,TIM_CHANNEL_1,pwm_h);        
      }
    }
    if(tim1clk%50==1) //20Hz
    {
      // OLED_Clear();
      // OLED_printf(0,0,"range=%4dmm",distance);
      // for(uint8_t i=0;i<100;i++)
      // {
      //   draw_arc((uint16_t)result[i][0],(uint16_t)(result[i][1]/15.625)); // 500mm => 32 pixels
      // }
      // draw_bgd();
      // OLED_Refresh_Gram();
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
  if(huart==&huart2)
  {
    ReceiveBuff_rc[ReceiveCnt_rc]=ReceiveByte_rc;
    ReceiveCnt_rc++;  //save data into ReceiveBuff
    if(ReceiveCnt_rc==BUF_LEN_RC)ReceiveCnt_rc=0;
    HAL_UART_Receive_IT(&huart2,&ReceiveByte_rc,1); 
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
  if(huart==&huart2)
  {
    if(__HAL_UART_GET_FLAG(&huart2,UART_FLAG_IDLE)!=RESET)  // IDLE interrupt happened
    {
      __HAL_UART_CLEAR_IDLEFLAG(&huart2); //clear IDLE flag
      
      // respond (do something)
      //HAL_UART_Transmit(&huart1,ReceiveBuff,BUF_LEN,0xfff);

      //distance=ReceiveBuff[8]<<8|ReceiveBuff[9];
      if(ReceiveBuff_rc[0]==0x00&&
         ReceiveBuff_rc[1]==0xff&&
         ReceiveBuff_rc[2]==0x19)
      {
        rst_flag=1;
      }
      // clear the buff afterwards
      ReceiveCnt_rc=0;
      
      
      for(uint8_t i=0;i<BUF_LEN_RC;i++)  //clear buff
      {
          rc_order[i]=ReceiveBuff_rc[i];
          ReceiveBuff_rc[i]=0;		
      }

    }
	
  }
}





