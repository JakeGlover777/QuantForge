
cmake_minimum_required(VERSION 4.1)

project(QuantForge)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(QuantForge
        main.cpp
        MarketData.h
)
