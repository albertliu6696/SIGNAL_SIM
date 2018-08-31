#include "SIMENV.h"

SIMTime::SIMTime(){
   time_sim=0;
   scaling = 0;
}
SIMTime::SIMTime(double t_scale){
   time_sim = 0;
   scaling = t_scale;
};
double SIMTime::get_Time(){
   return time_sim*scaling;
};
void SIMTime::next_Time(){
   time_sim = time_sim+1;
}
void SIMTime::prev_Time(){
   time_sim = time_sim==0?time_sim:time_sim-1;
}
