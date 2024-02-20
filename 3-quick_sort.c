#include "sort.h"

/**
 * partition - Function partition the list into two parts.
 * @array: The list to be partitioned.
 * @lo: The lower bound
 * @hi: The higher bound.
 *
 * Return: the pivot index
 */
int partition(int *array, int lo, size_t hi)
{
	int pivot = array[hi];
	int end, start = (lo - 1);

	for (end = lo; end <= (int)hi - 1; end++)
	{
		if (array[end] < pivot)
		{
			start++;
			swap(array, start, end);
		}
	}
	if (array[start + 1] > array[hi])
		swap(array, start + 1, hi);

	return (start + 1);
}

/**
 * quick_sort - Sort a list of integer using quick sort.
 * @array: The array of integer
 * @size: The size of the array.
 *
 * Return: Nothing
 */
void quick_sort(int *array, size_t size)
{
	if (size < 2)
		return;

	quicksort(array, 0, size - 1);
}

/**
 * quicksort - Function that quick sort an array of integers.
 * @array: The array of integers
 * @lo: The lower bound
 * @hi: The higher bound
 *
 * Return: Nothing
 */
void quicksort(int *array, int lo, size_t hi)
{
	int location;

	if (lo < (int)hi)
	{
		location = partition(array, lo, hi);
		print_array(array, hi + 1);
		quicksort(array, lo, location - 1);
		quicksort(array, location + 1, hi);
	}
}

/**
 *swap - swap the the elements at the given indices
 *@arr: pointer to array
 *@idx1: first index
 *@idx2: second index
 *Return: 1 (Success)
 */

int swap(int arr[], int idx1, int idx2)
{
	int tmp;

	tmp = arr[idx1];
	arr[idx1] = arr[idx2];
	arr[idx2] = tmp;
	return (1);
}
