#include "led-matrix-connector.h"

#include <wiringPi.h>
#include <wiringPiSPI.h>
#include <stdint.h>
#include <stdlib.h>
#include <signal.h>

config __config__;

void cancelFunction()
{
	LedFinalise();
	
	exit(0);
}

int LedInit(config Config)
{
	LedSetConfig(Config);
	
	signal(SIGINT, cancelFunction);
	
	return 0;
}

int LedSetConfig(config Config)
{
	__config__.orientation  = Config.orientation;
	__config__.exitFunction = Config.exitFunction;
	
	return 0;
}

int LedFinalise()
{
	(*__config__.exitFunction)();
	
	return 0;
}

int LedReset()
{
	static uint8_t canceldata[4] = {
		0xFF,
		0xFF,
		0xFF,
		0xFF
	};
	
	wiringPiSPIDataRW(0, canceldata, sizeof(canceldata));
	
	return 0;
}
