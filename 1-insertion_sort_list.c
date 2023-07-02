#include "sort.h"

/**
 * _swap - swaps a linked list node with it previous node
 * @node: The node to swap with previous
 * @list: linked list
 * Return: pointer to the node that was swap
 */
listint_t *_swap(listint_t *node, listint_t **list)
{
	listint_t *prev = node->prev;

	prev->next = node->next;
	if (node->next)
		node->next->prev = prev;
	node->next = prev;
	node->prev = prev->prev;
	prev->prev = node;
	if (node->prev)
		node->prev->next = node;
	else
		*list = node;
	return (node);
}

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm.
 * @list: The list to sort
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *node;

	if (list == NULL || (*list)->next == NULL)
		return;
	node = (*list)->next;
	while (node)
	{
		while ((node->prev != NULL) && (node->prev->n > node->n))
		{
			node = _swap(node, list);
			print_list(*list);
		}
		node = node->next;
	}
}
