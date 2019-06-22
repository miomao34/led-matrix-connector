#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "led-matrix-connector/led-matrix-connector.h"
//~ #include "led-matrix-connector/led-matrix-connector-ascii.h"

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
	Config.primaryColor = 'c';
	Config.delayTime = 1;
	Config.exitFunction = myExit;
	LedInit(Config);
	
	LedMonochromeMessage message = {};
	
	while(1)
	{
		LedRenderText("This is an EXAMPLE message 0123456789     ", 300);
	}
	LedFinalise();
}
