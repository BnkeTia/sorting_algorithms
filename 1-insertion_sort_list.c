#include "sort.h"

/**
 * insertion_sort_list - A function that sorts a doubly linked list
 * of intergers in ascending orde using insertion sort.
 * @list: A pointer to a pointer to the head of the list
 * Return: void.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *temp;


	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;
	while (current != NULL)
	{
		temp = current;
		current = current->next;

		while (temp->prev != NULL && temp->n < temp->prev->n)
		{
			temp->prev->next = temp->next;
			if (temp->next != NULL)
				temp->next->prev = temp->prev;

			temp->next = temp->prev;
			temp->prev = temp->next->prev;
			temp->next->prev = temp;

			if (temp->prev == NULL)
				*list = temp;
			else
				temp->prev->next = temp;

			print_list(*list);
		}
	}
}
