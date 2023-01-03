#include "TrafficLight.h"
#include <Arduino.h>

      

TrafficLight::TrafficLight(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k)
{
    r1.set(a, b, c);
    g1.set(d, e, f);
  jun[0].setPin(g);
  jun[1].setPin(h);
  jun[2].setPin(i);
  jun[3].setPin(j);
  timeBlock = k;
}

void TrafficLight::setup(){
  Serial.begin(9600);
  r1.setup();
  g1.setup();
  for (int i = 0; i < 4; i++){
    jun[i].setup();
  }
  r1.light(red);
  g1.light(green);
}

void TrafficLight::run(){
  previous = 0;
  if(has_run){
    startTimer();
    has_run = 0;
  }
 
  TimeElapsed = findTimeElapsed();
  jun[0].get_carNum();
  jun[1].get_carNum();
  jun[2].get_carNum();
  jun[3].get_carNum();

  // Serial.println(TimeElapsed);
  if(TimeElapsed>=timeBlock-3000){
    // yellow_todo(junction_move);
    for(int i=0; i<4; i++){
     Serial.println(jun[i].get_carNum());
        density[i] = (jun[i].get_carNum())*(jun[i].get_waitingCounter()); //get density from each junction
        current = density[i]; // find largest junction with largest density
        if(current>previous){
	        previous = current;
          junction_move = i;
       }
      
    }
    if(prev_junc != junction_move){
      yellow_todo(prev_junc);
    }
    green_todo(junction_move);
    prev_junc = junction_move;
    TimeElapsed = 0;
    has_run = 1;
  }
    r1.off();
    r1.light(red);
    g1.light(green);
}

void TrafficLight::startTimer(){
  startTime = millis();
}

unsigned long TrafficLight::findTimeElapsed(){
    endTime = millis();
    TimeElapsed = endTime - startTime;
    return TimeElapsed; 
}

void TrafficLight::green_todo(int junction_move){
  jun[junction_move].reset_carNum();
  jun[junction_move].set_waitingCounter(1);   

  for(int i=0; i<4; i++){
    red[i]=1;
    green[i] =0;
  }
  red[junction_move] = 0;
  green[junction_move] = 1;
  density[junction_move]= 0;

  for(int i=0; i<4; i++){
    if(i!=junction_move){
      if(jun[i].get_carNum()!=0){
        jun[i].increment_waitingCounter();
        // Serial.print("\t");
        // Serial.print(i);
        // Serial.print(": ");
        // Serial.print(j[i].get_carNum());
        }
      }
  }

  // delay(20000);
}

void TrafficLight::yellow_todo(int junction_move){
  for (int i = 0; i < 4; i++){
    green[i] = 0;
  }
  g1.off();
  g1.light(green);
  red[junction_move+4] = 1;
  r1.off();
  r1.light(red);
  delay(1000);
  red[junction_move+4] = 0;
  r1.off();
  r1.light(red);
}
