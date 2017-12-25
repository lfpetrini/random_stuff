#include <stdio.h>

#include "heapsort.h"

/**
 * convert_to_heap(int*, int, int)
 *
 * Convert a branch of a binary tree, from a given node, to a heap (binary tree where the children
 * nodes are always less than their parent).
 * If the parent node is already greater than its children (or we try to use a node that is over the size
 * of the list), nothing is done. Otherwise, its value is swapped with the one of the largest child, and
 * then the function is called again against this child node (after the value is swapped with the parent's).
 *
 * PARAMETERS:
 *      pList -> array of integers to be converted to a heap
 *      pElement -> element in the array representing the parent node
 *      pSize -> size of the list
 *
 */
void convert_to_heap(int *pList, int pParent, int pSize) {
    // we assume the largest as the parent element
    int largestElementPosition = pParent;
    int child1 = pParent * 2 + 1;
    int child2 = child1 + 1;

    // if first child is over the size of the list, parent element has no children
    if(child1 >= pSize)
        return;

    // now we'll find out the position of the largest element between the three

    if(pList[largestElementPosition] < pList[child1])
        largestElementPosition = child1;

    if(child2 < pSize && pList[largestElementPosition] < pList[child2])
        largestElementPosition = child2;

    // largest is not the parent? Swap their values and convert the child into a heap
    if(largestElementPosition != pParent) {
        swap_values_int(&pList[largestElementPosition], &pList[pParent]);
        convert_to_heap(pList, largestElementPosition, pSize);
    }
}

/**
 * heapsort(int*, int)
 *
 * Sorts an array list with the size passed as parameter using the heap sort algorithm.
 * The heap sort algorithm consists of creating a heap, i.e., a  binary tree in which each node
 * have a value that must be less than its parent's. We can easily represent a binary tree structure
 * in a array where any element n have two children positioned at n*2+1 and n*2+2.
 * After the array is turned into a heap, all we have to do is swap the last element with the first
 * one (the largest value in the list), and then convert the structure into a heap again, now
 * ignoring the last node that is now the largest one.
 * We keep doing that until all nodes are sorted.
 *
 * PARAMETERS:
 *      pList -> list of integers to be sorted
 *      pSize -> size of the list
 *
 */
void heapsort(int* pList, int pSize) {
    // start from the middle to the beginning
    for(int i = pSize / 2 - 1; i >= 0; i--)
        convert_to_heap(pList, i, pSize);

    /* now that we have a full heap, from the last element to the first, we swap the values
       of the first element with the current iteration's value (the root of the heap is always
       the largest, thus the sorting magic), then we need to convert the whole list to a heap again */
    for(int i = pSize - 1; i >= 0; i--) {
        swap_values_int(&pList[i], &pList[0]);
        convert_to_heap(pList, 0, i);
    }
}
