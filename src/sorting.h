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

#ifndef SORTINGALGORITHMS_LIBRARY_H
#define SORTINGALGORITHMS_LIBRARY_H

#include <iostream>
using namespace std;

/* Prototypes */
namespace SortingAlgorithms {
    /***
     * Sorts the array in place using QuickSort (ϴ(nlogn) and O(n^2), mem O(logn))
     * @tparam T type of the array's elements
     * @param array array to be sorted
     * @param size size of the array to sort
     */
    template <class T> void quick_sort(T array[], size_t size);

    /***
     * Sorts the vector elements in place using QuickSort (ϴ(nlogn) and O(n^2), mem O(logn))
     * @tparam T type of the vector's elements
     * @param list vector<T> to be sorted
     */
    template <class T> void quick_sort(vector<T>& list) {
        if(__cplusplus >= 201103L) // C++11 or greater
            quick_sort(list.data(), list.size());
        else
            quick_sort(&list[0], list.size());
    }

    /***
     * Sorts the array "in place" using MergeSort (ϴ(nlogn) and O(nlogn), mem O(n) so not in-place sorting per se)
     * @tparam T type of the array's elements
     * @param array array to be sorted
     * @param size size of the array to sort
     */
    template <class T> void merge_sort(T array[], size_t size);

    /***
     * Sorts the vector elements in place using MergeSort (ϴ(nlogn) and O(nlogn), mem O(n))
     * @tparam T type of the vector's elements
     * @param list vector<T> to be sorted
     */
    template <class T> void merge_sort(vector<T>& list){
        if(__cplusplus >= 201103L) // C++11 or greater
            merge_sort(list.data(), list.size());
        else
            merge_sort(&list[0], list.size());
    }
    /***
     * Sorts the array in place using HeapSort (ϴ(nlogn) and O(nlogn), mem O(1))
     * implemented with Floyd's heap construction (siftDown only) and a max heap
     * @tparam T type of the array's elements
     * @param array array to be sorted
     * @param size size of the array to sort
     */
    template <class T> void heap_sort(T array[], size_t size);

    /***
     * Sorts the vector elements in place using HeapSort (ϴ(nlogn) and O(nlogn), mem O(1))
     * implemented with Floyd's heap construction (siftDown only) and a max heap
     * @tparam T type of the vector's elements
     * @param list vector<T> to be sorted
     */
    template <class T> void heap_sort(vector<T>& list){
        if(__cplusplus >= 201103L) // C++11 or greater
            heap_sort(list.data(), list.size());
        else
            heap_sort(&list[0], list.size());
    }
    /***
     * Sorts the array in place using InsertionSort (ϴ(n^2) and O(n^2), mem O(1))
     * @tparam T type of the array's elements
     * @param array array to be sorted
     * @param size size of the array to sort
     */
    template <class T> void insertion_sort(T array[], size_t size);

    /***
     * Sorts the vector elements in place using InsertionSort (ϴ(n^2) and O(n^2), mem O(1))
     * @tparam T type of the vector's elements
     * @param list vector<T> to be sorted
     */
    template <class T> void insertion_sort(vector<T>& list){
        if(__cplusplus >= 201103L) // C++11 or greater
            insertion_sort(list.data(), list.size());
        else
            insertion_sort(&list[0], list.size());
    };

    /***
     * Sorts the array in place using SelectionSort (ϴ(n^2) and O(n^2), mem O(1))
     * @tparam T type of the array's elements
     * @param array array to be sorted
     * @param size size of the array to sort
     */
    template <class T> void selection_sort(T array[], size_t size);

    /***
     * Sorts the vector elements in place using SelectionSort (ϴ(n^2) and O(n^2), mem O(1))
     * @tparam T type of the vector's elements
     * @param list vector<T> to be sorted
     */
    template <class T> void selection_sort(vector<T>& list){
        if(__cplusplus >= 201103L) // C++11 or greater
            selection_sort(list.data(), list.size());
        else
            selection_sort(&list[0], list.size());
    };

    /***
     * Sorts the array in place using BubbleSort (ϴ(n^2) and O(n^2), mem O(1))
     * @tparam T type of the array's elements
     * @param array array to be sorted
     * @param size size of the array to sort
     */
    template <class T> void bubble_sort(T array[], size_t size);

    /***
     * Sorts the vector elements in place using BubbleSort (ϴ(n^2) and O(n^2), mem O(1))
     * @tparam T type of the vector's elements
     * @param list vector<T> to be sorted
     */
    template <class T> void bubble_sort(vector<T>& list){
        if(__cplusplus >= 201103L) // C++11 or greater
            bubble_sort(list.data(), list.size());
        else
            bubble_sort(&list[0], list.size());
    };

} // end namespace SortingAlgorithms

/* Implementations */
namespace SortingAlgorithms {

