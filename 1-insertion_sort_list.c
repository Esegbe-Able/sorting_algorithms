#include "sort.h"

/**
 *insertion_sort_list - sort a list of integers
 *in a linked list in assceding order
 *
 *@list: pointer to the head pointer of the linked list
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *next, *current, *tmp;

	if (list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;
	while (current != NULL)
	{
		tmp = *list;
		next = current->next;

		while (tmp != current && tmp->n < current->n)
			tmp = tmp->next;

		if (tmp != current)
		{
			current->prev->next = current->next;
			if (current->next != NULL)
				current->next->prev = current->prev;
			if (tmp->prev != NULL)
				tmp->prev->next = current;
			else
				*list = current;

			current->prev = tmp->prev;
			current->next = tmp;
			tmp->prev = current;

		}
		print_list(*list);
		current = next;
	}
}
