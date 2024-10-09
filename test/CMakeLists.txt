# Any C++ source files needed to build this target (pid-test).
add_executable(pid-test
  # list of source cpp files:
  test_pid.cpp
  ../app/PIDController.cpp     # Add the source file for PIDController
  )

# Any include directories needed to build this target.
# Note: we do not need to specify the include directories for the
# dependent libraries, they are automatically included.

target_include_directories(pid-test PUBLIC
  # list of include directories:
  ${CMAKE_SOURCE_DIR}/include
  )

# Any dependent libraires needed to build this target.
target_link_libraries(pid-test PUBLIC
  # list of libraries:
  gtest
  )

# Enable CMake’s test runner to discover the tests included in the
# binary, using the GoogleTest CMake module.
gtest_discover_tests(pid-test)


