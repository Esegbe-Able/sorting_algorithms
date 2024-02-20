#include "sort.h"

void swap_element(int *a, int *b);
int lomuto_partition(int *array, size_t size, int left, int right);
void lomuto_sort(int *array, size_t size, int left, int right);
void quick_sort(int *array, size_t size);

/**
 * swap_element - func swaps dual ints
 * @a: The 1st integer
 * @b: The 2nd integer
 */
void swap_element(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * lomuto_partition - Reorders a subset of an array of integers.
 * @array: array of integers.
 * @size: size of the array.
 * @left: starting index of subset
 * @right: ending index o fsubset
 * Return: The final partition index.
 */

int lomuto_partition(int *array, size_t size, int left, int right)
{
	int *pivot, above, below;

	pivot = array + right;
	for (above = below = left; below < right; below++)
	{
		if (array[below] < *pivot)
		{
			if (above < below)
			{
				swap_element(array + below, array + above);
				print_array(array, size);
			}
			above++;
		}
	}

	if (array[above] > *pivot)
	{
		swap_element(array + above, pivot);
		print_array(array, size);
	}

	return (above);
}

/**
 * lomuto_sort - uses quicksort algor
 * @array: An array of integer
 * @size: size of the array.
 * @left: starting index of array
 * @right: ending index of array par
 * Description: Uses Lomuto partition scheme.
 */
void lomuto_sort(int *array, size_t size, int left, int right)
{
	int part;

	if (right - left > 0)
	{
		part = lomuto_partition(array, size, left, right);
		lomuto_sort(array, size, left, part - 1);
		lomuto_sort(array, size, part + 1, right);
	}
}

/**
 * quick_sort - func sorts array of integers in ascending
 * @array: array of integers.
 * @size: size of array.
 * Description: Prints array after swap
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}
