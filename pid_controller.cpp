
#include "pid_controller.h"
#include <vector>
#include <iostream>
#include <math.h>

using namespace std;

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kpi, double Kii, double Kdi, double output_lim_maxi, double output_lim_mini) {

   Kp = Kpi;
   Ki = Kii;
   Kd = Kdi;
   output_lim_max = output_lim_maxi;
   output_lim_min = output_lim_mini;
}


void PID::UpdateError(double cte) {
 
   diff_cte = (cte - prev_cte)/dt;
   prev_cte = cte;
   int_cte += cte*dt;
   
}

double PID::TotalError() {
  
    double control;
    control = (prev_cte * Kp) + (int_cte * Ki) + (diff_cte * Kd);
    if (control > output_lim_max)
    {
      control = output_lim_max;
    }
    else if (control < output_lim_min)
    {
      control = output_lim_min;
    }
    return control;
}

double PID::UpdateDeltaTime(double new_delta_time) {

   dt = new_delta_time;
   return dt;
}