#include "sort.h"

/**
 * selection_sort - Sorts an array of integers in ascending order
 * using the Selection sort algorithm
 * @array: Pointer to the array to be sorted
 * @size: Size of the array
 * Return: void
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min_index;
	int temp;

	/* Check if the array is NULL or has less than 2 elements */
	if (array == NULL || size < 2)
		return;

	/* Iterate over the array to select the smallest element */
	for (i = 0; i < size - 1; i++)
	{
		/* Assume the current index has the smallest element */
		min_index = i;

		/* Find the index of the smallest element in the unsorted part */
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_index])
				min_index = j;
		}

		/* Swap the smallest element with the current index, if necessary */
		if (min_index != i)
		{
			temp = array[i];
			array[i] = array[min_index];
			array[min_index] = temp;

			/* Print the array after each swap */
			print_array(array, size);
		}
	}
}
