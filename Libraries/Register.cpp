#include "Register.h"
#include <Arduino.h>

Register::Register(int Latch, int Data, int Clock):latchPin(Latch), dataPin(Data),clockPin(Clock)
{
    leds = 0;
}

void Register::setup(){
  updateShiftRegister();
  delay(200);
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
}


void Register::updateShiftRegister()
{
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, leds);
  digitalWrite(latchPin, HIGH);
}

void Register::light(int* a){
  off();
  for (int i = 0; i < 8; i++){
    if(a[i] == 1){
      bitSet(leds, i);
    }
  }
  Register::updateShiftRegister();
}

void Register::off(){
  leds = 0;
}

void Register::set(int a, int b, int c){
  latchPin = a;
  dataPin = b;
  clockPin = c;
}
