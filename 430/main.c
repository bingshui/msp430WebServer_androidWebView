#include "msp430x14x.h"
#include "led.h"
#include "spi_enc28j60.h"
#include "web_server.h"

void Init_CLK(void)
{
   unsigned int iq0;
   BCSCTL1&=~0X00;      //��XT2����
   do
   {
      IFG1 &= ~OFIFG;   // �������ʧЧ��־
      for (iq0 = 0xFF; iq0 > 0; iq0--); // ��ʱ���ȴ�XT2����
    }
    while ((IFG1 & OFIFG) != 0);    // �ж�XT2�Ƿ�����
    BCSCTL2 =SELM_2+SELS;   //ѡ��MCLK��SMCLKΪXT2
}

void main( void )
{
  // Stop watchdog timer to prevent time out reset
  WDTCTL = WDTPW + WDTHOLD;
  Init_CLK();
  LED_IO_Init();
  SPI_IO_Init();
  Web_Server();
  while(1);
}
