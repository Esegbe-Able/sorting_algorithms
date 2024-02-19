#include <stdio.h>
#include "sort.h"

/**
 * print_list - This function prints a list of integers
 *
 * @list: lit to print
 */
void print_list(const listint_t *list)
{
	int j;

	j = 0;
	while (list)
	{
		if (j > 0)
			printf(", ");
		printf("%d", list->n);
		++j;
		list = list->next;
	}
	printf("\n");
}
