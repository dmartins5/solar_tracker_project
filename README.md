# Solar Tracker Project
This project is for a solar tracker that can adjust a solar panel's position relative to the sun. This works only with very specific hardware.

The hardware that will work with this Solar Tracker includes:

- ATmega328P/PB

? 16x2 LCD Display with an I2C Module.

- RGS13 Rotational Motor

- 4x Photoresistors

UPDATE #2: Source Code Version 0.1.1 is Available:

An update for the source code is added which includes the RGS13 Motor working. Due to the LCD display being the least critical part of the project (can be substituted for an LCD display), development to get the LCD display working will be a lower priority and may or may not be included in the final product.

This currently only works with an 8-Bit Timer and more code must be added for a 16-bit Timer.

NOTE: This only works with the ATmega328P since the ATmega328PB has a higher CPU frequency and has 3x 16-bit timers while the ATmega328P only has one 16-bit timer. The 328P is forwards compatible with the 328PB so using Timer0 and Timer1 should be essentially the same.

The LCD display is the least critical part of the project so the code base for the display is on hold or may be cancelled and removed from the project until we get the more critical parts taken care of. The next step is to program 4 different photoresistors.

UPDATE #1: Source Code Version 0.1 is Available:

Granted this program only covers the LCD display currently and has not been tested yet, we could try to test it sometime soon to see if this works as intended.
