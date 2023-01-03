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

    protected:
    private:
      int counter = 0;
      int pin;
};

#endif // INFRARED_H
