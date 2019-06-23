#ifndef LED_MATRIX_CONNECTOR
#define LED_MATRIX_CONNECTOR


#include <stdint.h>

#define LED_SEND_SIZE 4

typedef void (*ExitFunction)();

typedef struct
{
	int orientation;
	int spiDevice;
	
	char primaryColor;
	
	int delayTime;
	
	ExitFunction exitFunction;
} LedConfig;

typedef uint8_t LedMonochromeMessage[8];
typedef struct
{
	uint8_t payload[4];
} LedRenderLine;

int LedSetConfig(LedConfig Config);
int LedInit(LedConfig Config);
int LedFinalise();

uint8_t ledMirror(uint8_t byte);
int ledMirrorMessage(LedMonochromeMessage output, LedMonochromeMessage msg);
int ledGetASCII(LedMonochromeMessage output, char ascii_char);

int LedRenderMonochrome(LedMonochromeMessage lmm, int renderDuration);
int LedRenderText(const char * text, int renderDuration);
int LedRenderMorse(const char * text, int renderDuration);

int LedClear();


#endif
