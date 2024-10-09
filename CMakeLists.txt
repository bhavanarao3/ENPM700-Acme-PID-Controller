cmake_minimum_required(VERSION 3.14)
project(scratch)

# GoogleTest Setup
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include the directories
include_directories(${CMAKE_SOURCE_DIR}/include)  # Add this line to include your headers

# declares a dependency on GoogleTest which is downloaded from GitHub
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Enables testing for this directory and below
enable_testing()
include(GoogleTest)

# Doxygen Support check if Doxygen is installed
find_package(Doxygen)
if ( DOXYGEN_FOUND )
  set( DOXYGEN_OUTPUT_DIRECTORY     ${PROJECT_SOURCE_DIR}/docs )
  set( DOXYGEN_COLLABORATION_GRAPH  YES )
  set( DOXYGEN_EXTRACT_ALL          YES )
  set( DOXYGEN_CLASS_DIAGRAMS       YES )
  set( DOXYGEN_HIDE_UNDOC_RELATIONS NO )
  set( DOXYGEN_HAVE_DOT             YES )
  set( DOXYGEN_CLASS_GRAPH          YES )
  set( DOXYGEN_CALL_GRAPH           YES )
  set( DOXYGEN_CALLER_GRAPH         YES )
  set( DOXYGEN_COLLABORATION_GRAPH  YES )
  set( DOXYGEN_BUILTIN_STL_SUPPORT  YES )
  set( DOXYGEN_EXTRACT_PRIVATE      YES )
  set( DOXYGEN_EXTRACT_PACKAGE      YES )
  set( DOXYGEN_EXTRACT_STATIC       YES )
  set( DOXYGEN_EXTRACT_LOCALMETHODS YES )
  set( DOXYGEN_UML_LOOK             YES )
  set( DOXYGEN_UML_LIMIT_NUM_FIELDS 50 )
  set( DOXYGEN_TEMPLATE_RELATIONS   YES )
  set( DOXYGEN_DOT_GRAPH_MAX_NODES  100 )
  set( DOXYGEN_MAX_DOT_GRAPH_DEPTH  0 )
  set( DOXYGEN_DOT_TRANSPARENT      YES )
else()
  message( FATAL_ERROR "Doxygen needs to be installed to generate the doxygen documentation" )
endif()

# Create the compilation database for clangd and move it out of the build dir.
set(CMAKE_EXPORT_COMPILE_COMMANDS ON) # Enable compile_commands.json
execute_process(COMMAND cmake -E create_symlink
                "${PROJECT_BINARY_DIR}/compile_commands.json"
                "${PROJECT_SOURCE_DIR}/compile_commands.json")

# Set up code coverage generation.
option(WANT_COVERAGE "this option enable coverage" ON)
if(NOT CMAKE_BUILD_TYPE MATCHES "Debug")
  set(WANT_COVERAGE OFF)
endif()

if(WANT_COVERAGE)
  message("Enabling coverage")
  list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake-modules")
  include(CodeCoverage)
  append_coverage_compiler_flags() # will add "--coverage" compilation flag
  set(TEST_COVERAGE_DIR ${PROJECT_BINARY_DIR}/test_coverage)
  file(MAKE_DIRECTORY ${TEST_COVERAGE_DIR})
  set(COVERAGE_EXCLUDES
    ${PROJECT_BINARY_DIR}
    )
endif()

# Boilerplate for Subdirectories
add_subdirectory(app)
add_subdirectory(test)

# create a target to build documentation
doxygen_add_docs(docs           # target name
  ${PROJECT_SOURCE_DIR}/app
  ${PROJECT_SOURCE_DIR}/include
)

# create targets for building code coverage reports
if(WANT_COVERAGE)
  setup_target_for_coverage_lcov ( # use lcov to generate coverage report
    NAME test_coverage          # target name
    EXECUTABLE ctest     # what to run inside the build directory?
    EXCLUDE
      "app/main.cpp"     # Exclude app main from coverage analysis
      "*gtest*"          # Don't analyze GoogleTest code
      "/usr/include/*"   # Don't analyze system headers
  )

  setup_target_for_coverage_gcovr_html ( # use gcovr to generate coverage report
    NAME app_coverage          # target name
    EXECUTABLE shell-app       # what to run inside the build directory?
    EXCLUDE
      "test/test_pid.cpp"    # Exclude unit test from app coverage
  )
endif()

# Add a target for clang-tidy
if(CMAKE_EXPORT_COMPILE_COMMANDS)
  add_custom_target(run_clang_tidy
    COMMAND clang-tidy -p ${CMAKE_BINARY_DIR} ${CMAKE_SOURCE_DIR}/app/*.cpp ${CMAKE_SOURCE_DIR}/test/*.cpp
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
    COMMENT "Running clang-tidy on source files"
  )
endif()

# Sanity check:
message(STATUS "CMAKE_BUILD_TYPE = ${CMAKE_BUILD_TYPE}")
message(STATUS "WANT_COVERAGE    = ${WANT_COVERAGE}")
