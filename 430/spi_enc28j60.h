#ifndef __SPI_ENC28J60_H
#define __SPI_ENC28J60_H
#include "msp430x14x.h"

#define  uchar unsigned char
#define   uint unsigned  int

//P6.5管脚输出高低电平 P65
#define SET_SPI_SI  do{P6OUT |= BIT5;}while(0)     // SPI_MOSI=1
#define CLR_SPI_SI  do{P6OUT &= ~(BIT5);}while(0)  // SPI_MOSI=0
 
#define SPI_SO  (P6IN&BIT4)     // SPI_MISO

//P6.6管脚输出高低电平  P66
#define SET_SPI_SCK  do{P6OUT |= BIT6;}while(0)     // SPI_SCK=1
#define CLR_SPI_SCK  do{P6OUT &= ~(BIT6);}while(0)  // SPI_SCK=0

//P6.7管脚输出高低电平  P67
#define ENC28J60_CSH()	  do{P6OUT |= BIT7;}while(0)     // SPI_CS=1
#define ENC28J60_CSL()	 do{P6OUT &= ~(BIT7);}while(0)  // SPI_CS=0


void SPI_IO_Init(void);
int SpiRead(void);
void SpiWrite(uint data);

#endif /* __SPI_ENC28J60_H */

