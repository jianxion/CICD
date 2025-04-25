# cmake_minimum_required(VERSION 3.10)

# project(MyCMakeProject)

# set(CMAKE_CXX_STANDARD 11)
# set(CMAKE_CXX_STANDARD_REQUIRED True)

# include_directories(include)

# file(GLOB SOURCES "src/*.cpp")

# add_executable(MyCMakeProject ${SOURCES})

cmake_minimum_required(VERSION 3.10)

project(MyCMakeProject)


# Include directories
include_directories(include)

set(CMAKE_BUILD_TYPE Debug)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)


# Add executable
add_executable(my_cmake_project
    src/main.cpp
    src/my_functions.cpp
)