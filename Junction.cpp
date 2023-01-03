#include "Junction.h"
#include"Infrared.h"

Junction::Junction(int a):Infrared(a)
{
  car_counter = 0;
}

int Junction::get_carNum(){
  if(Infrared::get()){
    car_counter++;
  }

  return car_counter;
}

int Junction::get_waitingCounter(){
  return waiting_counter;
}

void Junction::increment_waitingCounter(){
  waiting_counter++;
}

void Junction::set_waitingCounter(int new_int){
  waiting_counter = new_int;
}

void Junction::reset_carNum(){
  car_counter = 0;
}

