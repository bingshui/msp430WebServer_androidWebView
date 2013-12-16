#ifndef __LED_H
#define	__LED_H

#include "msp430x14x.h"

#define ON	0
#define OFF	1

#define LED1(a)	 if(a){P1OUT =0xff;}else{P1OUT=0;}	

#define LED2(a)	 if(a){P1OUT&(~BIT5);}else{P1OUT|BIT5;}

#define LED3(a)	 if(a){P1OUT&(~BIT6);}else{P1OUT|BIT6;}

void LED_IO_Init(void);

#endif /* __LED_H */

