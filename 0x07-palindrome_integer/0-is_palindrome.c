#include "palindrome.h"

/**
 * is_palindrome - tell if an int is a palindrome
 * @n: the value to check
 * Return: True if the digits in the int is a palindrome, else false
 */
int is_palindrome(unsigned long n)
{
	int pwr = 1, l, r, i;
	unsigned long l_val, r_val, dig = 10;
	/* check for single digits */
	if (!n || !(n / dig))
		return (1);
	/* find the significant digits of n */
	for (; n / dig; ++pwr, dig *= 10)
	;
	printf("pwr:%d\n", pwr);
	/* find the middle */
	if (pwr % 2)
	{
		l = pwr / 2;
		r = l;
	}
	else
	{
		l = pwr / 2;
		r = (pwr - 1) / 2;
	}
	/* check for plindrome */
	for (; r >= 0; ++l, --r)
	{
		for (r_val = 1, i = r; i > 0; r_val *= 10, --i)
		;
		for (l_val = 1, i = l; i > 0; l_val *= 10, --i)
		;
		printf("lv:%ld=%ld, rv:%ld=%ld\n", l_val, (n % (10 * l_val)) / l_val, r_val, (n % (10 * r_val)) / r_val);
		if ((n % (10 * l_val)) / l_val != (n % (10 * r_val)) / r_val)
			return (0);
	}
	return (1);
}
