#include "sort.h"

/**
 * bitonic_merge - merges two halves of an array in ascending order
 * @array: pointer to the array
 * @size: size of the array
 * @up: flag indicating whether to sort in ascending
 */
void bitonic_merge(int *array, size_t size, int up)
{
	size_t mid, i;
	int temp;

	if (size > 1)
	{
		mid = size / 2;

		for (i = 0; i < mid; i++)
		{
			if ((array[i] > array[i + mid]) == up)
			{
				temp = array[i];
				array[i] = array[i + mid];
				array[i + mid] = temp;
			}
		}

		bitonic_merge(array, mid, up);
		bitonic_merge(array + mid, mid, up);
	}
}

/**
 * bitonic_sort_recursive - Recursively sorts a bitonic sequence.
 * @array: Pointer to the array.
 * @size: Size of the array.
 * @up: Flag indicating whether to sort in ascending order (1)
 * or descending (0).
 */
void bitonic_sort_recursive(int *array, size_t size, int up)
{
	size_t mid;

	if (size > 1)
	{
		mid = size / 2;

		bitonic_sort_recursive(array, mid, 1);
		bitonic_sort_recursive(array + mid, mid, 0);

		bitonic_merge(array, size, up);
	}
}

/**
 * bitonic_sort - Sorts an array of integers in ascending order
 *                using the Bitonic sort algorithm.
 * @array: Pointer to the array to be sorted.
 * @size: Size of the array.
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	bitonic_sort_recursive(array, size, 1);
}
