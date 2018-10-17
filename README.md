# Solar Tracker Project
This project is for a solar tracker that can adjust a solar panel's position relative to the sun. This works only with very specific hardware.

The hardware that will work with this Solar Tracker includes:

- ATmega328P/PB

? 16x2 LCD Display with an I2C Module.

- RGS13 Rotational Motor

- FS5103R Servor Motor

- 4x Photoresistors

<b>UPDATE #4:</b> Source Code Version 0.2 is Available:

Another update for the source code is available, this is for adding support to the FS5103R Servor Motor.

This motor operates with the same principle that it's powered by a PWM pulse, except that this motor has continous motion instead of taking a certain position depending on a pulse width. So there is a MIN, MAX and now a MED value for the RS5103R since at MED, the rotation stops. THe MIN and MAX values determine the direction of rotation where MIN is clockwise and MAX is counterclockwise. Timer0 is used for this motor since accuracy isn't a huge factor in this part like it was for the RGS13.

This piece of the project will be continued alongside with the RGS13 when we use the motors to interact with the data from the photoresistors which is the next part of the project.

<b>UPDATE #3:</b> Source Code Version 0.1.2 is Available:

An update for the source code is as updated version of the code for the RGS13. The 8-Bit Timer variables were renamed to Timer0 to avoid confusion since Timer0 is a specific 8-Bit Timer.

In addition to that, support for Timer1 on the ATmega328P is supported which is the 16-bit timer. This timer will allow for a higher degree of accuracy than what could be archieved through an 8-bit timer. For now, this piece of the project is done until we add code for the Photoresistors and then we can merge the values we get from the photoresistors and use the data from photoresistors to pin point where the motor should be positioned.

<b>UPDATE #2:</b> Source Code Version 0.1.1 is Available:

An update for the source code is added which includes the RGS13 Motor working. Due to the LCD display being the least critical part of the project (can be substituted for an LCD display), development to get the LCD display working will be a lower priority and may or may not be included in the final product.

This currently only works with an 8-Bit Timer and more code must be added for a 16-bit Timer.

<b>NOTE:</b> This only works with the ATmega328P since the ATmega328PB has a higher CPU frequency and has 3x 16-bit timers while the ATmega328P only has one 16-bit timer. The 328P is forwards compatible with the 328PB so using Timer0 and Timer1 should be essentially the same.

The LCD display is the least critical part of the project so the code base for the display is on hold or may be cancelled and removed from the project until we get the more critical parts taken care of. The next step is to program 4 different photoresistors.

<b>UPDATE #1:</b> Source Code Version 0.1 is Available:

Granted this program only covers the LCD display currently and has not been tested yet, we could try to test it sometime soon to see if this works as intended.
