#ifndef PID_H
#define PID_H

class PID {
public:
  /*
  * Errors
  */
  double p_error;
  double i_error;
  double d_error;

  /*
  * Coefficients
  */ 
  double Kp;
  double Ki;
  double Kd;

  /*
   * CTE variables
   */
  double int_cte;
  double prev_cte;
  double curr_cte;
  bool is_cte_initialized;

  /*
   * Twiddle tuning variables
   */
  bool is_tuned;
  int n;
  int state;
  int coeff;
  double best_error;
  double curr_error;
  
  /*
  * Constructor
  */
  PID();

  /*
  * Destructor.
  */
  virtual ~PID();

  /*
  * Initialize PID.
  */
  void Init(double Kp, double Ki, double Kd);
  
  /*
  * Update the PID error variables given cross track error.
  */
  void UpdateError(double cte, uWS::WebSocket<uWS::SERVER> ws);

  /*
  * Calculate the total PID error.
  */
  double TotalError();

  /*
  * Initialize PID cte values
  */
  void InitCTE(double cte);
    
  /*
   * Restart the simulator
   */
  void Restart(uWS::WebSocket<uWS::SERVER> ws);
};

#endif /* PID_H */
