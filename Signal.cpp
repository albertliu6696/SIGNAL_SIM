#include "SIMENV.h"

Signal::Signal(){
   prop_speed = 300000000;
};
double Signal::get_Signal(double distance,double time){
   //Default return 1 hertz Signal
   return cos(distance/prop_speed-time);
};
void Signal::set_PropSpeed(double speed){
   prop_speed = speed;
};

