#include "led-matrix-connector.h"

#include <wiringPi.h>
#include <wiringPiSPI.h>
#include <stdint.h>
#include <stdlib.h>
#include <signal.h>

LedConfig __config__;
LedRenderLine __renderline__;
void DefaultExitFunction()
{
	LedClear();
}

LedConfig DefaultConfig = {
	0,
	'g',
	1,
	DefaultExitFunction
};

LedRenderLine LedGreenMask = {
	0b00000000,
	0b00000000,
	0b11111111,
	0b11111111
};

void cancelFunction()
{
	LedFinalise();
	
	exit(0);
}

int LedInit(LedConfig Config)
{
	wiringPiSetup();
	wiringPiSPISetup(0,500000);

	LedSetConfig(Config);
	
	signal(SIGINT, cancelFunction);
	
	return 0;
}

int LedSetConfig(LedConfig Config)
{
	__config__.orientation  = Config.orientation;
	__config__.primaryColor = Config.primaryColor;
	__config__.delayTime    = Config.delayTime;
	__config__.exitFunction = Config.exitFunction;
	
	return 0;
}

int LedFinalise()
{
	(*__config__.exitFunction)();
	
	return 0;
}

int LedRenderMonochrome(LedMonochromeMessage lmm, int renderDuration)
{
	int duration = 0;
	switch(__config__.primaryColor)
	{
	case 'g':
		while (duration < renderDuration)
		{
			for (int i = 0; i <= 7; i++)
			{			
				__renderline__.payload[0] = LedGreenMask.payload[0] | ((1 << i) & 0b11110000) | (((~lmm[i]) & 0b11110000) >> 4);
				__renderline__.payload[1] = LedGreenMask.payload[1] | ((1 << i) & 0b00001111) | (((~lmm[i]) & 0b00001111) << 4);
				__renderline__.payload[2] = LedGreenMask.payload[2];
				__renderline__.payload[3] = LedGreenMask.payload[3];
				
				wiringPiSPIDataRW(0, __renderline__.payload, LED_SEND_SIZE);
				delay(__config__.delayTime);
			}
			
			duration++;
		}
		break;
	}
	
	LedClear();
	
	return 0;
}

int LedClear()
{
	static uint8_t canceldata[4] = {
		0xFF,
		0xFF,
		0xFF,
		0xFF
	};
	
	wiringPiSPIDataRW(0, canceldata, LED_SEND_SIZE);
	
	return 0;
}
