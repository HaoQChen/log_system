cmake_minimum_required(VERSION 2.8.12)

#use dlib to implement a log system by face detection and face alignment and face recognition
project(log_system)


add_subdirectory(./dlib/dlib dlib_build)

#add_definitions(-std=c++11)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

# find_package(Threads REQUIRED)

# link_directories(dlib)

add_library(${PROJECT_NAME} SHARED log_system.cpp)
target_link_libraries(${PROJECT_NAME} dlib::dlib ${OpenCV_LIBS})

add_executable(log_test test.cpp)
target_link_libraries(log_test ${PROJECT_NAME}  ${OpenCV_LIBS})