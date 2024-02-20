#include "sort.h"
void swap_element(int *a, int *b);
int hoare_partition(int *array, size_t size, int left, int right);
void hoare_sort(int *array, size_t size, int left, int right);
void quick_sort_hoare(int *array, size_t size);

/**
 * swap_element - Swap integers in array
 * @a: fir integer
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
 * hoare_partition - subset of an array of integers
 * @array: array of integers
 * @size: size of array
 * @left: starting index of the subset
 * @right: ending index of subset
 * Return: tofinal partition index
 * Description: prints array after swap
 */

int hoare_partition(int *array, size_t size, int left, int right)
{
	int pivot, above, below;

	pivot = array[right];
	for (above = left - 1, below = right + 1; above < below;)
	{
		do {
			above++;
		} while (array[above] < pivot);
		do {
			below--;
		} while (array[below] > pivot);

		if (above < below)
		{
			swap_element(array + above, array + below);
			print_array(array, size);
		}
	}

	return (above);
}
/**
 * hoare_sort - quicksort algorithm
 * @array: array of integers
 * @size: size of the array.
 * @left: starting index of array parti
 * @right: ending index of array
 * Description: hoare partition scheme
 */

void hoare_sort(int *array, size_t size, int left, int right)
{
	int part;

	if (right - left > 0)
	{
		part = hoare_partition(array, size, left, right);
		hoare_sort(array, size, left, part - 1);
		hoare_sort(array, size, part, right);
	}
}

/**
 * quick_sort_hoare - fuc sorts array of ints in ascend order
 * @array: array of integers
 * @size: size of the array.
 * Description: Prints array after swap
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	hoare_sort(array, size, 0, size - 1);
}
