/* Drew Martins, Justin Bickford, Eric Keffer
 * September 21, 2018
 * ECE-388
 * Lab 1: Solar Tracker
 * RGS13 Motor Demo
 */

#include <avr/io.h>
#include <avr/interrupt.h>

//#define F_CPU 16000000UL
#include <util/delay.h>

#define RGS_MAX_8BIT	75
#define RGS_MIN_8BIT	20
#define T_MS		150

volatile uint8_t counter_8bit = RGS_MIN_8BIT;
volatile uint8_t flag_8bit = 0;

void init_rgs13_timer0()
{
	DDRD = (1 << DDD6)|(1 << DDD5);
        TCCR0A = (1 << COM0A1)|(0 << COM0A0)|(1 << COM0B1)|(0 << COM0B0)|(0 << WGM01)|(1 << WGM00);
        TCCR0B = (1 << CS02)|(0 << CS01)|(0 << CS00);
        OCR0A = 255;
}
void update_rgs13_timer0()
{
	OCR0B = counter_8bit;
        _delay_ms(T_MS);
        if(counter_8bit > RGS_MAX_8BIT)
                flag_8bit = 0;
        else if (counter_8bit < RGS_MIN_8BIT)
                flag_8bit = 1;
        if(flag_8bit == 1)
                counter_8bit++;
        else
        	counter_8bit--;

}

void init_rgs13_timer1() /* TODO: ADD CODE TAHT CREATES 16-BIT FUNCTIONALITY TO THE MOTOR*/
{
	
}
void update_rgs13_timer1()
{
	
}
