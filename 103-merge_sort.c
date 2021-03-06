#include "sort.h"
/**
 * merge_sort - Function that sends code off to be merge recursively, creates
 * new array to work with
 * @array: pointer to the array
 * @size: size of the array
 *
 * Return: Nothing
 */

void merge_sort(int *array, size_t size)
{
	size_t i;
	int *tmp_arr = NULL;

	if (!array || size < 2)
		return;
	tmp_arr = malloc(size * sizeof(int));
	if (!tmp_arr)
		return;
	for (i = 0; i < size; i++)
		tmp_arr[i] = array[i];
	split(tmp_arr, 0, size, array);
	free(tmp_arr);
}

/**
 * split - Recursive function that splits the array
 * @array: Original array
 * @tmp_arr: Copy of original array
 * @left: Beginning of array
 * @right: End of array
 *
 * Return: Nothing
 */

void split(int *tmp_arr, size_t left, size_t right, int *array)
{
	int middle;

	if (right - left < 2)
		return;
	middle = (right + left) / 2;
	split(array, left, middle, tmp_arr);
	split(array, middle, right, tmp_arr);
	combine(tmp_arr, left, middle, right, array);
}

/**
 * combine - Function that prints and changes values of variables
 * @array: Original array
 * @tmp_arr: Copy of original array
 * @left: Beginning of array
 * @middle: Middle of array
 * @right: End of array
 *
 * Return: Nothing
 */

void combine(int *array, size_t left, size_t middle,
	     size_t right, int *tmp_arr)
{
	size_t i = left,  j = middle, x = 0;

	printf("Merging...\n");
	printf("[left]: ");
	for (x = left; x < middle; x++)
	{
		if (x < middle - 1)
			printf("%d, ", array[x]);
		else
			printf("%d\n", array[x]);
	}
	printf("[right]: ");
	for (x = middle; x < right; x++)
	{
		if (x < right - 1)
			printf("%d, ", array[x]);
		else
			printf("%d\n", array[x]);
	}
	for (x = left; x < right; x++)
	{
		if (i < middle && (j >= right || array[i] <= array[j]))
		{
			tmp_arr[x] = array[i];
			i++;
		}
		else
		{
			tmp_arr[x] = array[j];
			j++;
		}
	}
	printf("[Done]: ");
	for (x = left; x < right; x++)
	{
		if (x < right - 1)
			printf("%d, ", tmp_arr[x]);
		else
			printf("%d\n", tmp_arr[x]);
	}
}
