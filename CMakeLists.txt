cmake_minimum_required(VERSION 3.10)
project(datatype)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${PROJECT_SOURCE_DIR}/cmake_modules)

find_package(Eigen3 3.3 REQUIRED)

add_library(datatype INTERFACE)
add_library(common::datatype ALIAS datatype)
target_include_directories(datatype INTERFACE include ${EIGEN3_INCLUDE_DIRS})
target_link_libraries(datatype INTERFACE)

option(${CMAKE_PROJECT_NAME}_TEST "BUILD TEST" OFF)
if(${CMAKE_PROJECT_NAME}_TEST)
  find_package(GTest REQUIRED)
  include_directories(${GTEST_INCLUDE_DIRS})
  link_libraries(${GTEST_BOTH_LIBRARIES} common::datatype)

  add_executable(datatype_gnss_test test/datatype_gnss_test.cc)
  add_executable(datatype_imu_test test/datatype_imu_test.cc)
  add_executable(datatype_pose_test test/datatype_pose_test.cc)
  add_executable(datatype_keypose_test test/datatype_keypose_test.cc)
  add_executable(datatype_reflector_test test/datatype_reflector_test.cc)
endif()
