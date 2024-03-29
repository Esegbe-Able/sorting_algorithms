#include "sort.h"
void swap_element(int *a, int *b);
void max_heapify(int *array, size_t size, size_t base, size_t root);
void heap_sort(int *array, size_t size);
/**
 * swap_element - func swaps two ints
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
 * max_heapify - this function turns binary tree into binary heap
 * @array: array of integer values
 * @size: size of array
 * @base: index of the base row of tree
 * @root: root node
 */

void max_heapify(int *array, size_t size, size_t base, size_t root)
{
	size_t left, right, large;

	left = 2 * root + 1;
	right = 2 * root + 2;
	large = root;

	if (left < base && array[left] > array[large])
		large = left;
	if (right < base && array[right] > array[large])
		large = right;

	if (large != root)
	{
		swap_element(array + root, array + large);
		print_array(array, size);
		max_heapify(array, size, base, large);
	}
}

/**
 * heap_sort - Sort an array of integer values in ascending order
 * @array: array of integers
 * @size: size of array
 * Description: prints array after each swap
 */

void heap_sort(int *array, size_t size)
{
	int i;

	if (array == NULL || size < 2)
		return;

	for (i = (size / 2) - 1; i >= 0; i--)
		max_heapify(array, size, size, i);

	for (i = size - 1; i > 0; i--)
	{
		swap_element(array, array + i);
		print_array(array, size);
		max_heapify(array, size, i, 0);
	}
}
