#ifndef JUNCTION_H
#define JUNCTION_H

#include "Arduino.h"
#include "Infrared.h"


class Junction : public Infrared
{
    public:
        Junction(int=2);
        int get_carNum();
        void reset_carNum();
        int get_waitingCounter();
        void set_waitingCounter(int);
        void increment_waitingCounter();

    protected:

    private:
      int car_counter = 0; 
      int waiting_counter = 1;
};

#endif // JUNCTION_H
