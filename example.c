#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "led-matrix-connector.h"

void myExit()
{
	static uint8_t canceldata[4] = {
		0xFF,
		0xFF,
		0xFF,
		0xFF
	};
	printf("hey there buddy wanna end my life?\nbtw size is %i\n", sizeof(canceldata));
	return;
}

int main()
{
	config Configs = {0, myExit};
	LedInit(Configs);
	
	while ( 1 )
	{}
	
	LedFinalise();
}
