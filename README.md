# Solar Tracker Project
This project is for a solar tracker that can adjust a solar panel's position relative to the sun. This works only with very specific hardware.

The hardware that will work with this Solar Tracker includes:

- ATmega328P/PB

- RGS13 Rotational Motor

- FS5103R Servor Motor

- 4x Photoresistors

- 2x Push Buttons (1 for Calibration and 1 for Reset)

<b>UPDATE #7:</b> Source Code Version 0.5 is Available

The changes in this code are minor from Version 0.4, the changes made includes integrating the functionality of the rgs13 and fs5103r motors. This will most likely be the final version of the code prior to Version 1.0.

<b>UPDATE #6:</b> Source Code Version 0.4 is Available

The changes in this version mainly includes additional variables such as calibration variables and a sign variable to determine direction. In addition the calibration button for PORTC5 has been implemented to perform the calibration:

The calibration operates with two different magnitude values (cal_y for ADC0 and ADC2 and cal_x for ADC3 and ADC1), one for each motor. Unlike the actual number values from the num array of ADC values, the calibration values are signed 16-bit integers, and if it goes negative, the sign value that indicates direction will change and cal_y or cal_x get's set to a positive number by 2's Compliment.

RGS13 will use cal_y and FS5103R will use cal_x and an 8 bit direction value called sign which will tell which ADC value is greater and has 4 possible values from 0 to 3. Both motors share the sign value.

<table>
  <tr>
    <th>cal_y</th>
    <th>cal_x</th>
    <th>sign</th>
  </tr>
  <tr>
    <td>+/0</td>
    <td>+/0</td>
    <td>0</td>
  </tr>
  <tr>
    <td>-</td>
    <td>+/0</td>
    <td>1</td>
  </tr>
  <tr>
    <td>+/0</td>
    <td>-</td>
    <td>2</td>
  </tr>
  <tr>
    <td>-</td>
    <td>-</td>
    <td>3</td>
  </tr>
</table>

Where +/0 is a non-negative value (0 or greater) and - is a negative number.

Seems like the program is getting close to complete and is a matter of now using the calibration values to have the motor move to the desired direction (directly facing the sun).

<b>UPDATE #5:</b> Source Code Version 0.3 is Available, Major Changes since last version:

A lot of changes have occurred since the last version.

Mainly that all the code is being merged into a single file which is more managable when it comes to dealing with global variables and interrupts. So the code base no longer has header files and all of the functions are stored in one place.

A major change in the program's function is that the ADC values from each pin can finally be read and is stored into an array. Additional code must be implemented to perform an output comparison. Then the comparison determines how the motors will position the solar panel.

The additional part of this update is that the circuit will implement a calibration button and a reset button which is a WIP.

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
