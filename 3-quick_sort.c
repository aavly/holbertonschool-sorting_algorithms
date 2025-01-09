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
 * @array: array to partition.
 * @low: starting index of the partition.
 * @high: ending index of the partition.
 * @size: total size of array.
 *
 * Return: the index where the pivot element is placed.
 */

int partition(int *array, int low, int high, size_t size)
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
			if (a != b)
			{
				swap(&array[a], &array[b]);
				print_array(array, size);
			}
		}
	}

	if (a + 1 != high)
	{
		swap(&array[a + 1], &array[high]);
		print_array(array, size);
	}

	return (a + 1);
}

/**
 * quick_sort_recursive - recursively sorts the array using quick sort.
 *
 * @array: array to sort.
 * @low: starting index of array.
 * @high: ending index of array.
 * @size: total size of the array.
 */

void quick_sort_recursive(int *array, int low, int high, size_t size)
{
	int pi;

	if (low < high)
	{
		pi = partition(array, low, high, size);

		quick_sort_recursive(array, low, pi - 1, size);
		quick_sort_recursive(array, pi + 1, high, size);
	}
}

/**
 * quick_sort - sorts an array of int in ascending order.
 *
 * @array: array to sort.
 * @size: size of array.
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_recursive(array, 0, size - 1, size);
}
