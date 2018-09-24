/* Drew Martins, Justin Bickford, Eric Keffer
 * September 21, 2018
 * ECE-388
 * Lab 1: Solar Tracker
 * LCD Display
 */ 

#include <avr/io.h>
#include "i2c_lcd.h"

#define F_CPU 16000000UL
	#include <util/delay.h>

static char str[] = "  Hello World!";
static char str_arr[32];

void extract_char_arr() {
    uint8_t idx;
    for(idx = 0; idx < 32; idx++)
    {
        if(idx >= sizeof(str))
            str_arr[idx] = ' ';
        else
            str_arr[idx] = str[idx];
    }
}

int main(void)
{
	uint8_t idx;
    init_display();
	sei();
    while (1)
    {
        start_display();
		for(idx = 0; idx < 32; idx++)
        {
            
        }
        stop_display();
        TWCR0 = 0;
    }
}
