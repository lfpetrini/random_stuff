#include <stdio.h>

#include "common.h"

/**
 * print_array_int(int*, int)
 *
 * Prints an array list of integers, separated by space.
 *
 * PARAMETERS:
 *      pList -> list of integers to be printed
 *      pSize -> size of the list
 *
 */
void print_array_int(int* pList, int pSize) {
    int i;
    for(i = 0; i < pSize; i++)
        printf("%d ", pList[i]);
}

/**
 * swap_values_int(int*, int*)
 *
 * Swap the values of two integers.
 *
 * PARAMETERS:
 *      pValue1 -> address of the first integer
 *      pValue2 -> address of the second integer
 *
 */
void swap_values_int(int* pValue1, int* pValue2) {
    int temp = *pValue1;
    *pValue1 = *pValue2;
    *pValue2 = temp;
}

/**
 * populate_array_with_randoms_int(int*, int, int, int)
 *
 * Populate an array list with random integers.
 *
 * PARAMETERS:
 *      pList -> array list to populate
 *      pSize -> size of the array list
 *      pMin -> minimum random integer value
 *      pMax -> maximum random integer value
 *
 */
void populate_array_with_randoms_int(int* pList, int pSize, int pMin, int pMax) {
    // populate array with random numbers
    for(int i = 0; i < pSize; i++)
        pList[i] = pMin + rand() % pMax;
}

/**
 * is_array_sorted_int(int*, int)
 *
 * Verify if the elements of an array list are sorted.
 *
 * PARAMETERS:
 *      pList -> array list
 *      pSize -> size of the array list
 *
 * RETURN 1 if the elements are sorted, 0 otherwise
 *
 */
int is_array_sorted_int(int* pList, int pSize) {
    for(int i = 1; i < pSize; i++)
        if(pList[i] < pList[i-1])
            return 0;
    return 1;
}
