#include <stdio.h>

#include "mergesort.h"

/**
 * mergesort2(int*, int, int)
 *
 * Sorts an array list using the merge sort algorithm.
 * This function sorts all the elements between first and last. First it divides the list
 * by half into two sublists, so recursion is used until there is only one element left.
 * Then we always end up with two sorted lists so we can merge (!!!) them. We create a new list
 * that will receive all the merged elements sorted, so we compare the first element of each
 * list against each other, save the smallest one into the new list, and move the pivot of the new
 * sorted list and of the list where the smallest one belongs.
 * We do that until the list is complete.
 *
 * PARAMETERS:
 *      pList -> list of integers to be sorted
 *      pFirst -> position of the first element
 *      pLast -> position of the last element
 *
 */
void mergesort2(int *pList, int pFirst, int pLast) {
    // Nothing to sort!
    if(pFirst >= pLast)
        return;

    // get the distance between first and last elements, the middle element (list 1 end)
    // and the list 2 starting element
    int offset = pLast - pFirst;
    int list1end = pFirst + offset / 2;
    int list2start = list1end + 1;

    // divide and conquer!
    mergesort2(pList, pFirst, list1end);
    mergesort2(pList, list2start, pLast);

    // get the actual size of the list we are sorting (distance between first and last element plus one)
    int size = offset + 1;
    // list used to merge the sublists
    int sortedList[size];

    // starting pivots of each list
    int i = pFirst;
    int n = list2start;
    int sortedPivot;

    // get the smallest element left in the sublists to place in each blank element in the new list
    for(sortedPivot = 0; sortedPivot < size; sortedPivot++) {
        /* if element in list 1 is less than element in list 2
           AND the pivot hasn't got past the end
           OR the second list's pivot has got past the end the smallest one is the elementin the first list.
           We must be careful with the pivots because we always update the original list, so if the pivot
           of the first sublist gets past the end, it means it's pointing now to the second sublist. */
        if((pList[i] < pList[n] && i < list2start) || n > pLast) {
            sortedList[sortedPivot] = pList[i];
            i++;
        }
        // otherwise it's the one in the second list
        else {
            sortedList[sortedPivot] = pList[n];
            n++;
        }
    }

    // replace the original list with the sorted elements for this subset
    for(i = 0, n = pFirst; i < size; i++, n++) {
        pList[n] = sortedList[i];
    }
}

/**
 * mergesort(int*, int)
 *
 * Sorts an array list with the size passed as parameter using the merge sort algorithm.
 *
 * PARAMETERS:
 *      pList -> list of integers to be sorted
 *      pSize -> size of the list
 *
 */
void mergesort(int* pList, int pSize) {
    // nothing to be sorted if less than 2 elements
    if(pSize < 2)
        return;
    mergesort2(pList, 0, pSize - 1);
}
