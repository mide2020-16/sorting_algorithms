#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked
 * @list: Double pointer to the head of the linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *temp, *prev;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;
  	while (current != NULL)
	{
		temp = current->next;
		prev = current->prev;

		while (prev != NULL && prev->n > current->n)
		{
			/* Swap current and prev nodes */
			if (prev->prev != NULL)
				prev->prev->next = current;
			if (current->next != NULL)
				current->next->prev = prev;

			prev->next = current->next;
			current->prev = prev->prev;
			prev->prev = current;
			current->next = prev;

			/* Update head if necessary */
			if (*list == prev)
				*list = current;

			/* Print the list after swapping */
			print_list(*list);

			prev = current->prev;
		}

		current = temp;
  	}
}
