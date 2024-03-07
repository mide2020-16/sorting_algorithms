#include "sort.h"


/**
 * swap_nodes - Swaps two nodes in a doubly linked list
 * @list: Double pointer to the head of the linked list
 * @node1: Pointer to the first node to swap
 * @node2: Pointer to the second node to swap
 */
void swap_nodes(listint_t **list, listint_t **node1, listint_t **node2)
{
	listint_t *temp;

	temp = (*node1)->prev;

	if (temp != NULL)
	{
		temp->next = *node2;
	}
	else
	{
		*list = *node2;
	}

	(*node2)->prev = (*node1)->prev;
	(*node1)->prev = *node2;
	(*node1)->next = (*node2)->next;

	if ((*node2)->next != NULL)
	{
		(*node2)->next->prev = *node1;
	}

	(*node2)->next = *node1;
}


/**
 * cocktail_sort_list - Sorts a doubly linked list of integers
 * ascending order using the Cocktail shaker sort algorithm
 * @list: Double pointer to the head of the linked list
 */
void cocktail_sort_list(listint_t **list)
{
	int swapped;
	listint_t *current;

	if (*list == NULL || list == NULL || (*list)->next == NULL)
		return;
	do {
		swapped = 0;
		for (current = *list; current->next != NULL; current = current->next)
		{
			if (current->n > current->next->n)
			{
				swap_nodes(list, &current, &(current->next));
				swapped = 1;
				print_list(*list);
			}
		}
		if (swapped == 0)
			break;
		swapped = 0;
		for (; current->prev != NULL; current = current->prev)
		{
			if (current->n < current->prev->n)
			{
				swap_nodes(list, &(current->prev), &current);
				swapped = 1;
				print_list(*list);
			}
		}
		if (swapped == 0)
			break;
		swapped = 0;
	} while (swapped);
}
