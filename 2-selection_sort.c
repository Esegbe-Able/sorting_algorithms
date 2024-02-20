#include "sort.h"

/**
 * swap_element - It swaps two integers in an array.
 * @a: first int val
 * @b: second int val
 */
void swap_element(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * selection_sort - this function sorts an array of
 * integer values in ascending order
 * @array: array of integer values.
 * @size: size of the array.
 * Description: prints array
 */

void selection_sort(int *array, size_t size)
{
	int *min;
	size_t i, j;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min = array + i;
		for (j = i + 1; j < size; j++)
			min = (array[j] < *min) ? (array + j) : min;

		if ((array + i) != min)
		{
			swap_element(array + i, min);
			print_array(array, size);
		}
	}
}
