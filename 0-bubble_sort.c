#include "sort.h"

/**
 * swap - A function that swaps integers in a sorting algo
 * @x: first integer to be swapped
 * @y: second integer to be swapped
 * Return: void
 */
void swap(int *x, int *y)
{
	int temp = *x;

	*x = *y;
	*y = temp;
}

/**
 * bubble_sort - A function that sorts an array of integers using
 * the bubble sort algorithm
 * @array: pointer to the array
 * @size: size of the array of intgegers
 * Return: void
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int swapped;

	printf("Initial array:\n");
	print_array(array, size);
	printf("\n");

	for (i = 0; i < size - 1; i++)
	{
		swapped = 0;

		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap(&array[j], &array[j + 1]);
				swapped = 1;
			}
		}
		if (swapped)
		{
			printf("step %lu:\n", (unsigned long)(i + 1));
			print_array(array, size);
			printf("\n");
		}
		else
		{
			printf("Array is already sorted. Exiting loop.\n");
			break;
		}
	}
	printf("Final sorted array:\n");
	print_array(array, size);
}
