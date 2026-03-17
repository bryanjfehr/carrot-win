cmake_minimum_required(VERSION 3.14)
project(carrot VERSION 0.1.0 LANGUAGES CXX)

# Find dependencies
find_package(unofficial-sodium CONFIG REQUIRED)
find_package(cppzmq CONFIG REQUIRED)
find_package(Boost CONFIG REQUIRED COMPONENTS core)

# Add include directory
include_directories(include)

# Create library
add_library(carrot src/carrot.cpp)
target_include_directories(carrot PUBLIC include)
target_link_libraries(carrot PUBLIC memlock unofficial-sodium::sodium cppzmq Boost::core)

# Testing
option(BUILD_TESTING "Build tests" ON)
if(BUILD_TESTING)
    enable_testing()
    add_subdirectory(tests)
endif()
