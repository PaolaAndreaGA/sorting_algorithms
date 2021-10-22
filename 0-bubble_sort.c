
#include "sort.h"
/**
 *bubble_sort - function that sorts an array of integers in ascending order
 *@array: Pointer to the beginning of an array
 *@size: array´s size
 *Return: nothing
 */


void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int temp;

	if (size < 2 || !array)
		return;

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				print_array(array, size);
			}
		}
	}
}
