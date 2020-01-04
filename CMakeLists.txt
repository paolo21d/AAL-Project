cmake_minimum_required(VERSION 3.9)
project(SecondStep)

set(CMAKE_CXX_STANDARD 11)

add_executable(SecondStep main.cpp Compare.cpp Compare.h OptimalResolver.cpp OptimalResolver.h BrutforceResolver.cpp BrutforceResolver.h Resolver.cpp Resolver.h)