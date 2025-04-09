u#include "sort.h"
#include <stdio.h>

/**
 * swap - Swaps two integers in place
 * @a: Pointer to the first integer
 * @b: Pointer to the second integer
 */
void swap(int *a, int *b)
{
int t = *a;
*a = *b;
*b = t;
}
/**
 * maxHeapify - Heapifies a subtree rooted at index idx in a Max Heap
 * @array: Array representation of the heap
 * @size: Total size of the array (used for printing)
 * @idx: Index of the current root node
 * @n: Current size of the heap (may decrease during sorting)
 */
void maxHeapify(int *array, size_t size, int idx, size_t n)
{
int largest = idx;
int left = 2 * idx + 1;
int right = 2 * idx + 2;
if (left < (int)n && array[left] > array[largest])
largest = left;
if (right < (int)n && array[right] > array[largest])
largest = right;
if (largest != idx)
{
swap(&array[idx], &array[largest]);
print_array(array, size);
maxHeapify(array, size, largest, n);
}
}
/**
 * heap_sort - Sorts an array of integers in ascending order using Heap sort
 * @array: The array to sort
 * @size: Number of elements in the array
 */
void heap_sort(int *array, size_t size)
{
int i;
if (array == NULL || size < 2)
return;
for (i = (size - 2) / 2; i >= 0; --i)
maxHeapify(array, size, i, size);
for (i = (size - 1); i > 0; --i)
{
swap(&array[0], &array[i]);
print_array(array, size);
maxHeapify(array, size, 0, i);
}
}
