#include "init.h"
#include "iostm8s003f3.h"
#include "max.h"

//====INIT======================================================================
void Init(void)
{
//----GPIO----------------------------------------------------------------------  
 PC_DDR_DDR5 = 0; PC_CR1_C15 = 1; PC_CR2_C25 = 0; //

 PC_DDR_DDR7 = 1; PC_CR1_C17 = 1; PC_CR2_C27 = 0; //

//----ADC-----------------------------------------------------------------------
  ADC_CSR_EOCIE = 0;//interrupt off
  ADC_CSR_CH = 5;   //adc chanel = TCHANEL                                            ///выбор канала
  ADC_CR1_SPSEL = b111;//f = Fmaster/18 2/9=200khz 
  ADC_CR1_CONT = 0; //not continuos
  ADC_CR2_ALIGN = 1;//right align
  ADC_TDRH = 0;     //off schmitt trigger
  ADC_TDRL = 0; 
  ADC_CR1_ADON = 1; //wake up ADC   
//----CLOCK-------------------------------------------------------------def2Mh  
  CLK_CKDIVR_HSIDIV = b11;// 2Mhz
 // CLK_CKDIVR_CPUDIV = b111;// 1/2
  //----INTERRUPTS----------------------------------------------------------------
  asm("rim"); //–азрешаем прерывани€
//----TIM1----------------------------------------------------------------------  
  TIM1_CR1_ARPE = 1; //buffered ARR обновление на следующей итерации
  TIM1_CR1_OPM = 0; //one puls mode off
  TIM1_CR1_URS = 0;//interrupt overflow прерывание только по переполнению разрешено
  TIM1_CR1_UDIS = 0;    // нет ѕрерывание
  TIM1_IER_UIE = 1; //
  TIM1_CCMR3_OC3M = 0x6;//  pwm1
  TIM1_CCMR3_OC3PE = 1; //предзагрузка регистра 
  TIM1_CCMR3_CC3S = 0; // настройка канала на выход
  TIM1_CCER2_CC3P = 0; //OC1 active high
  TIM1_CCER2_CC3E = 1; //включили канал
  //TIM1_CCMR4_OC4M = 0x6;//  pwm1
 // TIM1_CCMR4_OC4PE = 0; //предзагрузка регистра 
 // TIM1_CCMR4_CC4S = 0; // настройка канала на выход
  //TIM1_CCER2_CC4P = 0; //OC1 active high
 // TIM1_CCER2_CC4E = 1; //включили канал
  TIM1_BKR_MOE = 1;// включили канал
   TIM1_PSCRH = 0x0; 
  TIM1_PSCRL = 132;// prescaller 66
  TIM1_ARRH = 0x1;
  TIM1_ARRL = 0x2C; // считаем до 300
  TIM1_CCR3H = 0; TIM1_CCR3L = 100 ; //половина 
  TIM1_EGR_UG = 1;
  TIM1_CR1_CEN = 1;  //start timer запускаем космонавта    */  
//----TIM2----------------------------------------------------------------------  
 /* TIM2_CR1_ARPE = 1;//buffered ARR обновление на следующей итерации
  TIM2_CR1_OPM = 0; //one puls mode off
  TIM2_CR1_URS = 0;//interrupt overflow прерывание только по переполнению разрешено
  TIM2_CR1_UDIS = 0;    // нет ѕрерывание
  TIM2_IER_UIE = 1; // NO INTERRUPT
 // TIM2_CR1_URS = 1; //interrupt only overflow
 // TIM2_CR1_UDIS = 0; //update disable =0
 // TIM2_IER_UIE = 1;//update interrupt enable
  
  TIM2_CCMR3_OC3M = b110;//  pwm1
  TIM2_CCMR3_OC3PE = 1; //предзагрузка регистра 
  TIM2_CCMR3_CC3S = 0; // настройка канала на выход
  TIM2_CCER2_CC3P = 0; //OC1 active high
  TIM2_CCR3H = 0; TIM2_CCR3L = 0;// duty 0%
  TIM2_CCER2_CC3E = 1; //включили канал
  
  TIM2_PSCR = 6; //prescaler ==64  2^6 250khz
  TIM2_ARRH = 0xF4;  TIM2_ARRL = 0x24; //62500 4Hz
  //
  
  TIM2_CR1_CEN = 1;

//----TIM4----------------------------------------------------------------------  
  TIM4_CR1_URS = 1; //interrupt only overflow
  TIM4_CR1_UDIS = 0; //update disable =0
  TIM4_IER_UIE = 1;//update interrupt enable
  TIM4_PSCR = 7; //prescaler ==128  2^7 
  TIM4_ARR = 0x7D; //1000Hz
  
  TIM4_CR1_CEN = 1;
*/
  
//----UART----------------------------------------------------------------------

  
};  