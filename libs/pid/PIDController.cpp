/**
 * @file PIDController.cpp
 * @brief Implementation of the PIDController class.
 */

#include "PIDController.hpp"
#include <algorithm>  // For std::min and std::max

/**
 * @brief Constructs a new PIDController object with given gains and parameters.
 *
 * @param kp Proportional gain.
 * @param ki Integral gain.
 * @param kd Derivative gain.
 * @param int_limit Maximum limit for the integral term to prevent windup.
 * @param derivative_filter Smoothing factor for the derivative term (default
 * is 1.0).
 */
PIDController::PIDController(double kp, double ki, double kd, double int_limit,
                             double derivative_filter)
    : kp(kp), ki(ki), kd(kd), integral_sum(0.0), previous_error(0.0),
      integral_limit(int_limit), derivative_filter(derivative_filter),
      previous_derivative(0.0) {}

/**
 * @brief Computes the control output using PID control logic.
 *
 * This method takes in the setpoint, current actual value, and the time step,
 * and calculates the control output using the PID formula:
 *
 * \f[ \text{output} = K_p \cdot e + K_i \cdot \int e \, dt + K_d \cdot
 * \frac{de}{dt} \f]
 *
 * The integral term is limited to prevent windup, and the derivative term is
 * filtered to reduce noise.
 *
 * @param setpoint Desired setpoint value.
 * @param actual_position Current measured value.
 * @param dt Time step duration.
 * @return The computed PID control output.
 */
double PIDController::compute(double setpoint, double actual_position,
                              double dt) {
  // Calculate the error
  double error = setpoint - actual_position;

  // Calculate the proportional term
  double proportional = kp * error;

  // Calculate the integral term with windup prevention
  integral_sum += ki * error * dt;
  integral_sum =
      std::max(-integral_limit,
               std::min(integral_sum, integral_limit));  // Clamp integral
  double integral = integral_sum;

  // Calculate the derivative term with filtering
  double derivative = (error - previous_error) / dt;
  double filtered_derivative = derivative_filter * derivative +
                               (1 - derivative_filter) * previous_derivative;
  double derivative_term = kd * filtered_derivative;

  // Update previous states
  previous_error = error;
  previous_derivative = filtered_derivative;

  // Return the total PID control output
  return proportional + integral + derivative_term;
}
