#include "sort.h"

/**
 * hoare_partition - Partitions the array using the Hoare scheme.
 * @array: Pointer to the array.
 * @size: Size of the array.
 * @low: Index of the lower bound.
 * @high: Index of the upper bound.
 * Return: Index of the pivot element.
 */
int hoare_partition(int *array, size_t size, int low, int high)
{
	int pivot, temp, i, j;

	pivot = array[high];
	i = low - 1;
	j = high + 1;

	while (1)
	{
		do {
			i++;
		} while (array[i] < pivot);

		do {
			j--;
		} while (array[j] > pivot);

		if (i >= j)
			return (j);

		/* Swap array[i] and array[j] */
		temp = array[i];
		array[i] = array[j];
		array[j] = temp;

		/* Print the array after each swap */
		print_array(array, size);
	}
}

/**
 * quick_sort_hoare_recursive - Recursively sorts a partitioned array.
 * @array: Pointer to the array.
 * @size: Size of the array.
 * @low: Index of the lower bound.
 * @high: Index of the upper bound.
 */
void quick_sort_hoare_recursive(int *array, size_t size, int low, int high)
{
	if (low < high)
	{
		int pivot_index = hoare_partition(array, size, low, high);

		/* Recursively sort the two sub-arrays */
		quick_sort_hoare_recursive(array, size, low, pivot_index);
		quick_sort_hoare_recursive(array, size, pivot_index + 1, high);
	}
}

/**
 * quick_sort_hoare - Sorts an array of integers in ascending order
 *                    using the Quick sort algorithm (Hoare partition).
 * @array: Pointer to the array to be sorted.
 * @size: Size of the array.
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_hoare_recursive(array, size, 0, size - 1);
}
