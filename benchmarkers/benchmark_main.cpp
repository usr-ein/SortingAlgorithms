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
#define FUNC_COUNT 6
#include "benchmark_lib.h"
#include "../src/sorting.h"

using namespace SortingAlgorithms;

int main(int argc, char** argv) {
    int array_max, seed, array_size_min, array_size_max, steps;
    bool exp_steps;
    parse_args(argc, argv, array_max, seed, array_size_min, array_size_max, steps, exp_steps);
    /* Print CSV headers in stdout */
    cout << "algo" << ", ";
    for (int n = array_size_min; n < array_size_max; exp_steps ? n *= steps : n += steps) {
        cout << n << ", ";
    }
    cout << endl;

    SortingFuncArr<int> funcs[FUNC_COUNT] = {
            &quick_sort, &merge_sort, &heap_sort, &insertion_sort, &selection_sort, &bubble_sort
    };

    string funcs_name[FUNC_COUNT] {
        "quick_sort", "merge_sort", "heap_sort", "insertion_sort", "selection_sort", "bubble_sort"
    };

    /* Prints runtime of funcs in nanoseconds for n between min and max with steps as step
     * if exp_steps is True, we multiply n by step at each step, else we just add step every time */
    for (int i = 0; i < FUNC_COUNT; i++){
        benchmark_this(array_max, array_size_min, array_size_max, steps, exp_steps, funcs[i], funcs_name[i]);
    }
}