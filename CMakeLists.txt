cmake_minimum_required(VERSION 3.30)

project(BGEIC)

include_directories(BGEIC include/)
set(BGEIC_SOURCES sources/main.cpp)

add_executable(BGEIC ${BGEIC_SOURCES})