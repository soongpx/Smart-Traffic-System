#ifndef INFRARED_H
#define INFRARED_H

#include<Arduino.h>

class Infrared
{
    public:
      Infrared(int=2);
      void setup();
      bool get();
      void setPin(int);

    private:
      int pin;
      int counter = 0;
};

#endif // INFRARED_H
