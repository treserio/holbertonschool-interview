#include "lists.h"

/**
 * is_palindrome - tell if a linked list is a palindrome
 * @head: the head of a linked list
 * Return: True if list of ints is a palindrome, else false
 */
int is_palindrome(listint_t **head)
{
	listint_t *itr;
	unsigned int sz = 0, i = 0;
	/* check for empty */
	if (!head && !*head && !(*head)->next)
		return (1);
	/* find the size */
	for (itr = *head; itr; itr = itr->next)
		++sz;
	/* walk the itr to the mid point, or mid + 1 if odd list */
	for (itr = *head; i < sz / 2; itr = itr->next, ++i)
	;
	if (sz % 2)
		itr = itr->next;
	/* confirm the other half matches */
	for (--i; i < UINT_MAX; --i, itr = itr->next)
		if (nth_value(*head, i) != itr->n)
			return (0);

	return (1);
}

int nth_value(listint_t *start, unsigned int i)
{
	listint_t *node;

	for (--i, node = start; i < UINT_MAX; --i, node = node->next)
	;

	return node->n;
}
