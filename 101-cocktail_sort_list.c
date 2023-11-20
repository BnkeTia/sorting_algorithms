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
	{
		x->prev->next = y;
	}
	else
		*list = y;

	if (y->next)
	{
		y->next->prev = x;
	}

	x->next = y->next;
	y->prev = x->prev;
	y->next = x;
	x->prev = y;
}


/**
 * cocktail_sort_list - A function that sorts a doubly linked list of integers
 * in ascending order using the cocktail shaker sort algorithm.
 * @list: A pointer to a pointer to the head of the doubly linked list,
 * Return: void.
 */
void cocktail_sort_list(listint_t **list)
{
	int isSorted = 1;
	listint_t *p;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	while (isSorted)
	{
		isSorted = 0;
		p = *list;

		while (p->next)
		{
			if (p->n > p->next->n)
			{
				swapN(list, p, p->next);
				isSorted = 1;
				print_list(*list);
			}
			else
				p = p->next;
		}
		if (!isSorted)
			break;
		isSorted = 0;
		p = p->prev;

		while (p->prev)
		{
			if (p->n < p->prev->n)
			{
				swapN(list, p->prev, p);
				isSorted = 1;
				print_list(*list);
			}
			else
				p = p->prev;
		}
	}
}
