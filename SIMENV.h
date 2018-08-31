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
      double get_Signal(double,double);
      void set_PropSpeed(double);
   private:
      double prop_speed;
};
//}}}
//{{{ Antenna Class
class Antenna{
   public:
      Antenna();
      Antenna(Position);
      Antenna(Position,Signal);
      Position pos;
      Signal TX;
      double voltage;
      int mode;
      void RX(Antenna,double);

};
//}}}
//{{{ SIMTime Class
class SIMTime{
   public:
      SIMTime();
      SIMTime(double);
      double get_Time();
      void next_Time();
      void prev_Time();

   private:
      double scaling;
      unsigned int time_sim;
};
//}}}
//{{{ ENV Class
class SIMENV{
   public:
      SIMENV(SIMTime *);
      void add_Antenna(Antenna);
      void remove_Antenna(Antenna);
      double *get_Voltages();
      SIMTime *t;
      Antenna *antennas;
   private:
      unsigned int ant_arrsize;
      int ant_ptr;
};
//}}}





#endif
