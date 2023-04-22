cmake_minimum_required(VERSION 3.25)
project(CLionProjects)

set(CMAKE_CXX_STANDARD 17)

add_executable(CLionProjects main.cpp animals.h animals.cpp birds.h birds.cpp separator.h separator.cpp base.h base.cpp points.cpp points.h)
