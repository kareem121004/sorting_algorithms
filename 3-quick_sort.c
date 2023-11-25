#include "sort.h"

/**
 * swap - swap values
 * @array: the int array
 * @size: size of the array
 * @a: a
 * @b: b
 * Return: void
 */

void swap(int *array, size_t size, int *a, int *b)
{
	if (*a != *b)
	{
		*a = *a + *b;
		*b = *a - *b;
		*a = *a - *b;
		print_array((const int *)array, size);
	}
}

/**
 * partition - array partition
 * @array: array to sort
 * @size: array size
 * @low: low position
 * @high: high position
 * Return: int pivot index
*/

int partition(int *array, size_t size, size_t low, size_t high)
{
    int pivot = array[high];
    size_t i, j;

    for (i = j = low; j < high; j++)
    {
        if (array[j] < pivot)
            swap(array, size, &array[j], &array[i++]);
    }
    swap(array, size, &array[i], &array[high]);
    return (i);
}

/**
 * qs - sorts an array of integers recursively
 * @array: array to sort
 * @size: array size
 * @low: low position
 * @high: high position
*/

void qs(int *array, size_t size, int low, int high)
{

    if (low < high)
    {
        size_t pivot = partition(array, size, low, high);
        qs(array, size, low, pivot - 1);
        qs(array, size, pivot + 1, high);
    }
}

/**
 * quick_sort - sorts an array of integers using the Quick
 * sort algorithm in ascending order
 * @array: array to sort
 * @size: array size
 */
void quick_sort(int *array, size_t size)
{
    qs(array, size, 0, size - 1);
}
