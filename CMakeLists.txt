cmake_minimum_required(VERSION 3.22)
project(McDonalds)

set(CMAKE_CXX_STANDARD 17)

find_package(Threads)
add_executable(McDonalds src/main.cpp src/items.h src/constants.h src/util.h src/printers.h)
target_link_libraries(McDonalds ${CMAKE_THREAD_LIBS_INIT})
