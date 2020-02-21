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

#include <iostream>
#include <vector>
#include "src/sorting.h"
using namespace std;

template <class T> void print_array(T array[], int n){
    for (int i = 0; i < n; ++i) {
        cout << array[i] << ", ";
    }
    cout << endl;
}

template <class T> void print_vector(vector<T> vect){
    for (T e : vect){
        cout << e << ", ";
    }
    cout << endl;
}

int* rand_array(int max, size_t n){
    int* rand_arr = (int*)malloc(sizeof(int)*n);
    for (int i = 0; i < n; ++i) {
        rand_arr[i] = rand() % max;
    }
    return rand_arr;
}

template <class T> using SortingFuncArr = void (*)(T[], size_t);
template <class T> using SortingFuncVect = void (*)(vector<T>&);

/**
 * Tests the functions `sorting_func_arr` and `sorting_func_vect` on integers arrays
 * @param name the name of the algorithm to print
 * @param n the size of the random array to generate, min value will be 0, max value will be min(7*n, RAND_MAX)
 * usually RAND_MAX = max value of a signed int32 = 0x7fffffff = 2^31
 * @param sorting_func_arr
 * @param sorting_func_vect
 */
void test_sorting_function(string name, int n,
        SortingFuncArr<int> sorting_func_arr, SortingFuncVect<int> sorting_func_vect){
    cout
    << "----------------------------------------"
    << "----------------------------------------"
    << endl;
    int max = min(RAND_MAX, 7*n);
    int* array = rand_array(max, n);
    cout << name << " tests:" << endl;
    cout << "\tArray:" << endl << "\t\t";
    print_array(array, n);
    sorting_func_arr(array, n);
    cout << "\t\t";
    print_array(array, n);

    free(array);
    array = rand_array(max, n);

    cout << "\tVector:" << endl << "\t\t";
    vector<int> vect(array, array + n);
    print_vector(vect);
    sorting_func_vect(vect);
    cout << "\t\t";
    print_vector(vect);
    free(array);
}



int main(int argc, char** argv){
    std::srand(std::time(nullptr));

    int array_size = 32;
    if (argc > 1)
        array_size = atoi(argv[1]);

    /* Quick Sort tests */
    test_sorting_function("Quick Sort", array_size,
                          &SortingAlgorithms::quick_sort, &SortingAlgorithms::quick_sort);

    /* Merge Sort tests */
    test_sorting_function("Merge Sort", array_size,
                          &SortingAlgorithms::merge_sort, &SortingAlgorithms::merge_sort);

    /* Heap Sort tests */
    test_sorting_function("Heap Sort", array_size,
                          &SortingAlgorithms::heap_sort, &SortingAlgorithms::heap_sort);

    /* Insertion Sort tests */
    test_sorting_function("Insertion Sort", array_size,
                          &SortingAlgorithms::insertion_sort, &SortingAlgorithms::insertion_sort);

    /* Selection Sort tests */
    test_sorting_function("Selection Sort", array_size,
                          &SortingAlgorithms::selection_sort, &SortingAlgorithms::selection_sort);

    /* Bubble Sort tests */
    test_sorting_function("Bubble Sort", array_size,
                          &SortingAlgorithms::bubble_sort, &SortingAlgorithms::bubble_sort);
    return 0;
}