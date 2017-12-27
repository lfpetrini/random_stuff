#include <stdlib.h>

#include "common.h"
#include "quicksort.h"

/**
 * quicksort2(int*, int)
 *
 * Sorts an array list with the size passed as parameter using the quick sort algorithm.
 * We choose a random pivot and will keep everything less than its value at the left side of the list
 * and everything greater at the right side. We do it with an iterator and a reverse iterator.
 * Until they don't "run into each other", whenever the iterator finds any value that is greater
 * than the pivot, it stops, waits for the reverse iterator to find a value that is less then
 * the pivot, and then both values are swapped and the iterations continue. Once the iterators
 * meet, we have our two "sublists" and just swap the pivot from the last position to the first
 * element that is greater. Bingo.
 * Another approach is to use a for loop and keep an index for the smaller elements, and whenever we find
 * an element smaller than the pivot, we swap it with index+1 (because the next one after the current
 * index should be greater than the pivot) and increase the index. But I'll stick with the first way.
 *
 * PARAMETERS:
 *      pList -> list of integers to be sorted
 *      pFirst -> position of the first element
 *      pLast -> position of the last element
 *
 */
void quicksort2(int* pList, int pFirst, int pLast) {
    int size = pLast - pFirst + 1;
    if(size < 2)
        return;

    int pivotPosition = pFirst + rand() % size;

    // pivot element will be swapped with the one so we can work with the list
    swap_values_int(&pList[pivotPosition], &pList[pLast]);

    int left = pFirst;
    // last element is our pivot, for now, so we don't touch it
    int right = pLast - 1;
    do {
        if(pList[left] > pList[pLast]) {
            do {
                if(pList[right] < pList[pLast]) {
                    // there is smaller value at the right and a greater at the left. Swap them.
                    swap_values_int(&pList[left], &pList[right]);
                    break;
                }
                right--;
            } while(left <= right);
        }
        left++;
    } while(left <= right);

    // place the pivot in the right position (right + 1, since 'right' should contain the last smaller element)
    pivotPosition = right + 1;
    swap_values_int(&pList[pivotPosition], &pList[pLast]);
    // recursive call for sublists
    quicksort2(pList, pFirst, right);
    quicksort2(pList, pivotPosition + 1, pLast);
}

/**
 * quicksort(int*, int)
 *
 * Sorts an array list with the size passed as parameter using the quick sort algorithm.
 * Quick sort basically uses a divide and conquer technique where it picks a random pivot
 * in a given list, from that list, create two lists, one with all the values greater than
 * the pivot value and another with all the values that are less than the pivot value.
 * Thus, we can know the exact position of the pivot in a sorted list (after we 'merge' all
 * the lists). We do that to all the sublists and finally merge them all.
 *
 * PARAMETERS:
 *      pList -> list of integers to be sorted
 *      pSize -> size of the list
 *
 */
void quicksort(int* pList, int pSize) {
    if(pSize < 2)
        return;
    quicksort2(pList, 0, pSize - 1);
}
