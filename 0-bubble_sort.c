#include "sort.h"

/**
 * bubble_sort - Sorts an array of integers in ascending order using
 * the bubble sort algorithm
 * @array: Pointer to the array to be sorted
 * @size: Size of the array
 */
void bubble_sort(int *array, size_t size)
{
	int swapped, tmp;
	size_t i;

	if (size < 2)
		return;

	do {
		swapped = 0;
		for (i = 0; i < size - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				/* Swap array[i] and array[i + 1] */
				tmp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = tmp;
				swapped = 1;

				/* Set swapped flag to true */
				swapped = 1;

				/* print the current state of the array */
				print_array(array, size);
			}
		}
	} while (swapped);
}
