#include "palindrome.h"

/**
 * is_palindrome - tell if an int is a palindrome
 * @n: the value to check
 * Return: True if the digits in the int is a palindrome, else false
 */
int is_palindrome(unsigned long n)
{
	unsigned long rev = 0, temp = n;
	/* reverse the number */
	for (; temp > 0; temp /= 10)
		rev = rev * 10 + temp % 10;
	/* check if reversed number is the same as the original */
	if (n == rev)
		return (1);
	return (0);
}
