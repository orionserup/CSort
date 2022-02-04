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

/**
 * \brief Recursively Creates a Max Heap from the Given Array
 * 
 * \param array: Array to heapify
 * \param size: The Size of the Array
 * \param i: The Point to Heap Around
 * \return Data*: The Heaped Array Back
 */
static Data* MaxHeapify(Data* const array, const size_t size, const size_t i);

/// Sorts Using Heap Sort
Data* HeapSort(Data* const array, const size_t size) {

    Assert(array, "Invalid Array in Heap Sort");

    if(size < 2) // if the array is One or Zero Elements it is sorted
        return array;

    // Build A Max Heap with the Array
    for (size_t i = size / 2 - 1; i != SIZE_MAX; i--)
        MaxHeapify(array, size, i);
 
    // Recurse, placing the Max on The End and then Reducing the Size
    for (size_t i = size - 1; i != SIZE_MAX; i--) {
        Swap(array, array + i); // move the high to the end
        MaxHeapify(array, i, 0); // Heapify to the end
    }

    return array;

}

Data* MaxHeapify(Data* const array, const size_t size, const size_t i) {

    Assert(array, "Invalid Array in Heapify");

    size_t max = i; // track the index where the parent should be
    size_t left = 2 * i + 1; // the left leaf
    size_t right = 2 * i + 2; // the right leaf
  
    // If the left is in the array and the value there is larger than that of max
    if (left < size && array[left] > array[max])
        max = left; // make the max index the left index
  
    // Same as Before but for right
    if (right < size && array[right] > array[max])
        max = right;
  
    // If we didn't pick the max value
    if (max != i) {
        Swap(&array[i], &array[max]); // make it the max value
        MaxHeapify(array, size, max); // recurse to check again
    }

    return array;

}
