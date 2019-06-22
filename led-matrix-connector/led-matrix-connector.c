#include "led-matrix-connector.h"
#include "led-matrix-connector-ascii.h"

#include <wiringPi.h>
#include <wiringPiSPI.h>
#include <stdio.h>
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
	0,
	'g',
	1,
	DefaultExitFunction
};
struct {
	LedRenderLine Red;
	LedRenderLine Green;
	LedRenderLine Blue;
	LedRenderLine Cyan;
	LedRenderLine Magenta;
	LedRenderLine Yellow;
} LedMasks =
{
	{
		0b00001111,
		0b11110000,
		0b11110000,
		0b00001111
	},
	{
		0b00000000,
		0b00000000,
		0b11111111,
		0b11111111
	},
	{
		0b00001111,
		0b11110000,
		0b00001111,
		0b11110000
	},
	{
		0b00000000,
		0b00000000,
		0b00001111,
		0b11110000
	},
	{
		0b00001111,
		0b11110000,
		0b00000000,
		0b00000000
	},
	{
		0b00000000,
		0b00000000,
		0b11110000,
		0b00001111
	},
};

void cancelFunction()
{
	LedFinalise();
	
	exit(0);
}

int LedInit(LedConfig Config)
{
	wiringPiSetup();
	wiringPiSPISetup(Config.spiDevice, 500000);

	LedSetConfig(Config);
	
	signal(SIGINT, cancelFunction);
	
	return 0;
}