    /* Swaps values so that the pivot is at (i+j)/2 and everything
     * on its right is greater and everything on its left is lower
     * (Hoare partition scheme)
     */
    template<class T>
    unsigned int _quick_sort_partition(T *array, unsigned int i, unsigned int j){
        T temp, pivot = array[(i + j) >> 1];
        i--; j++;
        while (true){
            do { i++; } while (array[i] < pivot);
            do { j--; } while (array[j] > pivot);
            if (i >= j) return j;
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
            /* Does not work between non integers (or non binary shiftable types)
             * but would be tidier
             * list[i] ^= list[j];
             * list[j] ^= list[i];
             * list[i] ^= list[j];
             * */
        }
    }

    /* partition the segment [i,j] and calls itself on the left and right
     * */
    template<class T>
    void _quick_sort_recursive(T arr[], size_t n, unsigned int i, unsigned int j) {
        if (i < j){
            unsigned int partition_index = SortingAlgorithms::_quick_sort_partition(arr, i, j);
            SortingAlgorithms::_quick_sort_recursive(arr, n, i, partition_index);
            SortingAlgorithms::_quick_sort_recursive(arr, n, partition_index+1, j);
        }
    }

    template<class T>
    void quick_sort(T array[], size_t size) {
        if (size == 0) return;
        SortingAlgorithms::_quick_sort_recursive(array, size, 0, size - 1);
    }

    template <class T> void print_array(T array[], int n){
        for (int i = 0; i < n; ++i) {
            cout << array[i] << ", ";
        }
        cout << endl;
    }

    template <class T> void merge_sort(T array[], size_t size){
        /* Classical variant */
        // if (size == 1){
        //     return;
        // }

        /* Insertion sort is faster for smaller arrays */
        if (size <= 10){
            insertion_sort(array, size);
            return;
        }
        unsigned int mid = size >> 1;
        merge_sort(array, mid);
        merge_sort(array+mid, size - mid);
        // Here comes the O(n) memory cost
        T* aux = (T*)malloc(sizeof(T)*size);
        // Merge two sorted array into one sorted array
        unsigned int i = 0, j = mid;
        for (int k = 0; k < size; ++k) {
            if (i < mid && (j >= size || array[i] <= array[j])){
                aux[k] = array[i];
                i += 1;
            } else {
                aux[k] = array[j];
                j += 1;
            }
        }
        for (int l = 0; l < size; ++l) {
            array[l] = aux[l];
        }
        // But we can still at least free it
        free(aux);
    }

    template <class T> unsigned int _heap_get_max_child(unsigned int i, T *array, size_t size){
        unsigned int left_child = (i<<1) + 1;
        if (left_child >= size) {
            return size+1; // Special value to stop the loop
        }
        unsigned int right_child = left_child + 1;
        if (right_child == size){
            return left_child;
        }
        return (array[right_child] > array[left_child]) ? right_child : left_child;
    }

    template <class T> void _heap_sort_sift_down(T val, unsigned int i, T array[], size_t size){
        unsigned int min_child = _heap_get_max_child(i, array, size);
        // the bigger val at the top, smaller under
        while (min_child != size+1 && array[min_child] > val){
            array[i] = array[min_child];
            i = min_child;
            min_child = _heap_get_max_child(i, array, size);
        }
        array[i] = val;
    }

    template <class T> void heap_sort(T array[], size_t size){
        // Heapify (every parent is bigger or equal to its children)
        // takes O(nlogn), c.f. Floyd's heap construction
        for (int i = ((int)size >> 1) - 1; i > -1; --i) {
            _heap_sort_sift_down(array[i], i, array, size);
        }
        // While we still haven't find all the max keep going
        while (size > 0){
            // Keep the last item, which we will later put back at its rightful place
            T last = array[--size];
            // Save up the biggest value (the root of the heap) at the back where
            // used to the `last` (but hopefully now we saved it so we can replace it)
            array[size] = array[0];
            // Reinsert the `last` in our array from the top and let it get to its rightful place
            // N.B. the `size` was updated so sink won't go too far and wont overwrite the saved up values
            // at the back of the array.
            _heap_sort_sift_down(last, 0, array, size);
        }
    }

    template<class T>
    void insertion_sort(T *array, size_t size) {
        T temp;
        for (int i = 1; i < size; ++i) {
            for (int j = i; j > 0 && array[j-1] > array[j]; --j) {
                temp = array[j-1];
                array[j-1] = array[j];
                array[j] = temp;
            }
        }
    }

    template<class T>
    void selection_sort(T *array, size_t size) {
        T temp;
        int j_min;
        for (int i = 0; i < size-1; ++i) {
            j_min = i;
            for (int j = i+1; j < size; ++j) {
                if (array[j] < array[j_min]){
                    j_min = j;
                }
            }
            if (j_min != i){
                temp = array[i];
                array[i] = array[j_min];
                array[j_min] = temp;
            }
        }
    }

    template<class T>
    void bubble_sort(T *array, size_t size) {
        T temp;
        for (int i = 0; i < size; ++i) {
            for (int j = 1; j < size; ++j) {
                if (array[j-1] > array[j]){
                    temp = array[j-1];
                    array[j-1] = array[j];
                    array[j] = temp;
                }
            }
        }
    }
} // end namespace SortingAlgorithms


#endif //SORTINGALGORITHMS_LIBRARY_H
