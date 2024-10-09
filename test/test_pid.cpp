/**
 * @file test_PIDController.cpp
 * @brief Unit tests for the enhanced PIDController class.
 */

#include <gtest/gtest.h>
#include "PIDController.hpp"

// Test for the constructor
TEST(PIDControllerTest, ConstructorInitializesCorrectly) {
  EXPECT_NO_THROW(PIDController(1.0, 0.5, 0.1, 10.0, 0.8));
}

// Test for compute function with zero inputs and a default time step
TEST(PIDControllerTest, ComputeWithZeroInputs) {
  PIDController pid(1.0, 0.5, 0.1, 10.0, 0.8);
  double output = pid.compute(0.0, 0.0, 1.0);  // dt = 1.0s
  EXPECT_NEAR(output, 0.0, 0.001);
}

// Test for compute function with positive error
TEST(PIDControllerTest, ComputeWithPositiveError) {
  PIDController pid(1.0, 0.5, 0.1, 10.0, 0.8);
  double output = pid.compute(10.0, 5.0, 1.0);  // dt = 1.0s
  EXPECT_NEAR(output, 7.9, 0.001);             // P = 5, I = 2.5, D = 0
}

// Test for compute function with negative error
TEST(PIDControllerTest, ComputeWithNegativeError) {
  PIDController pid(1.0, 0.5, 0.1, 10.0, 0.8);
  double output = pid.compute(5.0, 10.0, 1.0);  // dt = 1.0s
  EXPECT_NEAR(output, -7.9, 0.001);            // P = -5, I = -2.5, D = 0
}

// Add other tests similarly...
int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
