/* Drew Martins, Justin Bickford, Eric Keffer
 * September 21, 2018
 * ECE-388
 * Lab 1: Solar Tracker
 * LCD Display
 */ 

#ifndef I2C_LCD_H_
#define I2C_LCD_H_

#include <avr/io.h>

#define I2C_BUS_ADDR 0x27

void init_display()
{
	// Set SCL to 100 KHz
    TWSR = 0;
    TWBR = 72;
    
    TWCR0 = (1 << TWEN);
}

void start_display()
{
    TWCR0 = (1 << TWINT) | (1 << TWSTA) | (1 << TWEN); // Start Condition
    while ((TWCR0 & (1 << TWINT)) == 0); // Waiting for the End of Transmission
    if(TWSR & 0xF8 != START)
        ERROR();
}
void stop_display()
{
    TWCR0 = (1 << TWINT)|(1 << TWSTO)|(1 << TWEN);
}

void write_to_display(char data)
{
    TWDR = data;
    TWCR0 = (1 << TWINT)|(1 << TWEN);
    while ((TWCR & (1 << TWINT)) == 0);
}
uint8_t read_ACK_bit()
{
    TWCR0 = (1 << TWINT)|(1 << TWEN)|(1 << TWEA);
    while((TWCR & (1 << TWINT)) == 0);
    return TWDR;
}
uint8_t read_NACK_bit()
{
    TWCR0 = (1 << TWINT)|(1 << TWEN);
    while((TWCR & (1 << TWINT)) == 0);
    return TWDR;
}
uint8_t get_status()
{
    return (TWSR & 0xF8);
}
void display_character(char[] ch_arr)
{
    uint8_t idx;
	for(idx = 0; idx < 32; idx++)
    {
        write_to_display(ch_arr[idx]);
    }
}

#endif /* I2C_LCD_H_ */
