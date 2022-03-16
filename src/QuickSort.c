/**
 * \file QuickSort.c
 * \author Orion Serup (orionserup@gmail.com)
 * \brief Contains the Implementation of Quick Sort and its helpers
 * \version 0.1
 * \date 2022-01-09
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "QuickSort.h"

/**
 * \brief Partitions the Array Around the Last Element
 * 
 * \param array: Array to Partition
 * \param size: Size of the Array
 * \return size_t: Index of the Pivot
 */
static size_t Partition(Data* const array, const size_t size);

Data* QuickSort(Data* const array, const size_t size) {

    Assert(array, "Bad Array in QuickSort");
    
    if(size < 2) return array; // an array of 1 or zero elements is already sorted

    size_t part = Partition(array, size); // Find the Pivot Index After Moving it to the Correct Spot

    QuickSort(array, part); // Recurse on the First part of the Array
    QuickSort(array + part + 1, size - part - 1); // Recurse on the Other Part

    return array;

}

static size_t Partition(Data* const array, const size_t size) {

    Assert(array, "Bad Array in Partition");

    Data pivot = array[size - 1];
    
    size_t i = SIZE_MAX;
    for(size_t j = 0; j < size - 1; j++) { // go over up until the pivot

        if(array[j] < pivot) { // if we find a value less than the pivot put it to the far left

            i++;
            Swap(array + i, array + j); // move the elements so that the pivot will be in the right place

        }
    }

    Swap(array + i + 1, array + size - 1); // move the pivot to where the left elements are lower and right higher
    return i + 1;

}
