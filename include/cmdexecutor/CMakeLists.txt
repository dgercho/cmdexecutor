cmake_minimum_required(VERSION 3.22.0)
project(CmdExecutor CXX)
set(CMAKE_CXX_STANDARD 20)

add_library(CmdExecutor executor.cpp executor_result.cpp)