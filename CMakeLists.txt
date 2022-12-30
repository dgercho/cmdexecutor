cmake_minimum_required(VERSION 3.22.0)
project(Demo)
set(CMAKE_CXX_STANDARD 20)

include_directories(include)
add_subdirectory(include/cmdexecutor)

add_executable(${CMAKE_PROJECT_NAME} demo.cpp)

target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE CmdExecutor)
