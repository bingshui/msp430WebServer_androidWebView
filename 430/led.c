#include "led.h"

void LED_IO_Init(void)
{
  P1SEL =0;
  P1DIR =0xff;
  P1OUT =0xff;
}


