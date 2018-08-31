#include "SIMENV.h"


Antenna::Antenna(){
   pos.x = 0;
   pos.y = 0;
   mode = 0;
}
Antenna::Antenna(Position pos,Signal sig,int type){
   this->pos = pos;
   mode = type; // 0 RX; 1 RX
   this->TX = sig;
}
void Antenna::RX(Antenna ant,unsigned int time){
   if (!mode){
      double d = pow( pow(ant.pos.x-pos.x,2)+pow(ant.pos.y-pos.y,2) , 2);
      voltage = ant.TX.get_Signal(d,time);
   }
}
