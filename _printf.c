#include <stdarg.h>
#include <unistd.h>
#include "main.h"

/**
 * _printf - printf function
 * @format: format
 * Return: printed chars
 */

int_printf(const char *format, ...)
{
	va_list args;

	va_start(args, format);

	int printed_chars = 0;

	while (*format)
	{
		if (*format != '%')
		{
			write(1, format, 1);
			printed_chars++;
		}
		else
		{
			format++;
			of(*format == '\0')
				break;

			switch (*format)
			{
				case 'c':
					{
						char c = va_args(args, int)
							write(1, &c, 1);
						printed_chars++;
					}
break:
				case 's':
					{
						char *str = va_arg(args, char *);

						if (str)
						{
							int len = 0;

							while (str[len])
							{
								len++;
							}
							write(1, str, len);
							printed_chars = printed_chars + len;
						}
					}
					break;
				case '%':
					{
						write(1, "%", 1);

						printed_chars++;
					}
					break;

				default:
					write(1, "%", 1);
					write(1, format, 1);
					printed_chars = printed_chars + 2;
					break;
			}
		}
		format++;
	}

	va_end(args);

	return (printed_chars);
}
