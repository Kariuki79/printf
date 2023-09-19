#include <stdarg.h>
#include <unistd.h>
#include "main.h"

/**
 * _printf - printf function
 * @format: format
 * Return: printed chars
 */
int_printf(const char *format,...)
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
			of (*format == '\0')
				break;

			switch (*format)
			{
				case 'c':
					{
						char c = va_args(args,int)
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
							while (*str)
							{
								write(1, str, 1);

								str++;
								printed_chars++;
							}
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
