#include "sort.h"

void swap_node_ahead(list_tail **list, list_tail **tail, list_tail **shaker);
void swap_node_behind(list_tail **list, list_tail **tail, list_tail **shaker);
void cocktail_sort_list(list_tail **list);

/**
 * swap_node_ahead - Function is meant to swap node
 * @list: Ptr to head of doubly-linked list
 * @tail: Ptr to the tail of the doubly-linked list
 * @shaker: pointer to swapping node
 */

void swap_node_ahead(list_tail **list, list_tail **tail, list_tail **shaker)
{
	list_tail *tmp = (*shaker)->next;

	if ((*shaker)->previous != NULL)
		(*shaker)->previous->next = tmp;
	else
		*list = tmp;
	tmp->previous = (*shaker)->previous;
	(*shaker)->next = tmp->next;
	if (tmp->next != NULL)
		tmp->next->previous = *shaker;
	else
		*tail = *shaker;
	(*shaker)->previous = tmp;
	tmp->next = *shaker;
	*shaker = tmp;
}

/**
 * swap_node_behind - this function swaps node
 * @list: ptr to the head of the node
 * @tail: ptr to the tail of the node
 * @shaker: pointer to current swapping node
 */

void swap_node_behind(list_tail **list, list_tail **tail, list_tail **shaker)
{
	list_tail *tmp = (*shaker)->previous;

	if ((*shaker)->next != NULL)
		(*shaker)->next->previous = tmp;
	else
		*tail = tmp;
	tmp->next = (*shaker)->next;
	(*shaker)->previous = tmp->previous;
	if (tmp->previous != NULL)
		tmp->previous->next = *shaker;
	else
		*list = *shaker;
	(*shaker)->next = tmp;
	tmp->previous = *shaker;
	*shaker = tmp;
}

/**
 * cocktail_sort_list - This functions work is to sort integer values
 * @list: pointer to head of list_tail doubly-linked list
 */
void cocktail_sort_list(list_tail **list)
{
	list_tail *tail, *shaker;
	bool shaken_not_stirred = false;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (tail = *list; tail->next != NULL;)
		tail = tail->next;

	while (shaken_not_stirred == false)
	{
		shaken_not_stirred = true;
		for (shaker = *list; shaker != tail; shaker = shaker->next)
		{
			if (shaker->n > shaker->next->n)
			{
				swap_node_ahead(list, &tail, &shaker);
				print_list((const list_tail *)*list);
				shaken_not_stirred = false;
			}
		}
		for (shaker = shaker->previous; shaker != *list;
				shaker = shaker->previous)
		{
			if (shaker->n < shaker->previous->n)
			{
				swap_node_behind(list, &tail, &shaker);
				print_list((const list_tail *)*list);
				shaken_not_stirred = false;
			}
		}
	}
}
