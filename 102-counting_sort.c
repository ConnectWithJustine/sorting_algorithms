#include "sort.h"

/**
 * counting_sort - Sorts an arrary of integers in ascending order
 * using the counting sort algorithm
 * @array: Pointer to the array to be sorted
 * @size: Size of the array
 */
void counting_sort(int *array, size_t size)
{
	int *counting_array, *output_array, max_value = 0, min_value = 0;
	size_t i, range;

	if (array == NULL || size < 2)
		return;

	/* find the maximum and minimum value */
	for (i = 0; i < size; i++)
	{
		if (array[i] > max_value)
			max_value = array[i];
		if (array[i] < min_value)
			min_value = array[i];
	}

	/* Calculate the range (k) and allocate memory */
	range = max_value - min_value + 1;
	counting_array = malloc(sizeof(int) * range);
	if (counting_array == NULL)
		return;

	/* Initialize counting array with zeros */
	for (i = 0; i < range; i++)
		counting_array[i] = 0;

	/* count the occurrences of each element in the input array */
	for (i = 0; i < size; i++)
		counting_array[array[i] - min_value]++;

	/* Calculate the prefix sum of the counting array */
	for (i = 1; i < range; i++)
		counting_array[i] += counting_array[i - 1];

	print_array(counting_array, max_value + 1);

	/* Create the sorted output array based on the counting array */
	output_array = malloc(sizeof(int) * size);
	if (output_array == NULL)
	{
		free(counting_array);
		return;
	}

	for (i = size - 1; i < size; i--)
	{
		output_array[counting_array[array[i] - min_value] - 1] = array[i];
		counting_array[array[i] - min_value]--;
	}

	/* Copy the sorted output back to the original array */
	for (i = 0; i < size; i++)
		array[i] = output_array[i];

	/* Free dynamically allocated memory */
	free(counting_array);
	free(output_array);
}
