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
	int num, count = 0;
	char c;
	char *str;
	va_list ap;
	/*char *null = "(null)";*/

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
				c = va_arg(ap, int);
				write(1, &c, 1);
			}
			else if (*format == 's')
			{
				str = va_arg(ap, char*);
				count += print_str(str);
			} /*New addition*/
			else if (*format == 'd' || *format == 'i')
			{
				num = va_arg(ap, int);
				count += print_num(num) - 1;
			}
			else if (*format == '\0')
			{
				break;
				/*
				 * --format; loop should end having reached end of *format
				 * write(1, format, 1);
				 */
			}
			else
			{
				write(1, format, 1);
			}
		}
		format++;
		count++;/*should be in each if*/
	}
	va_end(ap);
	return (count);
}
