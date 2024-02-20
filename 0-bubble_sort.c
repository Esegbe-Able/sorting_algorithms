#include "sort.h"
/**
 * swap_element - This function is meant to swap integers
 * @a: First integer
 * @b: Second integer
 */

void swap_element(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
/**
 * bubble_sort - It sorts arrays of integer values
 * @array: array containing int values
 * @size: size of array
 * Description: prints array of int vals
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, len = size;
	bool changed = false;

	if (array == NULL || size < 2)
		return;

	while (changed == false)
	{
		changed = true;
		for (i = 0; i < len - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				swap_element(array + i, array + i + 1);
				print_array(array, size);
				changed = false;
			}
		}
		len--;
	}
}
