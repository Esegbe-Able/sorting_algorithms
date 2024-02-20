#include "sort.h"

/**
 * swap_nodes - This function swaps two nodes in a list_tail
 * doubly-linked list.
 * @h: Pointer to the head of the doubly-linked list.
 * @n1: ptr to the first node to swap.
 * @n2: The second node to swap.
 */
void swap_nodes(list_tail **h, list_tail **n1, list_tail *n2)
{
	(*n1)->next = n2->next;
	if (n2->next != NULL)
		n2->next->prev = *n1;
	n2->prev = (*n1)->prev;
	n2->next = *n1;
	if ((*n1)->prev != NULL)
		(*n1)->prev->next = n2;
	else
		*h = n2;
	(*n1)->prev = n2;
	*n1 = n2->prev;
}

/**
 * insertion_sort_list - this function is meant to sort a doubly
 * linked list of integers using the insertion sort algorithm.
 * @list: ptr to the head of a doubly-linked list of integers.
 *
 * Description: Prints the list after each swap.
 */
void insertion_sort_list(list_tail **list)
{
	list_tail *iter, *insert, *tmp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (iter = (*list)->next; iter != NULL; iter = tmp)
	{
		tmp = iter->next;
		insert = iter->prev;
		while (insert != NULL && iter->n < insert->n)
		{
			swap_nodes(list, &insert, iter);
			print_list((const list_tail *)*list);
		}
	}
}
