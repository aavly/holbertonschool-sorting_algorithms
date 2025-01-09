#include "sort.h"

/**
 * swapNodes - swaps two nodes in a doubly linked list.
 *
 * @list: double pointer to the head of list.
 * @firstNode: first node to swap.
 * @secondNode: second node to swap.
 */

void swapNodes(listint_t **list, listint_t *firstNode, listint_t *secondNode)
{
	if (firstNode->prev)
		firstNode->prev->next = secondNode;
	else
		*list = secondNode;

	if (secondNode->next)
		secondNode->next->prev = firstNode;

	secondNode->prev = firstNode->prev;
	firstNode->next = secondNode->next;
	secondNode->next = firstNode;
	firstNode->prev = secondNode;
}

/**
 * insertion_sort_list - sorts a doubly linked list of ints in
 *			ascending order using insertion sort algorithm.
 *
 * @list: double pointer to the head of the list.
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current, *temp;

	if (!list || !(*list) || !(*list)->next)
		return;

	current = (*list)->next;
	while (current)
	{
		temp = current;
		while (temp->prev && temp->n < temp->prev->n)
		{
			swapNodes(list, temp->prev, temp);
			print_list(*list);
		}

		current = current->next;
	}
}
