#include "sort.h"

/**
 * swap - A function that swaps two integers in an array
 * @x: First integer to be swapped
 * @y: Second integer to be swapped
 * Return: void.
 */
void swap(int *x, int *y)
{
	int tmp = *x;

	*x = *y;
	*y = tmp;
}

/**
 * lom_part - A Nico lomuto partition scheme to partition the array.
 * @array: The array to be partitioned.
 * @low: first index of the partition.
 * @high: last index of the partition.
 * @size: Number of elements in the array.
 * Return: Index of the pivot after partitioning
 */
size_t lom_part(int *array, ssize_t low, ssize_t high, size_t size)
{
	int pivot = array[high];
	ssize_t i = low - 1;
	ssize_t j;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (i != j)
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
		}
	}
	if (array[i + 1] != array[high])
	{
		swap(&array[i + 1], &array[high]);
		print_array(array, size);
	}
	return (i + 1);
}
/**
 * sortfast - A function that quickly sorts array recursively.
 * @array: The array to be sorted.
 * @low: First or begining index of the partition.
 * @high: Last or ending index of the partition
 * @size: number of elements in the array.
 * Return: void.
 */
void sortfast(int *array, ssize_t low, ssize_t high, size_t size)
{
	if (low < high)
	{
		ssize_t pivot = lom_part(array, low, high, size);

		sortfast(array, low, pivot - 1, size);
		sortfast(array, pivot + 1, high, size);
	}
}

/**
 * quick_sort - A function that sorts integers in ascending order
 * @array: The array to be sorted
 * @size: Number of elements in the array.
 * Return: void.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	sortfast(array, 0, size - 1, size);
}
