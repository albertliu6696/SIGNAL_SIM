#include "SIMENV.h"

SIMTime::SIMTime(){
   time_sim=0;
}
SIMTime::SIMTime(int t_start){
   time_sim = t_start;
};
unsigned int SIMTime::get_Time(){
   return time_sim;
};
void SIMTime::next_Time(){
   time_sim = time_sim+1;
}
void SIMTime::prev_Time(){
   time_sim = time_sim==0?time_sim:time_sim-1;
}
