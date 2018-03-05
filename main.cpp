#include "iostm8s003f3.h"   // ����������� ������������� ����� � ������������ ���������. ����� � �����
#include "max.h"
#include "init.h"
//#include "temperature.h"
//#include "LSD.h"
//#include "Button.h"

#define BL PC_IDR_IDR5
//__interrupt void TIM4_OVR_UIF_handler(void);

//----Var & Def ----------------------------------------------------------------
//#pragma location=0x4000
//__no_init u8 flash_var[3];
u8 duty=0;
u8 accum = 1;
u16 temp;
u8 new_cicle=0;
//---- funct -------------------------------------------------------------------

u16 ADC_Measuring(u8 N)
{ u16 ADC = 0;

  for (u16 i=0; i<(1<<N);i++)
  {
   
    ADC_CR1_ADON = 1;// ������ ���������
    while (!ADC_CSR_EOC) {};//���� �������������� ; 
    ADC_CSR_EOC = 0 ; //�������� ���� ���������� ��������������
    ADC += ADC_DRL;
    ADC += (ADC_DRH)<<8;
  };
  ADC=(ADC>>N);
  return(ADC);
};



//==== MAIN ====================================================================
int main(void) // �������� ���������
{//initTemperature();
  Init();
  ADC_CR1_ADON = 1;
  while(1)
  {// TIM1_CCR3L=100;/*
    if (new_cicle) 
    {
      new_cicle=0;
      Delay(720);
      temp=ADC_Measuring(6);
//      if (duty==0) duty = 1;
//      if (duty==100) duty = 99;
      if ((temp<800)&(duty>0)) duty--;
      if ((temp>828)&(duty<100)) duty++;
      if (BL == 1) duty = 0;
      TIM1_CCR3L = duty;
      PC_ODR_ODR7=0;
    };/**/
  };     // ����������� ����
};

//==== INTERRUPTS ==============================================================
/*
// ������ ���������� �� ���������� ��� ������������ �������2
#pragma vector = TIM4_OVR_UIF_vector 
__interrupt void TIM4_OVR_UIF_handler(void)
{ 
  TIM4_SR_UIF = 0;  // �������� ����
 
} ;*/

 // ������ ���������� �� ���������� ��� ������������ �������2
#pragma vector = TIM1_OVR_UIF_vector 
__interrupt void TIM1_OVR_UIF_handler(void)
{ 
  TIM1_SR1_UIF = 0;  // �������� ����
  new_cicle=1;
  PC_ODR_ODR7=1;
/*  if (duty==0) duty = 1;
  if (duty==100) duty = 99;
  if (accum == 0) duty=100; else duty=0;
  if (BL == 1) duty = 0;
  
  TIM1_CCR3L = duty;
  
  temp = ADC_Measuring(3);
  if (temp>837) accum = 0;
  if (temp<789) accum = 1;
  
  PC_ODR_ODR7++;
  */
};
/*
/ ������ ���������� �� ���������� ��� ������������ �������2
#pragma vector = TIM2_OVR_UIF_vector 
__interrupt void TIM2_OVR_UIF_handler(void)
{ 
  TIM2_SR1_UIF = 0;  // �������� ����
  
};
 //TIM2_CCR3H = 0x7A; TIM2_CCR3L = 0x12;// duty 50%*/
//==== function ================================================================
