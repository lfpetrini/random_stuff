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

