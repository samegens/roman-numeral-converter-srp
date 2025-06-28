cmake_minimum_required(VERSION 3.22)
project(RomanNumeralConverter)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()

# Enable debug symbols and disable optimization for Debug builds
set(CMAKE_CXX_FLAGS_DEBUG "-g -O0")

# Enable testing
enable_testing()

# Set the C++ standard to C++11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Shared source files
set(SHARED_SOURCES
    src/main.cpp
)

# Add the main executable
add_executable(convert src/main.cpp ${SHARED_SOURCES})
