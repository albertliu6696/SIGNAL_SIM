#include "SIMENV.h"


Antenna::Antenna(){
   pos.x = 0;
   pos.y = 0;
   mode = 0;
}
Antenna::Antenna(Position pos){
   this->pos = pos;
   mode = 0;
}
Antenna::Antenna(Position pos,Signal sig){
   this->pos = pos;
   mode = 1; // 0 RX; 1 TX
   this->TX = sig;
}
void Antenna::RX(Antenna ant,double time){
   if (!mode){
      double d = pow( pow(ant.pos.x-pos.x,2)+pow(ant.pos.y-pos.y,2) ,0.5 );
      voltage = ant.TX.get_Signal(d,time);
   }else{
      voltage = 0;
   }
}
