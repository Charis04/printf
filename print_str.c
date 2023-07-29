#include "main.h"

/**
 * print_str - prints a string
 * @str: string to be printed
 * Return: Number of characters printed
 */

int print_str(char *str)
{
	int len = 0;

	if (str == NULL)
	{
		write(1, "(null)", 6);
		len = 6;
	}
	else
	{
		while (str[len] != '\0')
			len++;
		write(1, str, len);
	}
	return (len - 1);
}
