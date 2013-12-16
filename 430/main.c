#include "msp430x14x.h"
#include "led.h"
#include "spi_enc28j60.h"
#include "web_server.h"

void Init_CLK(void)
{
   unsigned int iq0;
   BCSCTL1&=~0X00;      //打开XT2振荡器
   do
   {
      IFG1 &= ~OFIFG;   // 清除振荡器失效标志
      for (iq0 = 0xFF; iq0 > 0; iq0--); // 延时，等待XT2起振
    }
    while ((IFG1 & OFIFG) != 0);    // 判断XT2是否起振
    BCSCTL2 =SELM_2+SELS;   //选择MCLK、SMCLK为XT2
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
