#include <stdio.h>
#include <wiringPi.h>
#include <wiringPiSPI.h>
#include <stdint.h>

#define RED_DATA 0          //define the red data source 
#define BLUE_DATA 1         //define the blue data source
#define GREEN_DATA 2    // define the green data source 

int main(void)
{
  printf("bois");
  static uint8_t data[4] = {0x0,0x0,0x0,0x0};                  // initialize RGB data source 
  static uint8_t i = 0;                                                       

  wiringPiSetup();                                // initialize wiringPi 
  wiringPiSPISetup(0,500000);           // initialize SPI  information, 0 is channel 0, 500000 is clock rate.
  
  int a0 = 0;
  int a1 = 0;
  int a2 = 0;
  int a3 = 0;
  
  while(1){                         
    int j;
    int x = 2;
    static uint8_t heart[8] = {0x00, 0x66, 0xFF, 0xFF, 0xFF, 0x7E, 0x3C, 0x18};             // this is a array of heart
    /*
    00000000
    11001100
    11111111
    11111111
    11111111
    11111110
    00011000
    */
  data[0] = 0xFF;
  data[1] = 0b10000001;
  data[2] = 0xFF;
  data[3] = 0b00011000;
  wiringPiSPIDataRW(0,data,sizeof(data));              // send data to SPI channel 0, and the length of the data
    for ( j=0;j<8;j++)
	{
          data[0] = 0b00000000;
          data[1] = 0b00000000;
          data[2] = 0b00000000;
          data[3] = 0b00000000;
          //wiringPiSPIDataRW(0,data,sizeof(data));              // send data to SPI channel 0, and the length of the data
          delay(2);
	}
	
	a0++;
	if (a0 >= 16)
	{
		printf("a0 ");
		a0 = 0;
		a1++;
	}
	if (a1 >= 16)
	{
		printf("a1 ");
		a1 = 0;
		a2++;
	}
	if (a2 >= 16)
	{
		printf("a2 ");
		a2 = 0;
		a3++;
	}
	if (a3 >= 16)
	{
		printf("a3\n");
		a3 = 0;
	}
  }
}