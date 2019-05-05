#include <stdio.h>
#include <wiringPi.h>
#include <wiringPiSPI.h>
#include <stdint.h>
#include <stdlib.h>
#include <signal.h>

void cancelfunc()
{
    static uint8_t canceldata[4] = {
        0xFF,
        0xFF,
        0xFF,
        0xFF
    };
    wiringPiSPIDataRW(0,canceldata,sizeof(canceldata));
    exit(0);
}

int main(void)
{
    signal(SIGINT, cancelfunc);
    
    static uint8_t data[8][4] = {};
    static uint8_t heart[4] = {};

    printf("%i : %i\n", sizeof(0b00000000), sizeof(uint8_t));

    wiringPiSetup();
    wiringPiSPISetup(0,500000);

    data[0][0] = 0b00001111;
    data[0][1] = 0b11110001;
    data[0][2] = 0b11111001;
    data[0][3] = 0b10011111;

    data[1][0] = 0b00001111;
    data[1][1] = 0b11110010;
    data[1][2] = 0b11110000;
    data[1][3] = 0b00001111;

    data[2][0] = 0b00001111;
    data[2][1] = 0b11110100;
    data[2][2] = 0b11110000;
    data[2][3] = 0b00001111;

    data[3][0] = 0b00001111;
    data[3][1] = 0b11111000;
    data[3][2] = 0b11110000;
    data[3][3] = 0b00001111;

    data[4][0] = 0b00011111;
    data[4][1] = 0b11110000;
    data[4][2] = 0b11111000;
    data[4][3] = 0b10001111;

    data[5][0] = 0b00101111;
    data[5][1] = 0b11110000;
    data[5][2] = 0b11111100;
    data[5][3] = 0b11001111;

    data[6][0] = 0b01001111;
    data[6][1] = 0b11110000;
    data[6][2] = 0b11111110;
    data[6][3] = 0b11101111;

    data[7][0] = 0b10001111;
    data[7][1] = 0b11110000;
    data[7][2] = 0b11111111;
    data[7][3] = 0b11111111;

    while(1)
    {
        for (int i = 0; i <= 7; i++)
        {
            heart[0] = data[i][0];
            heart[1] = data[i][1];
            heart[2] = data[i][2];
            heart[3] = data[i][3];

            wiringPiSPIDataRW(0,heart,sizeof(heart));
            delay(1);
        }
    }

    return 0;
}
