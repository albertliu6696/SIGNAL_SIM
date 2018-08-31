#include "SIMENV.h"


SIMENV::SIMENV(SIMTime time){
   SIMTime t = SIMTime(time.get_Time());
   ant_arrsize = 10;
   ant_ptr = 0;
   antennas = new Antenna[10];
};

void SIMENV::add_Antenna(Antenna a){
   if(ant_ptr==ant_arrsize){
      Antenna *temp_arr = new Antenna[ant_arrsize*2];
      for(int i =0;i<ant_arrsize;i++){
         temp_arr[i] = antennas[i];
      }
      temp_arr[ant_ptr] = a;
      ant_ptr++;

      antennas = temp_arr;
      delete [] temp_arr;
   }
   else{
      antennas[ant_ptr] = a;
      ant_ptr++;
   }
}

void SIMENV::remove_Antenna(Antenna a){
   ant_ptr = ant_ptr?ant_ptr-1:ant_ptr;
}
