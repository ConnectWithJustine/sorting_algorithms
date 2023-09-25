#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>

/* ***** From alx ***** */

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

void print_array(const int *array, size_t size);
void print_list(const listint_t *list);

/* Bubble sort function */
void bubble_sort(int *array, size_t size);

/* Insertion sort function */
void insertion_sort_list(listint_t **list);

/* Selection sort function asc*/
void selection_sort(int *array, size_t size);

/* Quick sort function */
void quick_sort(int *array, size_t size);

/* Shell sort algorithm */
void shell_sort(int *array, size_t size);

/* Cocktail shaker sort algorithm */
void cocktail_sort_list(listint_t **list);






#endif /* sort.h */
