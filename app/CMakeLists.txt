# Any C++ source files needed to build this target (shell-app).
add_executable(shell-app
  # list of source cpp files:
  main.cpp
  PIDController.cpp
  )

# Any include directories needed to build this target.
# Note: we do not need to specify the include directories for the
# dependent libraries, they are automatically included.
target_include_directories(shell-app PUBLIC
  # list inclue directories:
  ${CMAKE_SOURCE_DIR}/include
)

target_link_libraries(shell-app PUBLIC
  # list of libraries:
  gtest
  )

  
