all:
	gcc -o wipe.out leds_wipe.c -lwiringPi
	gcc -o leds.out leds.c -lwiringPi

test:
	gcc -o test.out test.c led-matrix-connector.c -lwiringPi
	
invader:
	gcc -o invader.out leds_invader.c -lwiringPi

runners:
	gcc -o runners.out leds_cyan_runners.c -lwiringPi

heart:
	gcc -o heart.out leds_heart.c -lwiringPi

colors: red green blue cyan magenta

red:
	gcc -o red.out leds_all_red.c -lwiringPi
green:
	gcc -o green.out leds_all_green.c -lwiringPi
blue:
	gcc -o blue.out leds_all_blue.c -lwiringPi
cyan:
	gcc -o cyan.out leds_all_cyan.c -lwiringPi
magenta:
	gcc -o magenta.out leds_all_magenta.c -lwiringPi
#~ yellow:
#~ 	echo -e ${RED}TBD${NC}
white:
	gcc -o white.out leds_all_white.c -lwiringPi
	
amends:
