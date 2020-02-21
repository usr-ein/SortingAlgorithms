/*
 * Copyright (c) 2020 Samuel Prevost.
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#ifndef SORTINGALGORITHMSBENCHMARKER_BENCHMARKER_H
#define SORTINGALGORITHMSBENCHMARKER_BENCHMARKER_H

#include <iostream>
#include <chrono>
using namespace std;

template <class T> using SortingFuncArr = void (*)(T[], size_t);

int* rand_array(int max, size_t n);
void parse_args(int argc, char** argv, int& array_max, int& seed, int& array_size_min,
        int& array_size_max, int& steps, bool& exp_steps);
void benchmark_this(int array_max, int array_size_min, int array_size_max,
                    int steps, bool exp_steps, SortingFuncArr<int> sort, string name);

#endif //SORTINGALGORITHMSBENCHMARKER_BENCHMARKER_H
