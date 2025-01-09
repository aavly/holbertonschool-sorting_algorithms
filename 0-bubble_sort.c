#include "sort.h"

/**
 * bubble_sort - sorts array of ints in ascending order
 *		using Bubble sort algorithm.
 *
 * @array: array to be used.
 * @size: size of array.
 */

void bubble_sort(int *array, size_t size)
{
	size_t a, b;
	int temp;

	if (array == NULL || size < 2)
		return;

	for (a = 0; a < size - 1; a++)
	{
		for (b = 0; b < size - a - 1; b++)
		{
			if (array[b] > array[b + 1])
			{
				temp = array[b];
				array[b] = array[a + 1];
				array[b + 1] = temp;

				print_array(array, size);
			}
		}
	}
}
