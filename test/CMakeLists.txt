cmake_minimum_required(VERSION 3.15)
project(MPL_test)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -O3 -pthread")

set(testMat_src ../Constant.cpp ../core/Mat.cpp)

add_executable(testMat testMat.cpp ${testMat_src})