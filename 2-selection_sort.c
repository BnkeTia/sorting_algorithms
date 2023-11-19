#include "sort.h"

/**
 * selection_sort - A function that sorts an array of integers in
 * ascending order using the selection sort algorithm
 * @array: Pointer to the array of integers.
 * @size: size or number of elements in the array.
 * Return: void
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j;
	size_t minI; /* Declaration of the index of the minimum element */
	int temp;

	/* checking if array is empty or has less than 2 elements */
	if (array == NULL || size < 2)
		return;

	/*iterate through the array regardless */
	for (i = 0; i < size - 1; i++)
	{
		minI = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[minI])
				minI = j;
		}

		if (minI != i)
		{
			temp = array[i];
			array[i] = array[minI];
			array[minI] = temp;
			print_array(array, size);
		}
	}
}
