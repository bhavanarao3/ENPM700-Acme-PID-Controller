/**
 * @file PIDController.cpp
 * @brief Implementation of the PIDController class
 * @details Contains the implementation for a basic PID controller.
 * @author Driver: Bhavana B Rao
 *         Navigator: Kshitij Aggarwal
 * @date Oct 3, 2023
 */

#include "PIDController.hpp"

// Constructor implementation
PIDController::PIDController(double kp, double ki, double kd) 
    : Kp(kp), Ki(ki), Kd(kd), previous_error(0.0), integral(0.0) {}

// Compute function implementation
double PIDController::compute(double setpoint, double actual_velocity) {

    return 0.0;
}
