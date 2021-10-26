#include "sort.h"
/**
 * quick_sort - function that sorts an array of integers in ascending
 * order using the Quick sort algorithm
 * @array: pointer to integer array
 * @size: array's size
 *
 * Return: Nothing
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	realqs(array, 0, size - 1, size);
}
/**
 * realqs - recursive function for sorting array
 *
 * @array: pointer to integer array
 * @start: starting index
 * @end: ending index
 * @size: array's size
 *
 * Return: Nothing
 */
void realqs(int *array, int start, int end, size_t size)
{
	int pivot;

	if (start < end)
	{
		pivot = partition(array, start, end, size);
		realqs(array, start, pivot - 1, size);
		realqs(array, pivot + 1, end, size);
	}
}
/**
 * partition - partitions array, swaps values, and prints
 *
 * @array: pointer to integer array
 * @start: starting index
 * @end: ending index
 * @size: array's size
 *
 * Return: Nothing
 */
int partition(int *array, size_t start, size_t end, size_t size)
{
	size_t i = start - 1;
	size_t j;
	int temp = 0;
	int aux = 0;
	size_t pos = 0;

	for (j = start; j < end; j++)
	{
		if (array[j] < array[end])
		{
			i++;
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			if (array[j] != array[i])
				print_array(array, size);
		}
	}
	i++;
	pos = i;
	aux = array[i];
	array[i] = array[end];
	array[end] = aux;
	if (array[j] != array[i])
		print_array(array, size);
	return (pos);
}
