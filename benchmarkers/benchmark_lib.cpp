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
#include "benchmark_lib.h"

int* rand_array(int max, size_t n){
    int* rand_arr = (int*)malloc(sizeof(int)*n);
    for (int i = 0; i < n; ++i) {
        rand_arr[i] = rand() % max;
    }
    return rand_arr;
}

void parse_args(int argc, char** argv, int& array_max, int& seed, int& array_size_min,
        int& array_size_max, int& steps, bool& exp_steps){
    if (argc <= 6) {
        cout << "Usage " << argv[0] << " maxVal seed arraySizeMin arraySizeMax steps exp_steps(0 or 1)" << endl;
        exit(EXIT_FAILURE);
    }
    array_max = atoi(argv[1]);
    seed = atoi(argv[2]);
    srand(seed);
    array_size_min = max(1, atoi(argv[3]));
    array_size_max = max(array_size_min, atoi(argv[4]));
    steps = atoi(argv[5]);
    exp_steps = (bool)atoi(argv[6]);
}

void benchmark_this(int array_max, int array_size_min, int array_size_max,
        int steps, bool exp_steps, SortingFuncArr<int> sort, string name){
    cout << name << ", ";
    for (int n = array_size_min; n < array_size_max; exp_steps ? n *= steps : n += steps) {
        int* arr = rand_array(array_max, n);
        auto t1 = std::chrono::high_resolution_clock::now();
        sort(arr, n);
        auto t2 = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>( t2 - t1 ).count();
        cout << duration << ", ";
        free(arr);
    }
    cout << endl;
}
