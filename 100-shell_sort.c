#include "sort.h"

/**
 * shell_sort - Sorts an array of integers in ascending order
 * using the shell sort algorithm (knuth)
 * @array: Pointer to the array to be sorted
 * @size: size of the array
 */

void shell_sort(int *array, size_t size)
{
	size_t i, j, gap = 1;
	int temp;

	if (array == NULL || size < 2)
		return;

	/* calculate the initial gap using the knuth sequence */
	while (gap < size / 3)
		gap = gap * 3 + 1;

	while (gap >= 1)
	{
		for (i = gap; i < size; i++)
		{
			/* Perform insertion sort on elements with the gap */
			temp = array[i];
			j = i;

			while (j >= gap && array[j - gap] > temp)
			{
				array[j] = array[j - gap];
					j -= gap;
			}

			array[j] = temp;
		}
		print_array(array, size);

		/* cal the next gap */
		gap = (gap - 1) / 3;
	}
}
