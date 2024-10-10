# cpp-boilerplate-v2

# C++ Boilerplate v2 Badges
![CICD Workflow status](https://github.com/bhavanarao3/ENPM700-Acme-PID-Controller/actions/workflows/run-unit-test-and-upload-codecov.yml/badge.svg) [![codecov](https://codecov.io/gh/bhavanarao3/ENPM700-Acme-PID-Controller/graph/badge.svg?token=AAc36usRbX)](https://codecov.io/gh/bhavanarao3/ENPM700-Acme-PID-Controller) [![License](https://img.shields.io/badge/license-MIT-blue.svg)](LICENSE)


## Authors

### Part 1
- Bhavana B Rao
- Kshitij Aggarwal

### Part 2
- Piyush Goenka
- Kashif Ansari
## Overview

## Structure
The main.cpp and PIDController.cpp source file are within the app directory.
PIDController.hpp header file is within the include directory.
test_pid.cpp test file is within the test directory.

Simple starter C++ project with:

- CMake
- GoogleTest

## Standard install via command-line
```bash
# Download the code:
  git clone https://github.com/TommyChangUMD/cpp-boilerplate-v2
  cd cpp-boilerplate-v2
# Configure the project and generate a native build system:
  # Must re-run this command whenever any CMakeLists.txt file has been changed.
  cmake -S ./ -B build/
# Compile and build the project:
  # rebuild only files that are modified since the last build
  cmake --build build/
  # or rebuild everything from scracth
  cmake --build build/ --clean-first
  # to see verbose output, do:
  cmake --build build/ --verbose
# Run program:
  ./build/app/shell-app
# Run tests:
  cd build/; ctest; cd -
  # or if you have newer cmake
  ctest --test-dir build/
# Build docs:
  cmake --build build/ --target docs
  # open a web browser to browse the doc
  open docs/html/index.html
# Clean
  cmake --build build/ --target clean
# Clean and start over:
  rm -rf build/
```

ref: https://cmake.org/cmake/help/latest/manual/cmake.1.html

## Building for code coverage (for assignments beginning in Week 4)

```bash
# if you don't have gcovr or lcov installed, do:
  sudo apt-get install gcovr lcov
# Set the build type to Debug and WANT_COVERAGE=ON
  cmake -D WANT_COVERAGE=ON -D CMAKE_BUILD_TYPE=Debug -S ./ -B build/
# Now, do a clean compile, run unit test, and generate the covereage report
  cmake --build build/ --clean-first --target all test_coverage
# open a web browser to browse the test coverage report
  open build/test_coverage/index.html

This generates a index.html page in the build/test_coverage sub-directory that can be viewed locally in a web browser.
```

You can also get code coverage report for the *shell-app* target, instead of unit test. Repeat the previous 2 steps but with the *app_coverage* target:

``` bash
# Now, do another clean compile, run shell-app, and generate its covereage report
  cmake --build build/ --clean-first --target all app_coverage
# open a web browser to browse the test coverage report
  open build/app_coverage/index.html

This generates a index.html page in the build/app_coverage sub-directory that can be viewed locally in a web browser.
```

## Notes

The UML Diagram is inside the html directory i.e. doxygen documentation, as well as in the results directory.
THe cpplint and clang-tidy results are in the results directory.
