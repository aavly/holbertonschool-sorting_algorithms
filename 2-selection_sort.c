#include "sort.h"

/**
 * selection_sort - sorts an array of ints in ascending order
 *			using the Selection sort algorithm.
 *
 * @array: array to be sorted.
 * @size: size of the array.
 */

void selection_sort(int *array, size_t size)
{
	size_t a, b, min_index;
	int temp;

	if (array == NULL || size < 2)
		return;

	for (a = 0; a < size - 1; a++)
	{
		min_index = a;

		for (b = a + 1; b < size; b++)
		{
			if (array[b] < array[min_index])
				min_index = b;
		}

		if (min_index != a)
		{
			temp = array[a];
			array[a] = array[min_index];
			array[min_index] = temp;

			print_array(array, size);
		}
	}
}
