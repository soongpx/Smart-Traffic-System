#ifndef TRAFFICLIGHT_H
#define TRAFFICLIGHT_H

#include "Register.h"
#include"Junction.h"

class TrafficLight
{
    public:
      TrafficLight(int, int, int, int, int, int, int, int, int, int, int);
      void setup();
      void run();
      void startTimer();
      unsigned long findTimeElapsed();
      void green_todo(int);
      void yellow_todo(int junction_move);

    private:
      unsigned long endTime, startTime; 
      unsigned long timeBlock = 10000;
      unsigned long TimeElapsed; 
      int car_counter; 

      Register r1;
      Register g1;
      Junction jun[4];

      int current, previous, junction_move, prev_junc;  

      int density[4] = {0,0,0,0};
      int red[8] = {1,1,1,1,0,0,0,0};
      int green[4] = {0,0,0,0};
      
      bool has_run;
};

#endif // TRAFFICLIGHT_H
