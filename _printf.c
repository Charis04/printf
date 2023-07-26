#include "main.h"

/**
 * _printf - writes strings to stdout
 * @format: string with placeholders
 *
 * description: function that produces output according to a format.
 *
 * Return: 0 on Success
 */

int _printf(const char *format, ...)
{
int count = 0;
va_list ap;

va_start(ap, format);

while (*format != '\0')
{
	write(1, format, 1);	
	format++;
	count++;
}

return (count);
}
