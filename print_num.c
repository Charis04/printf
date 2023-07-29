#include "main.h"

/**
 * _print_number - Prints a signed integer using recursion.
 * @n: The integer to print.
 *
 * Return: The number of digits printed.
 */
int print_num(int n)
{
	int count = 0;
	char digit;

	if (n < 0)
	{
		write(1, "-", 1);
		count++;
		/* Handle special case for minimum integer value */
		if (n == INT_MIN)
		{
			write(1, "2147483648", 10);
			return count + 10;
		}
		n *= -1;
	}

	if (n / 10)
		count += print_num(n / 10);

	digit = '0' + (n % 10);
	write(1, &digit, 1);
	count++;

	return (count);
}
