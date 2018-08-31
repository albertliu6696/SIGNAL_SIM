#include <iostream>
#include "SIMENV.h"
using namespace std;

Position new_pos(double x,double y){
   Position p;
   p.x = x;
   p.y = y;
   return p;
}
double signal_arr[2][100];

int main(){
   SIMTime t = SIMTime(0.1);
   SIMENV ENV = SIMENV(&t);
   Position p1 = new_pos(0,0);
   Position p2 = new_pos(10,0);
   Signal s = Signal();
   Antenna a1 = Antenna(p1);
   Antenna a2 = Antenna(p2,s);
   ENV.add_Antenna(a1);
   ENV.add_Antenna(a2);
   double *v = new double[2];
   for(int i = 0;i<100;i++){

      v = ENV.get_Voltages();
      signal_arr[0][i] = v[0];
      signal_arr[1][i] = v[1];
      t.next_Time();
   }



   for(int i =0;i<100;i++){
      cout<<signal_arr[0][i]<<"\t"<<signal_arr[1][i]<<endl;
   }
   cout<<"Done\n";
   cout<<ENV.antennas[0].pos.x<<endl;
   double a;
   a1.RX(a2,0.5);
   cout<<a1.voltage<<endl;


   delete [] v;
   return 0;

}
