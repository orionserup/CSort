/**
 * \file HeapSort.c
 * \author Orion Serup (orionserup@gmail.com)
 * \brief Contains the Implementation of the Heap Sort and its helpers 
 * \version 0.1
 * \date 2022-01-08
 * 
 * \copyright Copyright (c) 2022
 * 
 */
#include "HeapSort.h"

static Data* Heapify(Data* const array, const size_t size, const size_t i);

/// Sorts Using Heap Sort
Data* HeapSort(Data* const array, const size_t size) {

    Assert(array, "Invalid Array in Heap Sort");

    if(size < 2) return array;

    for(size_t i = size / 2 - 1; i >= 0; i--)
        Heapify(array, size, i);


    for(size_t i = size - 1; i > 0; i--) {

        Swap(array, array + i);
        Heapify(array, i, 0);

    }

    return array;

}

Data* Heapify(Data* const array, const size_t size, const size_t i) {

    Assert(array, "Invalid Array in Heapify");

    size_t max = i;
    size_t left = 2 * i + 1;
    size_t right = 2 * i + 2;

    if(left < size && array[left] > array[max])
        max = left;

    if(right < size && array[right] > array[max])
        max = right;

    if(max != i) {

        Swap(array + i, array + max);
        Heapify(array, size, max);

    }

    return array;

}
