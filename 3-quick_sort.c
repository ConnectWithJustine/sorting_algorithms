#include "sort.h"

/**
 * lomuto_partition - Lomuto partition scheme for Quick sort.
 * @array: Pointer to the array to be partitioned.
 * @size: Size of the array.
 * @low: Index of the low element of the partition.
 * @high: Index of the high element of the partition.
 * Return: Index of the pivot element.
 */
int lomuto_partition(int *array, size_t size, int low, int high)
{
	int pivot = array[high];
	int i = low - 1;
	int j, temp;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			/* Swap array[i] and array[j] */
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			/* Print the array after each swap */
			print_array(array, size);
		}
	}
	/* Swap array[i + 1] and array[high] (pivot) */
	temp = array[i + 1];
	array[i + 1] = array[high];
	array[high] = temp;
	/* Print the array after each swap */
	print_array(array, size);

	return (i + 1);
}

/**
 * quicksort - Recursive function to perform Quick sort.
 * @array: Pointer to the array to be sorted.
 * @size: Size of the array.
 * @low: Index of the low element of the partition.
 * @high: Index of the high element of the partition.
 */
void quicksort(int *array, size_t size, int low, int high)
{
	if (low < high)
	{
		int pivot_index = lomuto_partition(array, size, low, high);

		/* Recursively sort the elements before and after pivot */
		quicksort(array, size, low, pivot_index - 1);
		quicksort(array, size, pivot_index + 1, high);
	}
}

/**
 * quick_sort - Sorts an array of integers in ascending order
 *              using the Quick sort algorithm (Lomuto partition scheme).
 * @array: Pointer to the array to be sorted.
 * @size: Size of the array.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quicksort(array, size, 0, size - 1);
}
