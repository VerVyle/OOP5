cmake_minimum_required(VERSION 3.25)
project(CLionProjects)

set(CMAKE_CXX_STANDARD 17)

add_executable(CLionProjects main.cpp headers/animals.h source/animals.cpp headers/birds.h source/birds.cpp headers/separator.h source/separator.cpp headers/base.h source/base.cpp source/points.cpp headers/points.h)
