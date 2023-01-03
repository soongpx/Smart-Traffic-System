#include "Infrared.h"
#include <Arduino.h>

Infrared::Infrared(int Pin):pin(Pin){counter = 0;}

void Infrared::setup(){
  Serial.begin(9600);
  pinMode(pin, INPUT);
}

bool Infrared::get(){
  if (digitalRead(pin) == 0){
    counter++;
  }  else{
    counter = 0;
  }

  if (counter == 5){
    return 1;
  } else {
    return 0;
  }
}

void Infrared::setPin(int a){
  pin = a;
}
