#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "led-matrix-connector/led-matrix-connector.h"
#include "led-matrix-connector/led-matrix-connector-ascii.h"

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
	Config.primaryColor = 'b';
	Config.delayTime = 1;
	Config.exitFunction = myExit;
	LedInit(Config);
	
	while(1)
	{
		for (int i = 0; i < sizeof(LedASCII)/sizeof(LedASCII[0]); i++)
		{
			LedRenderMonochrome(LedASCII[i], 350);
		}
	}
	LedFinalise();
}
