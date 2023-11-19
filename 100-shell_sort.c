#include "sort.h"

/**
 * shell_sort - A function that sorts an array of integers in ascending
 * order using shell sort algorithm (Knuth sequence)
 * @array: The array of integers to be sorted.
 * @size: Number of integers in the array.
 * Return: void
 */
void shell_sort(int *array, size_t size)
{
	size_t space = 1, i, j;
	int current;

	if (array == NULL || size < 2)
		return;
	/* find the initial gap (space) using Knuth sequence */
	while (space <= size / 3)
		space = space * 3 + 1;

	while (space > 0)
	{
		/* execute insertion sort for elements with a gap */
		for (i = space; i < size; i++)
		{
			current = array[i];
			j = i;

	/* move elements greater than the current element to the right */
			while (j >= space && array[j - space] > current)
			{
				array[j] = array[j - space];
				j -= space;
			}
			array[j] = current;
		}
		/* Print the array after each gap reduvtion */
		print_array(array, size);

		/* find the next gap */
		space = (space - 1) / 3;
	}
}
