#include "sort.h"

/**
 * selection_sort - Sorts an array of integers in ascending order
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 *
 * Description: Implements the selection sort algorithm
*/

void selection_sort(int *array, size_t size)
{
	int temp;
	int i, j, imin;

	if (!array || !size)
		return;

	for (i = 0; i < size - 1; i++)
	{
		imin = i;

		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[imin])
				imin = j;
		}

		if (array[i] > array[imin])
		{
			temp = array[i];
			array[i] = array[imin];
			array[imin] = temp;
			print_array(array, size);
		}
	}
}
