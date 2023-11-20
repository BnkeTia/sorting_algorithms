#include "sort.h"

/**
 * swapN - A function that swap nodes
 * @list: a pointer to a pointer to head of the list
 * @x: pointer to the fist element to be swapped
 * @y: pointer to the second element to be swapped.
 * Return: void.
 */
void swapN(listint_t **list, listint_t *x, listint_t *y)
{
	if (x->prev)
		x->prev->next = y;
	if (y->next)
		y->next->prev = x;
	if (x->next == y)
	{
		x->next = y->next;
		y->prev = x->prev;
		y->next = x;
		x->prev = y;
	}
	else
	{
		listint_t *temp = x->prev;

		x->prev = y->prev;
		y->prev = temp;

		temp = x->next;
		x->next = y->next;
		y->next = temp;

		if (x->prev)
			x->prev->next = x;
		if (y->prev)
			y->prev->next = y;

		if (x->next)
			x->next->prev = x;
		if (y->next)
			y->next->prev = y;
	}
	if (!x->prev)
		*list = x;
	else if (!y->prev)
		*list = y;
}

/**
 * cocktail_sort_list - A function that sorts a doubly linked list of integers
 * in ascending order using the cocktail shaker sort algorithm.
 * @list: A pointer to a pointer to the head of the doubly linked list,
 * Return: void.
 */
void cocktail_sort_list(listint_t **list)
{
	int isSorted;
	listint_t *p;
	listint_t *left, *right = NULL;

	if (*list == NULL)
		return;
	do {
		isSorted = 0;
		p = *list;

		while (p->next != right)
		{
			if (p->n > p->next->n)
			{
				swapN(list, p, p->next);
				isSorted = 1;
				print_list(*list);
			}
			p = p->next;
		}
		if (!isSorted)
			break;
		isSorted = 0;
		right = p;

		while (p->prev != left)
		{
			if (p->n < p->prev->n)
			{
				swapN(list, p->prev, p);
				isSorted = 1;
				print_list(*list);
			}
			p = p->prev;
		}
		left = p;
	} while (isSorted);
}
