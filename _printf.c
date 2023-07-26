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

	if (format == NULL)
		return (-1);

	va_start(ap, format);

	while (*format != '\0')
	{
		if (*format != '%')
		{
			write(1, format, 1);
			format++;
			count++;
		}
		else
		{
			++format;
			if (*format == 'c')
			{
				int *c = va_arg(ap, int*);
				write(1, &c, 1);
				count++;
				format++;
			}
		}
	}
	va_end(ap);
	return (count);
}
