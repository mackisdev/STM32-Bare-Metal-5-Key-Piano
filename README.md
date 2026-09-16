# STM32 5-Key Piano

This project contains buttons on a breadboard, and once you press those buttons, it produces a sound through a passive buzzer.
These sounds vary in frequency from 262-440Hz, each representing a different key in music. 

https://github.com/user-attachments/assets/a0537f3b-2c9d-437d-a41c-fc66b669f177

## Description

  The STM32 5-Key Piano is a user-controlled sound emitter that contains five buttons for five different sounds.
To create this project, I first initialized a timer, TIM2. To do this, I first enabled and configured HSI as the system clock for the STM32.
This initialized the system clock at 16MHz, and I set the AHB and APB prescalers to 1, so the actual TIM2 can be 16mHz at default.
Afterward, I prescaled TIM2 to 100,000Hz. I did this because it'll allow me to work with a smaller value for the timer arithmetic later.
Then, I set the ARR to 99,999 so the timer overflows at 1 second.
  Then, I created a function "TIM2_CHANGE_FREQUENCY(unsigned int frequency)" to take in a specified frequency for a select button.
In this, I made the choice that I wanted to emulate a cycle at the frequency I chose to match, so I took into account the two state changes
of a cycle: ON-OFF and OFF-ON. To do this, I multiplied the given frequency by two to obtain the number of times I needed there to be a state change 
per second. Then, I divided the frequency of the timer by the number of times I need to change states. The values of this minus 1 provide me
the new Auto Reload Register value that the timer will be overflowing at. 
  In main, I initialized all the buttons I connected to GPIO pins as inputs, and initialized the one connected to the passive button as an output.
Within the loop, the logic was that if a button was pressed, I'd call the (TIM2_CHANGE_FREQUENCY) function with a set frequency that coincides with
a note on the piano, and then I'd wait if the timer didn't overflow, but once it did, I'd toggle the buzzer pin, then set the timer's update flag (UIF)
to 0 instantly. Then, it'd be the same logic vice versa for the opposite state change.

### Tools

* STM32 Nucleo-F767ZI RM0410 Reference Manual
* STM32 Nucleo-F767ZI UM1974 User Manual
* PlatformIO
* Breadboard
* Buttons
* Passive Buzzer
* Jumper wires

## Authors

ex. Mackenzy Daniel

## Version History

* 0.1
    * Initial Release
