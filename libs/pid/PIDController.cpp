#include "PIDController.hpp"

// Constructor initializes the PID gains
PIDController::PIDController(double kp, double ki, double kd) : Kp(kp), Ki(ki), Kd(kd), previous_error(0.0), integral(0.0) {}

/**
 * @brief Compute the control output based on target setpoint and current velocity.
 * @param setpoint The target setpoint for the velocity.
 * @param actual_velocity The current velocity of the robot.
 * @return The new velocity computed by the PID controller.
 */
double PIDController::compute(double setpoint, double actual_velocity) {


    return 0.0;
}
