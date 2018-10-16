# Solar Tracker Project
This project is for a solar tracker that can adjust a solar panel's position relative to the sun. This works only with very specific hardware.

The hardware that will work with this Solar Tracker includes:

- ATmega328P/PB

? 16x2 LCD Display with an I2C Module.

- RGS13 Rotational Motor

- Continous Server Motor

- 4x Photoresistors

UPDATE #3: Source Code Version 0.1.2 is Available:

An update for the source code is as updated version of the code for the RGS13. The 8-Bit Timer variables were renamed to Timer0 to avoid confusion since Timer0 is a specific 8-Bit Timer.

In addition to that, support for Timer1 on the ATmega328P is supported which is the 16-bit timer. This timer will allow for a higher degree of accuracy than what could be archieved through an 8-bit timer. For now, this piece of the project is done until we add code for the Photoresistors and then we can merge the values we get from the photoresistors and use the data from photoresistors to pin point where the motor should be positioned.

UPDATE #2: Source Code Version 0.1.1 is Available:

An update for the source code is added which includes the RGS13 Motor working. Due to the LCD display being the least critical part of the project (can be substituted for an LCD display), development to get the LCD display working will be a lower priority and may or may not be included in the final product.

This currently only works with an 8-Bit Timer and more code must be added for a 16-bit Timer.

NOTE: This only works with the ATmega328P since the ATmega328PB has a higher CPU frequency and has 3x 16-bit timers while the ATmega328P only has one 16-bit timer. The 328P is forwards compatible with the 328PB so using Timer0 and Timer1 should be essentially the same.

The LCD display is the least critical part of the project so the code base for the display is on hold or may be cancelled and removed from the project until we get the more critical parts taken care of. The next step is to program 4 different photoresistors.

UPDATE #1: Source Code Version 0.1 is Available:

Granted this program only covers the LCD display currently and has not been tested yet, we could try to test it sometime soon to see if this works as intended.
