#include "SIMENV.h"


SIMENV::SIMENV(SIMTime *time){
   t = time;
   ant_arrsize = 10;
   ant_ptr = 0;
   antennas = new Antenna[10];
};

SIMENV::~SIMENV(){
   std::cout<<"Destructor Called"<<std::endl;
   delete [] antennas;
}

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

double *SIMENV::get_Voltages(){
   double temp = 0;
   double *arr =  new double[ant_ptr];
   for (int i  = 0;i<ant_ptr;i++){
      arr[i] = 0;
   }
   for(int i = 0;i<ant_ptr;i++){
      temp = 0;
      for(int j=0;j<ant_ptr;j++){
         if(j!=i){
            antennas[i].RX(antennas[j],t->get_Time());
            temp = temp+antennas[i].voltage;
         }
      }
      arr[i] = temp;
   }
   return arr;
}
