#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "led-matrix-connector.h"

void myExit()
{
	LedClear();

	printf("\nhey there buddy wanna end my life?\n");
	return;
}

int main()
{
	LedConfig Config = {};
	Config.orientation = 0;
	Config.primaryColor = 'g';
	Config.delayTime = 1;
	Config.exitFunction = myExit;
	LedInit(Config);
	
	
	
	LedMonochromeMessage stairs[8] = {
		{
			0b01111110,
			0b01111110,
			0b01100000,
			0b01111110,
			0b01111110,
			0b01100000,
			0b01111110,
			0b01111110
		},
		{
			0b01100110,
			0b01100110,
			0b00111100,
			0b00011000,
			0b00011000,
			0b00111100,
			0b01100110,
			0b01100110
		},
		{
			0b00111100,
			0b01111110,
			0b01100110,
			0b01100110,
			0b01111110,
			0b01111110,
			0b01100110,
			0b01100110
		},
		{
			0b01000010,
			0b01100110,
			0b01111110,
			0b01011010,
			0b01000010,
			0b01000010,
			0b01000010,
			0b01000010
		},
		{
			0b01111100,
			0b01111110,
			0b01100110,
			0b01111110,
			0b01111100,
			0b01100000,
			0b01100000,
			0b01100000
		},
		{
			0b01100000,
			0b01100000,
			0b01100000,
			0b01100000,
			0b01100000,
			0b01100000,
			0b01111110,
			0b01111110
		},
		{
			0b01111110,
			0b01111110,
			0b01100000,
			0b01111110,
			0b01111110,
			0b01100000,
			0b01111110,
			0b01111110
		},
		{
			0b00000000,
			0b00000000,
			0b00000000,
			0b00000000,
			0b00000000,
			0b00000000,
			0b00000000,
			0b00000000
		},
	};
	
	while(1)
	{
		for (int i = 0; i < 8; i++)
		{
			LedRenderMonochrome(stairs[i], 100);
		}
	}
	LedFinalise();
}
