#include <stdio.h>
#include <wiringPi.h>
#include <wiringPiSPI.h>
#include <stdint.h>

int main(void)
{
  static uint8_t data[4] = {0x0,0x0,0x0,0x0};                                  

  wiringPiSetup();
  wiringPiSPISetup(0,500000);

  data[0] = 0b11110000;
  data[1] = 0b00001111; 
  data[2] = 0b00000000;
  data[3] = 0b00000000;
  int delaytime = 2000;
  
  while(1)
  {
    //~ for (int i = 0; i <=3; i++)
    {
      //~ data[0] = 0;
      //~ data[1] = 1 << 2;
      wiringPiSPIDataRW(0,data,sizeof(data)); 
      delay(delaytime);
      
      //~ data[1] = 0;
      //~ data[0] = 1 << (4 + i);
      //~ wiringPiSPIDataRW(0,data,sizeof(data)); 
      //~ delay(delaytime);
    }
  }
    
  return 0;
}
