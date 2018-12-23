cmake_minimum_required(VERSION 2.8.8)

if (CMAKE_VERSION VERSION_LESS "3.1")
  add_definitions(-std=c++11)
else()
  set(CMAKE_CXX_STANDARD 11)
  set(CMAKE_CXX_STANDARD_REQUIRED ON)
  set(CMAKE_CXX_EXTENSIONS OFF)
endif()

project(addtest)

set(ROOT_PATH ${PROJECT_SOURCE_DIR}/../)
set(GTEST_PATH ${ROOT_PATH}/3rdparty/gtest)

INCLUDE_DIRECTORIES(
    ${ROOT_PATH}/core
    ${GTEST_PATH}
    ${GTEST_PATH}/include
)

set(SRC
    ${ROOT_PATH}/core/main.cpp
    ${ROOT_PATH}/core/test.cpp
)

set(GTEST_SRC
    ${GTEST_PATH}/src/gtest-all.cc
)

LINK_DIRECTORIES(
   ${GTEST_PATH}/lib
)

#gtest.lib生成一次之后，不再重复生成，提高编译速度
#ADD_LIBRARY(gtest ${GTEST_SRC})
ADD_EXECUTABLE(${PROJECT_NAME} ${SRC})

target_link_libraries(${PROJECT_NAME} gtest)


