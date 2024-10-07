#include "PIDController.hpp"

PIDController::PIDController(double kp, double ki, double kd) : Kp(kp), Ki(ki), Kd(kd) {}

/**
 * @brief Stub implementation of compute method.
 * @param setpoint The desired velocity
 * @param actual_velocity The current velocity
 * @return Placeholder value
 */
 
double PIDController::compute(double setpoint, double actual_velocity) {
  // Placeholder return value, to be implemented by the other pair
  return 0.0;
}
