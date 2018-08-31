#include "SIMENV.h"



//{{ Base Signal Class
Signal::Signal(){
   prop_speed = 300000000;
};
double Signal::signal_Function(double distance, double t){
   return cos(distance/prop_speed + t);
}
void Signal::set_PropSpeed(double speed){
   prop_speed = speed;
};
//}}}





