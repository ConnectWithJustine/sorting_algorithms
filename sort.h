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
int lomuto_partition(int *array, size_t size, int low, int high);
void quicksort(int *array, size_t size, int low, int high);
void quick_sort(int *array, size_t size);

/* Shell sort algorithm */
void shell_sort(int *array, size_t size);

/* Cocktail shaker sort algorithm */
void cocktail_sort_list(listint_t **list);

/* counting sort function */
void counting_sort(int *array, size_t size);

/* merge sort function */
void merge_sort(int *array, size_t size);

/* heap sort function  */
void heap_sort(int *array, size_t size); 

/* radix sort function */
void radix_sort(int *array, size_t size);

/* bitonic sort function */
void bitonic_sort(int *array, size_t size);

/* quick sort function */
void quick_sort_hoare(int *array, size_t size);

#endif /* sort.h */
