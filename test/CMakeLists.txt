cmake_minimum_required(VERSION 2.8)
project(tools_test)

SET(CMAKE_CXX_COMPILE "g++")
SET( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -march=native -O2 -pthread " )
SET( CMAKE_BUILD_TYPE "Release")

find_package(glog REQUIRED)
find_package(Eigen3 REQUIRED)

include_directories(${GLOG_INCLUDE_DIRS} 
${EIGEN3_INCLUDE_DIRS} 
${PROJECT_SOURCE_DIR}/include
)

MESSAGE(STATUS ${EIGEN3_INCLUDE_DIRS})


add_executable(test_log ${PROJECT_SOURCE_DIR}/NavLog.cc)
add_executable(test_time ${PROJECT_SOURCE_DIR}/NavTime.cc)

target_link_libraries(test_log tools glog::glog)
target_link_libraries(test_time tools glog::glog)
