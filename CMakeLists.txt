cmake_minimum_required(VERSION 2.8.0)
project(tools)

include_directories(${PROJECT_SOURCE_DIR}/include)

aux_source_directory(${PROJECT_SOURCE_DIR}/src cpp_files)

add_library(${PROJECT_NAME} SHARED ${cpp_files})
target_link_libraries(${PROJECT_NAME}  glog::glog)
