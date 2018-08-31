#ifndef SIMENV_h
#define SIMENV_h

#include <stdio.h>
#include <iostream>
#include <math.h>

class Signal;
class Antenna;
class SIMTime;
class SIMENV;
struct Position{double x; double y;};

//{{{ Signal Class
class Signal{
   public:
      Signal();
      double get_Signal(double,unsigned int);
      void set_PropSpeed(double);
   private:
      double prop_speed;
};
//}}}
//{{{ Antenna Class
class Antenna{
   public:
      Antenna();
      Antenna(Position,Signal,int);
      Position pos;
      Signal TX;
      double voltage;
      int mode;
      void RX(Antenna,unsigned int);

};
//}}}
//{{{ SIMTime Class
class SIMTime{
   public:
      SIMTime();
      SIMTime(int);
      unsigned int get_Time();
      void next_Time();
      void prev_Time();

   private:
      unsigned int time_sim;
};
//}}}
//{{{ ENV Class
class SIMENV{
   public:
      SIMENV(SIMTime);
      void add_Antenna(Antenna);
      void remove_Antenna(Antenna);
      Antenna *antennas;
      SIMTime t;
   private:
      unsigned int ant_arrsize;
      int ant_ptr;
};
//}}}





#endif
