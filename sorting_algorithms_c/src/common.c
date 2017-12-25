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
