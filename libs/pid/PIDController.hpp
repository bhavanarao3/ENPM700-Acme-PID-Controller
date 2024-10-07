/**
 * @file PIDController.hpp
 * @brief Declaration of the PIDController class
 * @details Contains the declarations for a basic PID controller.
 * @author Driver: Bhavana B Rao
 * Navigator: Kshitij Aggarwal
 * @date Oct 3, 2023
 */

#pragma once

class PIDController {
public:
  /**
   * @brief Constructor for PIDController.
   * @param kp Proportional gain
   * @param ki Integral gain
   * @param kd Derivative gain
   */
  PIDController(double kp, double ki, double kd);

  /**
   * @brief Compute the control output based on target setpoint and current velocity.
   * @param setpoint The target setpoint for the velocity.
   * @param actual_velocity The current velocity of the robot.
   * @return The new velocity computed by the PID controller.
   */
  double compute(double setpoint, double actual_velocity);

private:
  double Kp, Ki, Kd; ///< PID gain parameters
};
