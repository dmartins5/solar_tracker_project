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

#define FS5103R_MAX_T0	75
#define FS5103R_MED_T0	46
#define FS5103R_MIN_T0	20
#define FS5103R_T_MS	250

volatile uint8_t counter_timer0 = FS5103R_MIN_T0;
volatile uint8_t flag_timer0 = 0;

void init_fs5103r_timer0()
{
        DDRD = (1 << DDD6)|(1 << DDD5);
        TCCR0A = (1 << COM0A1)|(0 << COM0A0)|(1 << COM0B1)|(0 << COM0B0)|(0 << WGM01)|(1 << WGM00);
        TCCR0B = (1 << CS02)|(0 << CS01)|(0 << CS00);
        OCR0A = 255;
}

void update_med_fs5103r_timer0()
{
        OCR0B = counter_timer0;
        _delay_ms(FS5103R_T_MS);
        if(counter_timer0 >= FS5103R_MED_T0)
                flag_timer0 = 0;
        else if (counter_timer0 < FS5103R_MIN_T0)
                flag_timer0 = 1;
        if(flag_timer0 == 1)
                counter_timer0++;
        else if(flag_timer0 == 0 && counter_timer0 == FS5103R_MED_T0){
                _delay_ms(5000);
		counter_timer0--;
	} else {
		counter_timer0--;
	}
}

void update_max_fs5103r_timer0()
{
        OCR0B = counter_timer0;
        _delay_ms(FS5103R_T_MS);
        if(counter_timer0 > FS5103R_MAX_T0)
                flag_timer0 = 0;
        else if (counter_timer0 < FS5103R_MIN_T0)
                flag_timer0 = 1;
        if(flag_timer0 == 1)
                counter_timer0++;
        else
                counter_timer0--;

}
