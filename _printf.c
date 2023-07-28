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
				char c = va_arg(ap, int);
				write(1, &c, 1);
			}
			else if (*format == 's')
			{
				char *str = va_arg(ap, char*);
				if (str == NULL)
				{
					/*changed null to "(null)"*/
					write(1, "(null)", 6);
					count += 6 - 1; /*should increment by len of null*/
					format++;
					continue;
				}
				while (str[len] != '\0')
					len++;
				write(1, str, len);
				count+=len - 1;
				str = NULL;
				len = 0;
			}/*New addition*/
			else if (*format == 'd' || *format == 'i')
			{
				int num = va_arg(ap, int);
				count += print_num(num) - 1;
			}
			else if (*format == '\0')
			{
				break;
				/*--format; loop should end having reached end of *format
				write(1, format, 1);*/
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
