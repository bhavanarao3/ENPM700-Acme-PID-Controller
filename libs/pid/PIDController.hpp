#ifndef PIDCONTROLLER_HPP
#define PIDCONTROLLER_HPP

/**
 * @file PIDController.hpp
 * @brief Declaration of the PIDController class.
 */

/**
 * @class PIDController
 * @brief A simple Proportional-Integral-Derivative (PID) controller class for
 * control system applications.
 *
 * This class provides a basic implementation of a PID controller, which can be
 * used to compute control outputs given a setpoint and actual process variable.
 * It includes features like integral windup prevention and derivative
 * filtering.
 */
class PIDController {
public:
  /**
   * @brief Constructor for the PIDController class.
   *
   * Initializes the PID controller with the specified gains, integral windup
   * limit, and derivative filter constant.
   *
   * @param kp Proportional gain.
   * @param ki Integral gain.
   * @param kd Derivative gain.
   * @param int_limit Maximum limit for the integral term to prevent windup
   * (default is 10.0).
   * @param derivative_filter Filter constant for derivative smoothing (default
   * is 1.0).
   */
  PIDController(double kp, double ki, double kd, double int_limit = 10.0,
                double derivative_filter = 1.0);

  /**
   * @brief Computes the control output of the PID controller.
   *
   * Given a setpoint and the current process variable, this function computes
   * the PID output. It supports optional time-step (dt) parameter to adjust the
   * derivative and integral terms.
   *
   * @param setpoint Desired target value.
   * @param actual_position Current measured value.
   * @param dt Time step (default is 1.0).
   * @return Control output based on the PID calculation.
   */
  double compute(double setpoint, double actual_position, double dt = 1.0);

private:
  double kp;                ///< Proportional gain
  double ki;                ///< Integral gain
  double kd;                ///< Derivative gain
  double integral_sum;      ///< Sum of the integral term
  double previous_error;    ///< Previous error value for derivative calculation
  double integral_limit;    ///< Maximum limit for integral windup prevention
  double derivative_filter; ///< Derivative filter constant for smoothing
  double previous_derivative; ///< Previous derivative value for filtering
};

#endif // PIDCONTROLLER_HPP
