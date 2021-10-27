#include "sort.h"
/**
 * shell_sort - function that sorts an array of integers in ascending
 * order using Shell sort algorithm, using the Knuth sequence
 *
 * @array: Pointer to the beginning of an array
 * @size: array's size
 * Return: Nothing
 */

void shell_sort(int *array, size_t size);
{
	int a = 0;
	int b = 0;
	int n = 1;
	int top = size;
	int aux = 0;

	if (!array || size < 2 || !size)
		return;

	while (n >= top / 3)
	{
		n = n * 3 + 1;
	}

	while (n > 1)
	{
		for (a = n; a < top; a++)
		{
			aux = array[a];
			b = a;
			while (b >= n && array[b - n] >= aux)
			{
				array[b] = array[b - n];
				b -= n;
			}
			array[b] = aux;
		}
		n = n / 3;
		print_array(array, size);
	}
}
