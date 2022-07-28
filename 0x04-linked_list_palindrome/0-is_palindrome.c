#include "lists.h"
#include <limits.h>
#include <stdlib.h>
/**
 * is_palindrome - tell if a linked list is a palindrome
 * @head: the head of a linked list
 * Return: True if list of ints is a palindrome, else false
 */
int is_palindrome(listint_t **head)
{
	const listint_t *itr;
	unsigned int sz = 0, i = 0;
	int *list, *l_itr;
	/* check for empty */
	if (!head && !*head && !(*head)->next)
		return (1);
	/* find the size */
	for (itr = *head; itr; itr = itr->next)
		++sz;
	/* malloc an array of ints to hold 1/2 the values */
	list = malloc(sizeof(int) * (sz / 2));
	/* establish half of our list's values */
	for (itr = *head, l_itr = list; i < sz / 2;
		itr = itr->next, ++l_itr, ++i)
		*l_itr = itr->n;
	if (sz % 2)
		itr = itr->next;
	/* confirm the other half matches */
	for (--i; i < UINT_MAX; --i, itr = itr->next)
		if (*(list + i) != itr->n)
			return (0);
	free(list);
	return (1);
}
