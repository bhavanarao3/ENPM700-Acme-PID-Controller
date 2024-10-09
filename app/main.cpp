/**
 * @file main.cpp
 * @brief Demonstrates a basic usage of the PIDController class.
 *
 * This program creates a PIDController object with specific gains,
 * computes a single control output based on a setpoint and actual
 * position, and prints the result.
 */

#include <iostream>

#include "PIDController.hpp"

/**
 * @brief Main function to demonstrate a single-step PID control calculation.
 *
 * This function creates a `PIDController` object, sets a desired setpoint and
 * initial actual position, and calculates the control output using the
 * `compute()` function. The control output is then printed to the console.
 *
 * @return int Exit status of the program (0 for successful execution).
 */
int main() {
  // Define PID gains
  double kp = 1.0;         /**< Proportional gain */
  double ki = 0.5;         /**< Integral gain */
  double kd = 0.1;         /**< Derivative gain */
  double int_limit = 10.0; /**< Maximum integral windup limit */
  double derivative_filter =
      0.8; /**< Smoothing factor for the derivative term */

  // Instantiate the PID controller
  PIDController pid(kp, ki, kd, int_limit, derivative_filter);

  // Set the desired setpoint and current position
  double setpoint = 10.0;       /**< Desired target value */
  double actual_position = 5.0; /**< Current position or measurement */
  double dt = 1.0;              /**< Time step duration (in seconds) */

  // Calculate the PID control output for a single time step
  double control_output = pid.compute(setpoint, actual_position, dt);

  // Print the results
  std::cout << "Setpoint: " << setpoint << "\n";
  std::cout << "Actual Position: " << actual_position << "\n";
  std::cout << "Control Output: " << control_output << "\n";

  return 0;  // Return success
}
