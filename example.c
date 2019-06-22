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
	LedConfig Config = {
		.orientation = 0,
		.spiDevice = 1,
		.primaryColor = 'c',
		.delayTime = 1,
		.exitFunction = myExit
	};
	LedInit(Config);
	
	LedMonochromeMessage message = {};
	
	while(1)
	{
		LedRenderText("This is an EXAMPLE message 0123456789     ", 300);
	}
	LedFinalise();
}
