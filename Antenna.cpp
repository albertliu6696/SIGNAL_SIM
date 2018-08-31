#include "SIMENV.h"

Antenna::Antenna(Position pos,Signal sig,int type){
   this->pos = pos;
   mode = type; // 0 RX; 1 RX
   this->sig = sig;
}
void Antenna::RX(Antenna ant,unsigned int time){
   if (!type){
      double d = pow( pow(ant.pos.x-pos.x,2)+pow(ant.pos.y-pos.y,2) , 2);
      voltage = ant.TX.getSignal(d,time);
   }
}
