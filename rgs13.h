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

//#define RGS_MAX_T0	75
//#define RGS_MIN_T0	20
#define RGS_MAX_T1	300
#define RGS_MIN_T1	80
#define T_MS		50

//volatile uint8_t counter_timer0 = RGS_MIN_T0;
//volatile uint8_t flag_timer0 = 0;
volatile uint16_t counter_timer1 = RGS_MIN_T1;
volatile uint8_t flag_timer1 = 0;

/*
void init_rgs13_timer0()
{
	DDRD = (1 << DDD6)|(1 << DDD5);
        TCCR0A = (1 << COM0A1)|(0 << COM0A0)|(1 << COM0B1)|(0 << COM0B0)|(0 << WGM01)|(1 << WGM00);
        TCCR0B = (1 << CS02)|(0 << CS01)|(0 << CS00);
        OCR0A = 255;
}
void update_rgs13_timer0()
{
	OCR0B = counter_timer0;
        _delay_ms(T_MS);
        if(counter_timer0 > RGS_MAX_T0)
                flag_timer0 = 0;
        else if (counter_timer0 < RGS_MIN_T0)
                flag_timer0 = 1;
        if(flag_timer0 == 1)
                counter_timer0++;
        else
        	counter_timer0--;

}
*/

void init_rgs13_timer1() /* TODO: ADD CODE TAHT CREATES 16-BIT FUNCTIONALITY TO THE MOTOR*/
{
	DDRB = (1 << DDB2)|(1 << DDB1);
        TCCR1A = (1 << COM1A1)|(0 << COM1A0)|(1 << COM1B1)|(0 << COM1B0)|(1 << WGM11)|(1 << WGM10);
        TCCR1B = (0 << CS12)|(1 << CS11)|(1 << CS10);
        OCR1A = 1023;
}
void update_rgs13_timer1()
{
	OCR1B = counter_timer1;
        _delay_ms(T_MS);
        if(counter_timer1 > RGS_MAX_T1)
                flag_timer1 = 0;
        else if (counter_timer1 < RGS_MIN_T1)
                flag_timer1 = 1;
        if(flag_timer1 == 1)
                counter_timer1++;
        else
                counter_timer1--;
}
