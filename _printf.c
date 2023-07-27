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
	int count = 0, len = 0;
	va_list ap;
	char *str = NULL;

	if (format == NULL)
		return (-1);

	va_start(ap, format);

	while (*format != '\0')
	{
		if (*format != '%')
		{
			write(1, format, 1);
		}
		else
		{
			++format;
			if (*format == 'c')
			{
				char c = va_arg(ap, int);
				write(1, &c, 1);
			}
			else if (*format == 's')
			{
				str = va_arg(ap, char*);
				if (str == NULL)
				{
					write(1, '\0', 1);
					count++;
					return (count);
				}
				while (str[len] != '\0')
				{
					len++;
				}
				write(1, str, len);
				count+=len - 1;
				str = NULL;
				len = 0;
			}
			else
			{
				write(1, format, 1);
			}
		}
		format++;
		count++;
	}
	va_end(ap);
	return (count);
}
