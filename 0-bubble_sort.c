#include "sort.h"
/**
 * swap_element - This function swaps two integers
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
 * bubble_sort - bubble_sort sorts array of integer
 * @array: array of integers
 * @size: size of the array
 * Description: func prints array
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
