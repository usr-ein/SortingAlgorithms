cmake_minimum_required(VERSION 3.15)
set(CMAKE_CXX_STANDARD 14)

project(SortingAlgorithmsLib)
# Header only, so add_library is useless
#add_library(SortingAlgorithmsLib STATIC src/sorting.cpp)

project(SortingAlgorithmsTests)
add_executable(SortingAlgorithmsTests tests.cpp src/sorting.h)

project(benchmark)
add_executable(benchmark
        benchmarkers/benchmark_lib.cpp
        benchmarkers/benchmark_lib.h
        src/sorting.h
        benchmarkers/benchmark_main.cpp
        )
