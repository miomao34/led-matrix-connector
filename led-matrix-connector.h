#define LED_SEND_SIZE 4

typedef void (*ExitFunction)();

typedef struct
{
	int orientation;
	
	ExitFunction exitFunction;
} config;

int LedSetConfig(config Config);
int LedInit(config Config);
int LedFinalise();

int LedReset();
