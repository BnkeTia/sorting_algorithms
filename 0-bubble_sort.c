#include "sort.h"

/**
 * bubble_sort - A function that sorts an array of integers using
 * the bubble sort algorithm
 * @array: pointer to the array
 * @size: size of the array of integers
 * Return: void
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int isSorted, temp;

	/* verify if array is empty or has only 2 elements */
	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		isSorted = 0;
		/* iterate through the array */
		for (j = 0; j < size - i - 1; j++)
		{
			/* setting condition to swap elements */
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				/* Print array after each swap */
				print_array(array, size);
				isSorted = 1;
			}
		}
		if (isSorted == 0)
			break;
	}
}
