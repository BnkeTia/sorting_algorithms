#include "sort.h"

/**
 * maxV_find - A function that finds the max value in an array of integers.
 * @array: The array of integers.
 * @size: The size of the array.
 * Return: maxV, The maximum integer in the array.
 */
int maxV_find(int *array, int size)
{
	int maxV, i;

	for (maxV = array[0], i = 1; i < size; i++)
	{
		if (array[i] > maxV)
			maxV = array[i];
	}

	return (maxV);
}

/**
 * counting_sort - A function that sorts an array of integers in ascending
 * order using the counting sort algorithm.
 * @array: The array of integers to be sorted.
 * @size: The number of elements in the array.
 *Return: void
 */
void counting_sort(int *array, size_t size)
{
	int *count, *isSorted, maxiV, i;

	if (array == NULL || size < 2)
		return;

	isSorted = malloc(sizeof(int) * size);
	if (isSorted == NULL)
		return;
	maxiV = maxV_find(array, size);
	count = malloc(sizeof(int) * (maxiV + 1));
	if (count == NULL)
	{
		free(isSorted);
		return;
	}

	for (i = 0; i < (maxiV + 1); i++)
		count[i] = 0;
	for (i = 0; i < (int)size; i++)
		count[array[i]] += 1;
	for (i = 0; i < (maxiV + 1); i++)
		count[i] += count[i - 1];
	print_array(count, maxiV + 1);

	for (i = 0; i < (int)size; i++)
	{
		isSorted[count[array[i]] - 1] = array[i];
		count[array[i]] -= 1;
	}

	for (i = 0; i < (int)size; i++)
		array[i] = isSorted[i];

	free(isSorted);
	free(count);
}
