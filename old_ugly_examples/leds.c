#include <stdio.h>
#include <wiringPi.h>
#include <wiringPiSPI.h>
#include <stdint.h>
#include <stdlib.h>
#include <signal.h>

/* CONN LOST:
 * 
 * XX X_ XX XX
 * __ _X _X _X
 * __ X_ X_ X_
 * X_ X_ _X _X
 * X_ _X X_ XX
 * X_ X_ X_ X_ 
 * 
 * */

void cancelfunc()
{
	static uint8_t canceldata[4] = {
		0xFF,
		0xFF,
		0xFF,
		0xFF
	};
	wiringPiSPIDataRW(0, canceldata, sizeof(canceldata));
	
	exit(0);
}

int main(void)
{
	signal(SIGINT, cancelfunc);
	
	static uint8_t data[4] = {};
	static uint8_t heart[4] = {};

	//~ printf("%i : %i\n", sizeof(0b00000000), sizeof(uint8_t));

	wiringPiSetup();
	wiringPiSPISetup(0,500000);
	
	int delay_time = 1;

	data[0] = 0b00000000;
	data[1] = 0b00000000;
	data[2] = 0b00000000;
	data[3] = 0b00000000;
		
        
        
        
        
        
    while (1)
    {
        
    }
    
	//~ while (1)
	//~ {
		//~ for (int i = 0; i < 64; i++)
		//~ {
			
			//~ data[0] = (1 << (i % 8)) & 0b11110000;
			//~ data[1] = (1 << (i % 8)) & 0b1111;
			//~ data[2] = 0b00000000;
			//~ data[3] = 0b00000000;
			
			//~ wiringPiSPIDataRW(0, data, sizeof(data));
			//~ delay(delay_time);
		//~ }
	//~ }
	
	return 0;
}
