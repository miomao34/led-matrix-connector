#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "led-matrix-connector.h"

void myExit()
{
	LedClear();
	printf("\n");
	return;
}

int main()
{
	LedConfig Config = {};
	Config.orientation = 0;
	Config.primaryColor = 'r';
	Config.delayTime = 1;
	Config.exitFunction = myExit;
	LedInit(Config);
		
	LedMonochromeMessage message[8] = {
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
			0b11000011,
			0b11100111,
			0b11111111,
			0b11011011,
			0b11000011,
			0b11000011,
			0b11000011,
			0b11000011
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
		Config.primaryColor = 'r';
		LedSetConfig(Config);
		for (int i = 0; i < 8; i++)
		{
			LedRenderMonochrome(message[i], 500);
		}
		Config.primaryColor = 'g';
		LedSetConfig(Config);
		for (int i = 0; i < 8; i++)
		{
			LedRenderMonochrome(message[i], 500);
		}
		Config.primaryColor = 'b';
		LedSetConfig(Config);
		for (int i = 0; i < 8; i++)
		{
			LedRenderMonochrome(message[i], 500);
		}
	}
	LedFinalise();
}
