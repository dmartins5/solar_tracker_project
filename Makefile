MCU=atmega328p
F_CPU=16000000
CC=avr-gcc
OBJCOPY=avr-objcopy
CFLAGS=-std=c99 -Wall -g -Os -mmcu=${MCU} -DF_CPU=${F_CPU} -I.
TARGET=main
SRCS=main.c rgs13.h

all:
	        ${CC} ${CFLAGS} -o ${TARGET}.bin ${SRCS}
		${OBJCOPY} -j .text -j .data -O ihex ${TARGET}.bin ${TARGET}.hex

flash:
	        avrdude -p ${MCU} -c xplainedmini -U flash:w:${TARGET}.hex:i -F -P usb

clean:
	        rm -f *.bin *.hex *.o

