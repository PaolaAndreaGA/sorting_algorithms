#include "sort.h"
/**
 * selection_sort -function that sorts an array of integers in ascending
 * order using the Selection sort algorithm
 *
 * @array: Pointer to the beginning of an array
 * @size: array's size
 * Return: Nothing
 */

void selection_sort(int *array, size_t size)
{
	size_t a, b, aux, min;


	for (a = 0; a < size; a++)
	{
		min = a;
		for (b = a + 1; b < size; b++)
		{
			if (array[b] < array[min])
			{
				min = b;
			}
		}
		if (min == a)
			continue;
		aux = array[a];
		array[a] = array[min];
		array[min] = aux;
		print_array(array, size);
	}
}
