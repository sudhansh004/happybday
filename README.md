
# Happy Birthday on Arduino 🎂


This small project demonstrates how to play the "Happy Birthday" tune using an Arduino and a passive buzzer, and a little fun display of colorful LEDs. It's a fun and simple way to explore Arduino's tone generation capabilities!

## Components Used

- Arduino board Uno
- Passive buzzer
- smoothing capacitor (optional)
- Jumper wires
- Breadboard
- RGB LEDs (optional)
- 74HC595 shift register (optional)

## Code Overview

The sketch uses the `tone()` function to generate sounds of specific frequencies that correspond to the musical notes of the "Happy Birthday" song and plays them for a specific period of time. The sketch uses a user defined library "pitches.h" that contains the names of all musical notes and their corresponding frequencies, **paste the header file in the same folder as your arduino code to import the frequencies into your code**.
The sketch also uses shiftDisplay() function to control two RGB LEDs using a shift register, though this part can be omitted if you just want to play the song.

## Circuit Overview

- The circuit is quite simple the buzzer can be connected to any PWM output pin of the arduino along with ground.
- The shift register is capable of driving 8 outputs at once by taking an 8 bit binary number as an input and shifting the bits with every iteration, the outputs are connected to 2 RGB LEDs thus they glow in different colours with the music (only 4 outputs i used because of lack of wires :) ). The binary number can be changed to create a different pattern.
- Have added a capacitor of 1micro Farads to smooth out the sound of buzzer, you can use even smaller value like 0.1 micro Farads just connect the capacitor parallelly to the buzzer. The output of the PWM pin is a square wave and the capacitor makes the transitions curved avoiding abrupt changes in voltage across the buzzer making it sound smoother.
- Resistors of 220 ohms are used along with the leds to limit current and avoid damage. 
Refer to the circuit diagram for pin connections.



Play around with the code as you want to and have fun!!