#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "common.h"
#include "mergesort.h"
#include "heapsort.h"
#include "quicksort.h"

/**
 * sort_and_print_randoms(int (*)(int*,int), int)
 *
 * Create an array of integers with the size passed as parameter, populate it with random numbers,
 * print the numbers, sort them using the sorting function passed as parameter, and then print
 * them again.
 *
 * PARAMETERS:
 *      pSortingFunction -> pointer to the sorting function to be used
 *      pSize -> size of the array to create and sort
 *
 */
void sort_and_print_randoms(int (*pSortingFunction)(int*, int), int pSize) {
    int list[pSize];
    populate_array_with_randoms_int(list, pSize, 0, 1000);
    printf("Generated list: ");
    print_array_int(list, pSize);
    // call the sorting function passed as a pointer argument
    pSortingFunction(list, pSize);
    printf("\nSorted list: ");
    print_array_int(list, pSize);
}

/**
 * show_statistics(int (*)(int*,int), int, int)
 *
 * Run a determined sorting function the given number of times for lists of random
 * integers, show the execution time and check if all the lists are really sorted.
 *
 * PARAMETERS:
 *      pSortingFunction -> pointer to the sorting function to be used
 *      pListSize -> size of the array lists to create and sort
 *      pFunctionCalls -> number times to create, sort and verify the array lists
 *
 */
void show_statistics(int (*pSortingFunction)(int*, int), int pListSize, int pFunctionCalls) {
    clock_t clocks;
    int isSorted = 1;
    printf("Running sorting function %d times with random lists of %d elements....\n", pFunctionCalls, pListSize);
    clocks = clock();
    for(int i = 0; i < pFunctionCalls; i++) {
        int list[pListSize];
        populate_array_with_randoms_int(list, pListSize, 0, 1000);
        pSortingFunction(list, pListSize);
        isSorted &= is_array_sorted_int(list, pListSize);
    }
    clocks = clock() - clocks;
    printf("Time: %.4f s. All %d lists sorted: %s.\n", (float)clocks / CLOCKS_PER_SEC, pFunctionCalls, isSorted ? "yes" : "no");
}

int main()
{
    // set the seed for random numbers
    srand(time(NULL));
    printf("Running mergesort algorithm:\n");
    sort_and_print_randoms(&mergesort, 15);
    printf("\n\nRunning heapsort algorithm:\n");
    sort_and_print_randoms(&heapsort, 15);
    printf("\n\nRunning quicksort algorithm:\n");
    sort_and_print_randoms(&quicksort, 15);

    printf("\n\n\n--------------------\n\n\n");

    printf("Checking mergesort:\n");
    show_statistics(&mergesort, 300, 2000);
    printf("Checking heapsort:\n");
    show_statistics(&heapsort, 300, 2000);
    printf("Checking quicksort:\n");
    show_statistics(&quicksort, 300, 2000);
    return 0;
}
