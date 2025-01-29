#include "pitches.h"  //header file for note frequencies

// setup pins
int data_pin = 2;
int clock = 3;
int latch = 4;
int SPEAKER_PIN = 5;
int SPEAKER = SPEAKER_PIN;


// defining the order of notes to be played
#define NUM_OF_NOTES 28
int NOTE_SEQ[NUM_OF_NOTES] = {
  NOTE_C5, NOTE_C5, NOTE_D5, NOTE_C5, NOTE_F5, NOTE_E5, PAUSE,
  NOTE_C5, NOTE_C5, NOTE_D5, NOTE_C5, NOTE_G5, NOTE_F5, PAUSE,
  NOTE_C5, NOTE_C5, NOTE_C6, NOTE_A5, NOTE_F5, NOTE_E5, NOTE_D5, PAUSE,
  NOTE_AS5, NOTE_AS5, NOTE_A5, NOTE_F5, NOTE_G5, NOTE_F5
};

// The length of each note and pause durations in milliseconds
int NOTE_LEN[NUM_OF_NOTES] = {
  4, 2, 8, 8, 8, 16, 50,
  4, 2, 8, 8, 8, 16, 100,
  4, 2, 8, 8, 8, 8, 16, 150,
  4, 2, 8, 8, 8, 20
};

// tempo determines the speed of song
int TEMPO = 65;


// Function to generate sound of required frequency
void playNote(int pitch, int duration) {
  tone(SPEAKER, pitch);
  delay(duration);
  noTone(SPEAKER);
}


// Function to generate parallel outputs from the shift register
void shiftDisplay(byte data) {
  digitalWrite(latch, LOW);
  shiftOut(data_pin, clock, LSBFIRST, data);
  digitalWrite(latch, HIGH);
}


void setup() {
  pinMode(data_pin, OUTPUT);
  pinMode(clock, OUTPUT);
  pinMode(latch, OUTPUT);
  byte x = B10000000;

  for (int i = 0; i < NUM_OF_NOTES; i++) {
    shiftDisplay(x);
    
    // Playing the note from the array in order
    if (NOTE_SEQ[i] != PAUSE) {
      playNote(NOTE_SEQ[i], NOTE_LEN[i] * TEMPO);
      delay(TEMPO);
    } else {
      delay(NOTE_LEN[i]);
    }

    // shift the binary number x to right by one bit
    x = x >> 1;

    // resetting x to original value after 5 iterations as i've used only 5 outputs
    if (x == B00001000) {
      x = B10000000;
    }
  }
}

void loop() {
  // kept this empty as i wanted to play it only once
}
