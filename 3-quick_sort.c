#include "sort.h"

void swap_element(int *a, int *b);
int lomuto_partition(int *array, size_t size, int left, int right);
void lomuto_sort(int *array, size_t size, int left, int right);
void quick_sort(int *array, size_t size);

/**
 * swap_element - this function swaps two integer values
 * @a: The 1st integer
 * @b: second integer
 */
void swap_element(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * lomuto_partition - The function reorders a subset of an array
 * of integer values.
 * @array: array containing int values.
 * @size: size of the array.
 * @left: starting index of subset
 * @right: ending index o fsubset
 * Return: final partition index.
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
 * lomuto_sort - uses quicksort algorithm to sort
 * @array: array of integer values
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
 * quick_sort - quick_sort function sorts array of integer values
 * in ascending
 * @array: array containing integer values.
 * @size: size of the array.
 * Description: Prints array after swap
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}
