#include "sort.h"

/**
 * swap - Swaps two integers.
 * @a: Pointer to the first integer.
 * @b: Pointer to the second integer.
 *
 * Description: This function swaps the values of two integers.
 */
void swap(int *a, int *b) {
  int temp;

  temp = *a;
  *a = *b;
  *b = temp;
}

/**
 * partition - Partitions the array using the last element as pivot.
 * @array: Pointer to the array to be partitioned.
 * @low: Index of the first element of the array.
 * @high: Index of the last element of the array.
 *
 * Description: This function partitions the array into two sub-arrays
 * such that elements smaller than the pivot are placed
 * to the left, and elements greater than or equal to
 * the pivot are placed to the right.
 *
 * Return: The index of the pivot element after partitioning.
 */
int partition(int *array, int low, int high) {
  int pivot, i, j;

  pivot = array[high];
  i = low - 1;

  for (j = low; j < high; j++) {
    if (array[j] < pivot) {
      i++;
      swap(&array[i], &array[j]);
      print_array(array, high + 1);
    }
  }

  swap(&array[i + 1], &array[high]);
  return (i + 1);
}

/**
 * quick_sort_helper - Recursively sorts the array using Quick Sort algorithm.
 * @array: Pointer to the array to be sorted.
 * @low: Index of the first element of the array.
 * @high: Index of the last element of the array.
 *
 * Description: This function recursively applies Quick Sort algorithm
 * to sort the elements of the array in ascending order.
 */
void quick_sort_helper(int *array, int low, int high) {
  int pi;

  if (low < high) {
    pi = partition(array, low, high);

    quick_sort_helper(array, low, pi - 1);
    quick_sort_helper(array, pi + 1, high);
  }
}

/**
 * quick_sort - Sorts an array of integers in ascending order using Quick Sort.
 *
 * @array: Pointer to the array to be sorted.
 * @size: Size of the array.
 *
 * Description: This function sorts the elements of the array in ascending order
 * using the Quick Sort algorithm with Lomuto partition scheme.
 * It prints the array after each swap operation.
 */
void quick_sort(int *array, size_t size) {
  if (array == NULL || size < 2)
    return;

  quick_sort_helper(array, 0, size - 1);
}
