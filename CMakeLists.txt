cmake_minimum_required(VERSION 3.23)
project(JMachineProblem)

set(CMAKE_CXX_STANDARD 14)

file(GLOB source
        *.cpp
        *.h
        *.hpp
)

add_executable(JMachineProblem ${source})