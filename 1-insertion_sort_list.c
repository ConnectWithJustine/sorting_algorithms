#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 *                       in ascending order using Insertion sort.
 * @list: Pointer to a pointer to the head of the list.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *sorted;
	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	
	sorted = NULL;   /* Initialize sorted list as empty */
	while (*list != NULL)
	{
		listint_t *current = *list;  /* Take the first node from the original list*/
		*list = current->next;    /* Move to the next node in the original list*/
		if (sorted == NULL || current->n < sorted->n)
		{
/**
 * If sorted list is empty or current node's
 * value is smaller, insert it at the beginning 
 * of the sorted list. 
 * */
			current->next = sorted;
			current->prev = NULL;
			if (sorted != NULL)
				sorted->prev = current;
			sorted = current;
		}
		else
		{
/* Find the correct position in the sorted list and insert it there.*/
			listint_t *temp = sorted;
			while (temp->next != NULL && temp->next->n < current->n)
				temp = temp->next;
			
			current->next = temp->next;
			current->prev = temp;
			if (temp->next != NULL)
				temp->next->prev = current;
			temp->next = current;
		}

        /* Print the list after each swap */
		print_list(sorted);
	}
	
	*list = sorted;  /* Update the original list's head to the sorted list*/
}
