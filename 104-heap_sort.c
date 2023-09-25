#include "sort.h"

/**
 * sift_down - Maintains the max heap property by moving an element down.
 * @array: Pointer to the array.
 * @size: Size of the array.
 * @root: Index of the root node.
 * @max_size: Size of the subarray to consider.
 */
void sift_down(int *array, size_t size, size_t root, size_t max_size)
{
	size_t largest, left, right;
	int temp;

	largest = root;
	left = 2 * root + 1;
	right = 2 * root + 2;

	if (left < max_size && array[left] > array[largest])
		largest = left;

	if (right < max_size && array[right] > array[largest])
		largest = right;

	if (largest != root)
	{
		/* Swap the root with the largest element */
		temp = array[root];
		array[root] = array[largest];
		array[largest] = temp;

		/* Print the array after each swap */
		print_array(array, size);

		/* Recursively sift down the affected subarray */
		sift_down(array, size, largest, max_size);
	}
}

/**
 * heap_sort - Sorts an array of integers in ascending order
 *             using the Heap sort algorithm (Sift-down).
 * @array: Pointer to the array to be sorted.
 * @size: Size of the array.
 */
void heap_sort(int *array, size_t size)
{
	int temp;
	size_t i;

	if (array == NULL || size < 2)
		return;

	/* Build a max heap */
	for (i = size / 2 - 1; i < size; i--)
		sift_down(array, size, i, size);

	/* Extract elements one by one */
	for (i = size - 1; i > 0; i--)
	{
		/* Swap the root (max element) with the last element */
		temp = array[0];
		array[0] = array[i];
		array[i] = temp;

		/* Print the array after each swap */
		print_array(array, size);

		/* Maintain the max heap property on the reduced array */
		sift_down(array, size, 0, i);
	}
}
