#include "SIMENV.h"

//{{{ Antenna Base Class
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
   this->sig = sig;
}
void Antenna::RX(Antenna ant,double time){
   if (!mode){
      double d = pow( pow(ant.pos.x-pos.x,2)+pow(ant.pos.y-pos.y,2) ,0.5 );
      voltage = ant.TX(d,time);
   }else{
      voltage = 0;
   }
}
double Antenna::TX(double distance, double time){
   //todo change to function of position and time
   return sig.signal_Function(distance,time);
}
//}}}
//{{{ ULA Antenna Class
ULA::ULA(Position pos, double angle, double d,int n){
   mode = 0;
   num_antennas = n;
   antennas = new Antenna[num_antennas];
   double a_r = angle/180*3.141592653;
   Position t1;
   if(!(n%2)){
      for(int i  = 0;i<n;i++){
         t1.x = pos.x+(i-int((n-1)/2))*d*cos(a_r);
         t1.y = pos.y+(i-int((n-1)/2))*d*sin(a_r);
         antennas[i] = Antenna(t1);
      }
   }
   else{
      for(int i =0;i<n;i++){
         t1.x = pos.x+(i-double(n-1)/2)*d*cos(a_r);
         t1.y = pos.y+(i-double(n-1)/2)*d*sin(a_r);
         antennas[i] = Antenna(t1);
      }
   }
}
void ULA::RX(Antenna ant,double time){
   if(!mode){
      voltage  = 0;
      for(int i = 0; i<num_antennas;i++){
         antennas[i].Antenna::RX(ant,time);
         voltage = voltage + antennas[i].voltage;
      }
   }else{
     voltage=  0;
   }
}


double ULA::TX(double distance, double time){
   double d;
   for(int i =0;i<num_elements;i++){
      //todo get change tx to inputs position and time
      d = distance(antenna[i].pos,pos)
      antenna[i].signal_Function(distance,time)
   }
}
//}}}
