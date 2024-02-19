#include "sort.h"

/**
 * swap_element - func swap two integers in an array.
 * @a: the first integer
 * @b: The second integer
 */
void swap_element(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * selection_sort - func dort an array of integers in ascending order
 * @array: array of integers.
 * @size: size of the array.
 * Description: Prints array after swap
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
