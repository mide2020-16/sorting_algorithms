#include "sort.h"

/**
 * bubble_sort - Sorts an array of integers in ascending order using the Bubble sort algorithm
 * @array: Pointer to the array to be sorted
 * @size: Size of the array
 *
 * Return: void
 */
void bubble_sort(int *array, size_t size)
{
    unsigned int i, j, k;
    int temp, swapped;

    for (i = 0; i < size - 1; i++)
    {
        swapped = 0;
        for (j = 0; j < size - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;

                swapped = 1;
            }
        }

        if (!swapped)
            break;

        for (k = 0; k < size; k++)
        {
            printf("%d", array[k]);
            if (k < size - 1)
                printf(", ");
        }

        printf("\n");
    }
}
