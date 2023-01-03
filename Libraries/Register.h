#ifndef REGISTER_H
#define REGISTER_H

#include "Arduino.h"

class Register
{
    public:
        Register(int=2, int=3, int=4);
        void setup();
        void updateShiftRegister();
        void light(int*);
        void off();
        void set(int, int, int);

    protected:

    private:
        uint8_t leds;
        int latchPin;
        int clockPin;
        int dataPin;
};

#endif // REGISTER_H