int LedSetConfig(LedConfig Config)
{
	__config__.orientation  = Config.orientation;
	__config__.spiDevice    = Config.spiDevice;
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

uint8_t ledMirror(uint8_t byte)
{
	return ( \
		((byte & 1  ) << 7) | \
		((byte & 2  ) << 5) | \
		((byte & 4  ) << 3) | \
		((byte & 8  ) << 1) | \
		((byte & 16 ) >> 1) | \
		((byte & 32 ) >> 3) | \
		((byte & 64 ) >> 5) | \
		((byte & 128) >> 7)   \
	);
}

int ledMirrorMessage(LedMonochromeMessage output, LedMonochromeMessage msg)
{
	for (int i = 0; i < 8; i++)
		output[i] = ledMirror(msg[i]);
		
	return 0;
}

int ledGetASCII(LedMonochromeMessage output, char ascii_char)
{
	if (ascii_char < ' ')
	{
		fprintf(stderr, "led-matrix-connector.c: ledGetASCII: character out of bounds - \\%i is lesser than \' \'", ascii_char);
		//~ cancelFunction();
		return 1;
	}
	
	if (ascii_char > '~')
	{
		fprintf(stderr, "led-matrix-connector.c: ledGetASCII: character out of bounds - \\%i is greater than \'~\'", ascii_char);
		//~ cancelFunction();
		return 1;
	}
	
	
	for(int i = 0; i < 8; i++)
		output[i] = LedASCII[ascii_char - ' '][i];
	
	return 0;
}


int LedRenderMonochrome(LedMonochromeMessage lmm, int renderDuration)
{
	int duration = 0;
	LedMonochromeMessage lmmMirrored = {};
	ledMirrorMessage(lmmMirrored, lmm);
	
	switch(__config__.primaryColor)
	{
	case 'r':
		while (duration < renderDuration)
		{
			for (int i = 0; i <= 7; i++)
			{
				__renderline__.payload[0] = LedMasks.Red.payload[0] | ((1 << i) & 0b11110000);
				__renderline__.payload[1] = LedMasks.Red.payload[1] | ((1 << i) & 0b00001111);
				__renderline__.payload[2] = LedMasks.Red.payload[2] | (((~lmm[i])         & 0b11110000) >> 4);
				__renderline__.payload[3] = LedMasks.Red.payload[3] | (((~lmmMirrored[i]) & 0b11110000));
				
				wiringPiSPIDataRW(__config__.spiDevice, __renderline__.payload, LED_SEND_SIZE);
				delay(__config__.delayTime);
			}
			
			duration += __config__.delayTime * 8;
		}
		break;
	
	case 'g':
		while (duration < renderDuration)
		{
			for (int i = 0; i <= 7; i++)
			{
				__renderline__.payload[0] = LedMasks.Green.payload[0] | ((1 << i) & 0b11110000) | (((~lmm[i]) & 0b11110000) >> 4);
				__renderline__.payload[1] = LedMasks.Green.payload[1] | ((1 << i) & 0b00001111) | (((~lmm[i]) & 0b00001111) << 4);
				__renderline__.payload[2] = LedMasks.Green.payload[2];
				__renderline__.payload[3] = LedMasks.Green.payload[3];
				
				wiringPiSPIDataRW(__config__.spiDevice, __renderline__.payload, LED_SEND_SIZE);
				delay(__config__.delayTime);
			}
			
			duration += __config__.delayTime * 8;
		}
		break;
		
	case 'b':
		while (duration < renderDuration)
		{
			for (int i = 0; i <= 7; i++)
			{
				__renderline__.payload[0] = LedMasks.Blue.payload[0] | ((1 << i) & 0b11110000);
				__renderline__.payload[1] = LedMasks.Blue.payload[1] | ((1 << i) & 0b00001111);
				__renderline__.payload[2] = LedMasks.Blue.payload[2] | (((~lmm[i])         & 0b00001111) << 4);
				__renderline__.payload[3] = LedMasks.Blue.payload[3] | (((~lmmMirrored[i]) & 0b00001111));
				
				wiringPiSPIDataRW(__config__.spiDevice, __renderline__.payload, LED_SEND_SIZE);
				delay(__config__.delayTime);
			}
			
			duration += __config__.delayTime * 8;
		}
		break;
		
	case 'c':
		while (duration < renderDuration)
		{
			for (int i = 0; i <= 7; i++)
			{
				__renderline__.payload[0] = LedMasks.Cyan.payload[0] | ((1 << i) & 0b11110000) | ((1 << i) & 0b11110000) | (((~lmm[i]) & 0b11110000) >> 4);
				__renderline__.payload[1] = LedMasks.Cyan.payload[1] | ((1 << i) & 0b00001111) | ((1 << i) & 0b00001111) | (((~lmm[i]) & 0b00001111) << 4);
				__renderline__.payload[2] = LedMasks.Cyan.payload[2] | (((~lmm[i])         & 0b00001111) << 4);
				__renderline__.payload[3] = LedMasks.Cyan.payload[3] | (((~lmmMirrored[i]) & 0b00001111));
				
				wiringPiSPIDataRW(__config__.spiDevice, __renderline__.payload, LED_SEND_SIZE);
				delay(__config__.delayTime);
			}
			
			duration += __config__.delayTime * 8;
		}
		break;
		
	case 'm':
		while (duration < renderDuration)
		{
			for (int i = 0; i <= 7; i++)
			{
				__renderline__.payload[0] = LedMasks.Magenta.payload[0] | ((1 << i) & 0b11110000);
				__renderline__.payload[1] = LedMasks.Magenta.payload[1] | ((1 << i) & 0b00001111);
				__renderline__.payload[2] = LedMasks.Magenta.payload[2] | (((~lmm[i])         & 0b11110000) >> 4) | (((~lmm[i])         & 0b00001111) << 4);
				__renderline__.payload[3] = LedMasks.Magenta.payload[3] | (((~lmmMirrored[i]) & 0b11110000))      | (((~lmmMirrored[i]) & 0b00001111));
				
				wiringPiSPIDataRW(__config__.spiDevice, __renderline__.payload, LED_SEND_SIZE);
				delay(__config__.delayTime);
			}
			
			duration += __config__.delayTime * 8;
		}
		break;
	}
	
	LedClear();
	
	return 0;
}

int LedRenderText(const char * text, int letterRenderDuration)
{
	LedMonochromeMessage letter = {};
	int i = 0;
	while(*(text + i) >= ' ' && *(text + i) <= '~')
	{
		ledGetASCII(letter, *(text + i));
		LedRenderMonochrome(letter, letterRenderDuration);
		LedClear();
		
		i++;
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
	
	wiringPiSPIDataRW(__config__.spiDevice, canceldata, LED_SEND_SIZE);
	
	return 0;
}
