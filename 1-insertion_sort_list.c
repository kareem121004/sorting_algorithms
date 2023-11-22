#include "sort.h"

/**
 * swap_node - swaps 2 nodes
 * @a: the first node
 * @b: the second node
 * Return: the smaller node address
*/

void swap_node(listint_t *a, listint_t *b)
{
	if (a->prev)
		a->prev->next = b;
	if (b->next)
		b->next->prev = a;
	a->next = b->next;
	b->prev = a->prev;
	a->prev = b;
	b->next = a;
}

/**
 * insertion_sort_list - sorts a list using insertion sort algorithm
 * @list: the list to sort
 * Return: void
*/

void insertion_sort_list(listint_t **list)
{
	listint_t *i, *j;

	if ((list == NULL || (*list == NULL)))
		return;

	i = (*list)->next;

	while (i)
	{
		j = i;
		i = i->next;
		while (j && j->prev)
		{
			if (j->prev->n > j->n)
			{
				swap_node(j->prev, j);

				if (!j->prev)
					*list = j;
				print_list((const listint_t *)*list);
			}
			else
				j = j->prev;
		}
	}
}
