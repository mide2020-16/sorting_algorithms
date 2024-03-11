#include "deck.h"

/**
 * compare_card - This compare card of same kind and value
 *
 * @a: the first instance of the deck
 * @b: the second instance of the deck
 *
 * Return: the differeences
*/
int compare_card(const void *a, const void *b)
{
	const deck_node_t *node_a, *node_b;
	int i, kind = 13, id_a = 0, id_b = 0;
	const char *values[] = {"Ace", "2", "3", "4", "5", "6",
	"7", "8", "9", "10", "Jack", "Queen", "King"};

	node_a = *(deck_node_t **)a;
	node_b = *(deck_node_t **)b;

	/*Compare the kind first*/
	if (node_a->card->kind != node_b->card->kind)
		return (node_a->card->kind - node_b->card->kind);

	/*Compare the value if the two nodes are of same kind*/
	for (i = 0; i < kind; i++)
	{
		if (strcmp(values[i], node_a->card->value) == 0)
			id_a = i;
		if (strcmp(values[i], node_b->card->value) == 0)
			id_b = i;
	}

	return (id_a - id_b);
}

/**
 * sort_deck - A function that sorts cards on a deck by
 * its kind and value
 *
 * @deck: The full unsorted cards
*/
void sort_deck(deck_node_t **deck)
{
	deck_node_t *current, **array;
	int count = 0, i, j;

	if (*deck == NULL || deck == NULL)
		return;

	/*Count the number of nodes in the deck*/
	current = *deck;
	while (current != NULL)
	{
		count++;
		current = current->next;
	}

	/*Put all cards in the deck into a new Array*/
	current = *deck;
	array = malloc(count * sizeof(deck_node_t *));
	if (!array)
		return;
	for (i = 0; i < count; i++)
	{
		array[i] = current;
		current = current->next;
	}

	/*Sort all the cards in the array by their kind and value using qsort*/
	qsort(array, count, sizeof(deck_node_t *), compare_card);
	*deck = array[0];
	for (j = 0; j < count; j++)
	{
		array[j]->prev = (j > 0) ? array[j - 1] : NULL;
		array[j]->next = (j < count - 1) ? array[j + 1] : NULL;
	}

	free(array);
}
