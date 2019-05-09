#include <stdint.h>

#define LED_SEND_SIZE 4

typedef void (*ExitFunction)();

typedef struct
{
	int orientation;
	
	char primaryColor;
	
	int delayTime;
	
	ExitFunction exitFunction;
} LedConfig;

typedef uint8_t LedMonochromeMessage[8];
typedef struct
{
	uint8_t payload[4];
} LedRenderLine;

int LedRenderMonochrome(LedMonochromeMessage lmm, int renderDuration);
int LedSetConfig(LedConfig Config);
int LedInit(LedConfig Config);
int LedFinalise();

int LedClear();
