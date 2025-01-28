#  Happy Birthday on Arduino 🎂

This small project demonstrates how to play the "Happy Birthday" tune using an Arduino and a passive buzzer, and a little fun display of colorful LEDs. It's a fun and simple way to explore Arduino's tone generation capabilities!

##  Components Used
- Arduino board Uno
- Passive buzzer
- smoothing capacitor (optional)
- Jumper wires
- Breadboard
- RGB LEDs (optional)
- 74HC595 shift register (optional)

##  Code Overview
The sketch uses the `tone()` function to generate sounds of specific frequencies that correspond to the musical notes of the "Happy Birthday" song and plays them for a specific period of time.
The sketch also uses shiftDisplay() function to control two RGB LEDs using a shift register, though this part can be omitted if you just want to play the song.


##  How to Use
1. Connect the passive buzzer to a digital pin on the Arduino (e.g., pin 8) and GND.
2. Upload the provided code to your Arduino using the Arduino IDE.
3. Power up your Arduino, and the "Happy Birthday" melody will play!

## 📜 License
Feel free to use and modify the code for personal or educational purposes.

---
🎉 Have fun making birthdays more special with Arduino! 🎂


