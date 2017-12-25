#include <stdio.h>
#include <stdlib.h>

#include "mergesort.h"
#include "heapsort.h"

/**
 * sort_and_print_randoms(int (*)(int*,int), int)
 *
 * Create a list of integers with the size passed as parameter, populate it with random numbers,
 * print the numbers, sort them using the sorting function passed as parameter, and then print
 * them again.
 *
 * PARAMETERS:
 *      pSortingFunction -> pointer to the sorting function to be used
 *      pSize -> size of the list to create and sort
 *
 */
void sort_and_print_randoms(int (*pSortingFunction)(int*, int), int pSize) {
    int list[pSize];
    // populate array with random numbers
    int i;
    for(i = 0; i < pSize; i++)
        list[i] = rand() % 1000;
    printf("Generated list: ");
    print_array_int(list, pSize);
    // call the sorting function passed as a pointer argument
    pSortingFunction(list, pSize);
    printf("\nSorted list: ");
    print_array_int(list, pSize);
}

int main()
{
    // set the seed for random numbers
    srand(time(NULL));
    printf("Running mergesort algorithm:\n");
    sort_and_print_randoms(&mergesort, 15);
    printf("\nRunning heapsort algorithm:\n");
    sort_and_print_randoms(&heapsort, 15);
    return 0;
}
