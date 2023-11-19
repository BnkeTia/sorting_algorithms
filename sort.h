#ifndef BISKIT_SORT_H
#define BISKIT_SORT_H

/* Needed standard library header files */
#include <stdlib.h>
#include <stdio.h>

/* Type definition or Data structure neede */

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

/* Function prototype of given functions */
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);

/* Function prototypes of Actual sorting Algorithms */
	/* Bubbly sort prototypes */
void bubble_sort(int *array, size_t size);
void swap(int *x, int *y);

	/* Insertion sort prototype */
void insertion_sort_list(listint_t **list);

	/* Selection sort prototype */
void selection_sort(int *array, size_t size);


#endif /*BISKIT_SORT_H */
