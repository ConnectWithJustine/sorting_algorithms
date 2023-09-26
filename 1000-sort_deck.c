#include "deck.h"

/**
 * card_cmp - Comparison function for sorting cards.
 * @card1: Pointer to the first card.
 * @card2: Pointer to the second card.
 * Return: Negative value if card1 < card2, 0 if card1 == card2,
 * Positive value if card1 > card2.
 */
int card_cmp(const void *card1, const void *card2)
{
	int value_cmp;

	const card_t *c1 = *(const card_t **)card1;
	const card_t *c2 = *(const card_t **)card2;

	value_cmp = strcmp(c1->value, c2->value);

	if (value_cmp != 0)
		return (value_cmp);

	return (c1->kind - c2->kind);
}

/**
 * sort_deck - Sorts a deck of cards.
 * @deck: Pointer to the head of the deck.
 */
void sort_deck(deck_node_t **deck)
{
	size_t deck_size,i;
	deck_node_t *current;
	card_t **cards;

	deck_size = 0;
	current = *deck;

	/* Count the number of cards in the deck */
	while (current != NULL)
	{
		deck_size++;
		current = current->next;
	}

	/* Create an array of card pointers */
	cards = malloc(sizeof(card_t *) * deck_size);

	if (cards == NULL)
	{
		perror("Memory allocation failed");
		exit(EXIT_FAILURE);
	}

	/* Populate the array with card pointers */
	current = *deck;
	for (i = 0; i < deck_size; i++)
	{
		cards[i] = (card_t *)current->card;
		current = current->next;
	}

	/* Use qsort to sort the array of card pointers */
	qsort(cards, deck_size, sizeof(card_t *), card_cmp);

	/* Update the deck nodes with the sorted cards */
	current = *deck;
	for (i = 0; i < deck_size; i++)
	{
		current->card = cards[i];
		current = current->next;
	}

	free(cards);
}
