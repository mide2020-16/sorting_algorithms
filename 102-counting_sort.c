#include "sort.h"

/**
 * counting_sort - A sorting algorithm that doesn't use comparison.
 *
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void counting_sort(int *array, size_t size)
{
	int max, *count, j, l, m, *temp;
	size_t i, k, p, n;

	if (array == NULL || size < 2)
		return;

	max = array[0];
	for (i = 0; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	count = malloc(sizeof(int) * (max + 1));
	if (count == NULL)
		return;
	for (j = 0; j <=max; j++)
		count[j] = 0;
	for (k = 0; k < size; k++)
		count[array[k]]++;

	printf("%d", count[0]);
	for (l = 0; l <= max; l++)
		printf(", %d", count[l]);
	printf("\n");
	for (m = 1; m <= max; m++)
		count[m] += count[m - 1];

	temp = malloc(sizeof(int) * size);
	if (temp == NULL)
	{
		free(count);
		return;
	}

	for (n = size - 1; n < size; n--)
	{
		temp[count[array[n]] - 1] = array[n];
		count[array[n]]--;
	}
	for (p = 0; p < size; p++)
		array[p] = temp[p];

	free(temp);
	free(count);
}
