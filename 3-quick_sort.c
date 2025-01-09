#include "sort.h"

/**
 * swap - swaps two integers in an array.
 *
 * @a: pointer to first integer.
 * @b: pointer to second integer.
 */

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * partition: partitions the array for quick sort by
 *		using the Lomuto scheme.
 *
 * @array: array to the partition.
 * @low: starting index of the partition.
 * @high: ending indec of the partition.
 * @size: size fo the array (used for printing).
 *
 * Return: the index where the pivor element is placed.
 */

int partition(int *array, int low, int high)
{
	int pivot;
	int a, b;

	pivot = array[high];
	a = low - 1;


	for (b = low; b < high; b++)
	{
		if (array[b] < pivot)
		{
			a++;
			swap(&array[a], &array[b]);
		}
	}

	swap(&array[a + 1], &array[high]);

	return (a + 1);
}

/**
 * quick_sort_recursive - recursively sorts the array using quick sort.
 *
 * @array: array to sort.
 * @low: starting index of array.
 * @high: ending index of array.
 * @size: size of array.
 */

void quick_sort_recursive(int *array, int low, int high)
{
	int pi;

	if (low < high)
	{
		pi = partition(array, low, high);

		quick_sort_recursive(array, low, pi - 1);
		quick_sort_recursive(array, pi + 1, high);
	}

}

/**
 * quick_sort - sorts an array of itns in ascending order.
 *
 * @array: array to sort.
 * @size: size of array.
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_recursive(array, 0, size - 1);
}
