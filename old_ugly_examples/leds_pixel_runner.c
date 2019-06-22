#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "led-matrix-connector/led-matrix-connector.h"

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
	Config.spiDevice = 1;
	Config.primaryColor = 'g';
	Config.delayTime = 1;
	Config.exitFunction = myExit;
	LedInit(Config);
	
	LedMonochromeMessage message = {};
	int counter = 0;
	while(1)
	{
		ledGetASCII(message, ' ');
		message[counter / 8] = 1 << (counter % 8);
		LedRenderMonochrome(message, 50);
		counter = (counter + 1) % 64;
	}
	LedFinalise();
}
