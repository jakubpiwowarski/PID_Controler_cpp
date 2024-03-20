
#ifndef PID_CONTROLLER_H
#define PID_CONTROLLER_H

class PID {
public:

   
    double prev_cte=0;
    double diff_cte=0; 
    double int_cte=0;
    
    double Kp;
    double Ki;
    double Kd;
 
    double output_lim_min;
    double output_lim_max;
   
  
    double dt=0;

   
    PID();


  
    virtual ~PID();


    void Init(double Kp, double Ki, double Kd, double output_lim_max, double output_lim_min);


    void UpdateError(double cte);
    

    double TotalError();
  

    double UpdateDeltaTime(double new_delta_time);
};

#endif //PID_CONTROLLER_H

