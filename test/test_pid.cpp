/**
 * @file test_PIDController.cpp
 * @brief Unit tests for the PIDController class.
 * @details This file contains test cases to validate the PIDController implementation.
 * @author Your Name
 * @date Oct 3, 2023
 */

#include <gtest/gtest.h>
#include "PIDController.hpp"

// Test for the constructor
TEST(PIDControllerTest, ConstructorInitializesCorrectly) {
    EXPECT_NO_THROW(PIDController(1.0, 0.5, 0.1));
}

// Test for compute function with zero inputs
TEST(PIDControllerTest, ComputeWithZeroInputs) {
    PIDController pid(1.0, 0.5, 0.1);
    double output = pid.compute(0.0, 0.0);
    EXPECT_NEAR(output, 0.0, 0.001);
}

// Test for compute function with positive error
TEST(PIDControllerTest, ComputeWithPositiveError) {
    PIDController pid(1.0, 0.5, 0.1);
    double output = pid.compute(10.0, 5.0);
    EXPECT_NEAR(output, 8.0, 0.001); 
}

// Test for compute function with negative error
TEST(PIDControllerTest, ComputeWithNegativeError) {
    PIDController pid(1.0, 0.5, 0.1);
    double output = pid.compute(5.0, 10.0);
    EXPECT_NEAR(output, -8.0, 0.001); 
}


// Test for compute function after multiple iterations
TEST(PIDControllerTest, ComputeWithMultipleIterations) {
    PIDController pid(1.0, 0.5, 0.1);
    double output1 = pid.compute(20.0, 15.0); // First call
    double output2 = pid.compute(20.0, 17.0); // Second call
    double output3 = pid.compute(20.0, 18.0); // Third call

    EXPECT_NEAR(output1, 8.0, 0.001); 
    EXPECT_NEAR(output2, 6.8, 0.001); 
    EXPECT_NEAR(output3, 6.9, 0.001); 
}

// Extreme setpoint
TEST(PIDControllerTest, ComputeFailsForIncorrectExpectation) {
    PIDController pid(1.0, 0.5, 0.1);
    double output = pid.compute(1000.0, 0.0);
    EXPECT_NEAR(output, 1600, 0.001); 
}



// Main function to run all tests
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
