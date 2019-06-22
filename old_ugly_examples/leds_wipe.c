#include <wiringPi.h>
#include <wiringPiSPI.h>
#include <stdint.h>

int main(void)
{
  static uint8_t data[4] = {0x0,0x0,0x0,0x0};                                                     
  
  wiringPiSetup();
  wiringPiSPISetup(1,500000);

  data[0] = 0xFF;
  data[1] = 0xFF;
  data[2] = 0xFF;
  data[3] = 0xFF ;
  
  wiringPiSPIDataRW(1,data,sizeof(data));
}
