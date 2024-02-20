#include "sort.h"

/**
 * swap_element - Func swaps two ints
 * @a: 1st integer
 * @b: 2nd integer
 */

void swap_element(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * shell_sort - Sort array of integers
 * @array: array of integers
 * @size: size of array
 * Description: Uses interval sequence
 */

void shell_sort(int *array, size_t size)
{
	size_t gap, i, j;

	if (array == NULL || size < 2)
		return;

	for (gap = 1; gap < (size / 3);)
		gap = gap * 3 + 1;

	for (; gap >= 1; gap /= 3)
	{
		for (i = gap; i < size; i++)
		{
			j = i;
			while (j >= gap && array[j - gap] > array[j])
			{
				swap_element(array + j, array + (j - gap));
				j -= gap;
			}
		}
		print_array(array, size);
	}
}
