cmake_minimum_required(VERSION 3.11)

# Project name and version
project(MyProject VERSION 1.0)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Collect main source files
set(SOURCES
    v2.0.cpp
    helper.cpp
    helperFunctions.cpp
    cFunctions.tpp
)

# Create the main executable
add_executable(MyExecutable ${SOURCES})
target_compile_options(MyExecutable PRIVATE -Wall -Wextra -Wpedantic -O3)

# Message output
message(STATUS "Building MyExecutable from ${SOURCES}")

set(SOURCES2
    my_tests.cpp
    helper.cpp
    helperFunctions.cpp
    cFunctions.tpp
)

# Add test executable
add_executable(tests ${SOURCES2})
target_include_directories(tests PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/v2.0)
