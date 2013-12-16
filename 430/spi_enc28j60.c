#include "spi_enc28j60.h"


void SpiWrite(uint data)
{
  data=data|0x1100;
  for(uchar i=0;i<8;i++)
  { 
    CLR_SPI_SCK;
      if(data&0x80)
        SET_SPI_SI;
      else
        CLR_SPI_SI;
    data<<=1;
    SET_SPI_SCK;
  }
  CLR_SPI_SCK;
}

int SpiRead(void)
{
  uint idata;
  idata=0;
  for(uchar i=0;i<8;i++)
  { 
    SET_SPI_SCK;
    idata<<=1;
    idata |=SPI_SO>>4;
    CLR_SPI_SCK;
  }
  return idata;
}

void SPI_IO_Init(void)
{
  P6SEL =0;
  P6DIR =0xE0;
  P6OUT =0xff;
}



  
  
