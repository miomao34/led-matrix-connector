all:
	gcc -o wipe.out old_ugly_examples/leds_wipe.c -lwiringPi
	gcc -o leds.out old_ugly_examples/leds.c -lwiringPi

example:
	gcc -o example.out example.c led-matrix-connector/led-matrix-connector.c -lwiringPi
	
invader:
	gcc -o invader.out old_ugly_examples/leds_invader.c -lwiringPi

runners:
	gcc -o runners.out old_ugly_examples/leds_cyan_runners.c -lwiringPi

heart:
	gcc -o heart.out old_ugly_examples/leds_heart.c -lwiringPi

colors: red green blue cyan magenta

red:
	gcc -o red.out old_ugly_examples/leds_all_red.c -lwiringPi
green:
	gcc -o green.out old_ugly_examples/leds_all_green.c -lwiringPi
blue:
	gcc -o blue.out old_ugly_examples/leds_all_blue.c -lwiringPi
cyan:
	gcc -o cyan.out old_ugly_examples/leds_all_cyan.c -lwiringPi
magenta:
	gcc -o magenta.out old_ugly_examples/leds_all_magenta.c -lwiringPi
#~ yellow:
#~ 	echo -e ${RED}TBD${NC}
white:
	gcc -o white.out old_ugly_examples/leds_all_white.c -lwiringPi
	
amends:
