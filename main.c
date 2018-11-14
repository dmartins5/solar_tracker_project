
/* Drew Martins, Justin Bickford, Eric Keffer
 * November 13, 2018
 * ECE-388
 * Lab Project: Solar Tracker
 * Version 0.4
 */

#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/wdt.h>
#include <avr/sleep.h>

#include <util/delay.h>
#define F_CPU 16000000UL

#define RGS13_MAX_T1    300
#define RGS13_MIN_T1    80
#define RGS13_T_MS      30

#define FS5103R_MAX_T0  75
#define FS5103R_MED_T0  46
#define FS5103R_MIN_T0  20
#define FS5103R_T_MS    250

volatile uint8_t counter_timer0 = FS5103R_MIN_T0;
volatile uint8_t flag_timer0 = 0;

volatile uint16_t num[] = {0, 0, 0, 0};
volatile uint8_t idx = 0;
volatile uint16_t cal_y = 0;
volatile uint16_t cal_x = 0;
volatile uint8_t sign = 0;

/* NOTE: THIS FUNCTION IS FOR TESTING PURPOSES, WILL NOT BE USED FOR FINAL PROGRAM */
/*void display_adc_val()
{
        PORTD = num[idx];
        PORTB = num[idx]/256;
        //_delay_ms(1000);
}*/
/* NOTE: This FUNCTION IS FOR TESTING PURPOSES, WILL NOT BE USED FOR FINAL PROGRAM */
/*void display_cal_val(uint16_t cal)
{
        PORTD = cal;
        PORTB = cal/256;
        //_delay_ms(1000);
}*/
/* The WDT Functions are for the Global Timer */
void wdt_init()
{
        if(MCUSR & _BV(WDRF))
        {
                MCUSR &=~ (1 << WDRF);                  // Clear the WDT reset flag
                WDTCSR |= (1 << WDCE) | (1 << WDE);     // Enable the WD Change Bit
                WDTCSR = 0x00;                          // Disable the WDT
        }
}
void wdt_startup()
{
        WDTCSR |= (1 << WDCE) | (1 << WDE);             // Enable the WD Change Bit
        WDTCSR = (1 << WDIE)|(1 << WDP3)|(1 << WDP0); // Enable WDT Interrupt & Set Timeout to 8 Seconds
}
void wdt_sleep_cpu()
{
        if(MCUCR & (1 << SE))
        {
                cli();
                sleep_bod_disable();
                sei();
                sleep_cpu();
        }
}
/* The ADC functions are for the ADC input reading*/
void init_adc_converter()
{
        ADMUX = (1 << REFS0);
        ADCSRA = (1 << ADEN)|(1 << ADPS2)|(1 << ADPS1)|(1 << ADPS0);
}
uint16_t read_adc(uint8_t mux)
{
        mux &= 0x07;
	ADMUX = (ADMUX & 0xF8)|mux;
	ADCSRA |= (1 << ADSC);
	while(ADCSRA & (1 << ADSC));
	return (ADC);
}
/* The RGS13 functions are for operating the RGS13 Motor using Timer1 */
void init_rgs13()
{
        DDRB = (1 << DDB2)|(1 << DDB1);
        TCCR1A = (1 << COM1A1)|(0 << COM1A0)|(1 << COM1B1)|(0 << COM1B0)|(1 << WGM11)|(1 << WGM10);
        TCCR1B = (0 << CS12)|(1 << CS11)|(1 << CS10);
        OCR1A = 1023;
}
void update_rgs13()
{
        OCR1B = ((num[idx])/128) - 11;
        _delay_ms(RGS13_T_MS);
}

void init_fs5103r()
{
        DDRD = (1 << DDD6)|(1 << DDD5);
        TCCR0A = (1 << COM0A1)|(0 << COM0A0)|(1 << COM0B1)|(0 << COM0B0)|(0 << WGM01)|(1 << WGM00);
        TCCR0B = (1 << CS02)|(0 << CS01)|(0 << CS00);
        OCR0A = 255;
}
/* The FS5013R functions are for operating the FS5013R Motor using Timer0 */
void update_fs5103r()
{
        OCR0B = counter_timer0;
        _delay_ms(FS5103R_T_MS);
        if(counter_timer0 >= FS5103R_MED_T0)
                flag_timer0 = 0;
        else if (counter_timer0 < FS5103R_MIN_T0)
                flag_timer0 = 1;
        if(flag_timer0 == 1)
                counter_timer0++;
        else if(flag_timer0 == 0 && counter_timer0 == FS5103R_MED_T0) {
                _delay_ms(5000);
                counter_timer0--;
        } else {
                counter_timer0--;
	}
}
/* Calibration Operation */
void calibrate()
{
	idx = 0;
        init_adc_converter();
        num[idx] = read_adc(idx);
        _delay_ms(25);
        idx += 2;
        init_adc_converter();
        num[idx] = read_adc(idx);
        _delay_ms(25);
        if(num[2] >= num[0])
        {
                cal_y = (num[2]-num[0])/2;      // For Photoresistors 0 and 2
                sign &= ~1;
        } else {
                cal_y = (num[0]-num[2])/2;
                sign |= 1;
        }
        //display_cal_val(cal_y);
        idx--;
        init_adc_converter();
        num[idx] = read_adc(idx);
        _delay_ms(25);
        idx += 2;
        init_adc_converter();
        num[idx] = read_adc(idx);
        _delay_ms(25);
        if(num[3] >= num[1])
        {
                cal_x = (num[3]-num[1])/2;      // For Photoresistors 1 and 3
                sign &= ~2;
        } else {
                cal_x = (num[1]-num[3])/2;
                sign |= 2;
        }
        //display_cal_val(cal_x);
        idx = 0;
}
/* Reset Function */
void reset()
{

}
/* Main Function */
int main(void)
{
	DDRC &=~ (1 << DDC5);
	PORTC = (1 << PORTC5);
	
	wdt_init();
	//init_rgs13_timer1();
	//init_fs5103r_timer0();
	wdt_startup();
	set_sleep_mode(SLEEP_MODE_PWR_DOWN);
	sei();
	while(1)
	{
		wdt_sleep_cpu();
		if(PINC & (1 << PINC5))
        	{
                	calibrate();
        	} // Calibration Button is pressed
	}
}
/* Global Timer Interrupt */
ISR(WDT_vect)
{
	sleep_disable();
	init_adc_converter();
	num[idx] = read_adc(idx);
	//display_adc_val();
	if(idx >= 3)
		idx = 0;
	else
		idx++;
	//update_rgs13_timer1(0);
	//update_med_fs5103r_timer0(0);
	sleep_enable();
}
