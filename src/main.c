/**
 * \file main.c
 * \author Orion Serup (orionserup@gmail.com)
 * \brief Contains the main function
 * \version 0.1
 * \date 07-01-2022
 * 
 * \copyright Copyright (c) 2022
 * 
 */

#include "Sorts.h"
#include "SortBenchmark.h"

/// The Minimum Number of Elements to Test
#define MIN  100
/// The Maximum Number of Elements to Test
#define MAX  5000
/// How Far Apart Two Trials should be
#define STEP 100
/// How Big of an array is needed to store this data
#define SIZE (MAX - MIN) / STEP + 1

/**
 * \brief The Entry Point of the Program
 * 
 * \return int: The Status Code
 */
int main() {

    Sort sorts[] = { QUICK_SORT, RADIX_SORT};
    const size_t numsorts = sizeof(sorts)/sizeof(Sort);

    Data n[SIZE];
    for(Data i = 0; i < SIZE; i++)
        n[i] = MIN + STEP * i;

    BenchmarkSorts(sorts, numsorts, n, SIZE, 50);

    return EXIT_SUCCESS;

}

