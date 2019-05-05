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
    
    int delay_time = 50;

    data[0] = 0b00000000;
    data[1] = 0b00001111;
    data[2] = 0b00001111;
    data[3] = 0b11110000;

    while(1)
    {
        for (int i = 0; i <= 3; i++)
        {
            heart[0] = data[0] | ~(1 << (i));
            heart[1] = data[1] | (~(1 << i) << 4);
            heart[2] = data[2] | (~(1 << i) << 4);
            heart[3] = data[3] | ~(1 << (3 - i));

            wiringPiSPIDataRW(0,heart,sizeof(heart));
            delay(delay_time);
        }
        
        for (int i = 0; i <= 3; i++)
        {
            heart[0] = data[0] | ~(1 << (3 - i));
            heart[1] = data[1] | (~(1 << (3 - i)) << 4);
            heart[2] = data[2] | (~(1 << (3 - i)) << 4);
            heart[3] = data[3] | ~(1 << (i));

            wiringPiSPIDataRW(0,heart,sizeof(heart));
            delay(delay_time);
        }
    }

    return 0;
}
