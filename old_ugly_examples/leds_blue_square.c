#include <stdio.h>
#include <wiringPi.h>
#include <wiringPiSPI.h>
#include <stdint.h>

int main(void)
{
  static uint8_t data[4] = {0x0,0x0,0x0,0x0};                                  

  printf("%i : %i\n", sizeof(0b00000000), sizeof(uint8_t));
  
  wiringPiSetup();
  wiringPiSPISetup(0,500000);

  data[0] = 0b00111100;
  data[1] = 0b00111100;
  data[2] = 0b00111111;
  data[3] = 0b11110011;
  
  printf("boop bitch\n");
  
  wiringPiSPIDataRW(0,data,sizeof(data));
  return 0;
}
