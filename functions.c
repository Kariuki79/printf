#include "main.h"

/**
 * print_char - Prints a character
 */
int print_char(va_list args, char buffer[],
	int flags, int width, int precision, int size)
{
	char c = va_arg(args, int);
	return (handle_write_char(c, buffer, flags, width, precision, size));
}

/**
 * print_string - Prints a string
 */
int print_string(va_list args, char buffer[],
	int flags, int width, int precision, int size)
{
	char *str = va_arg(args, char *);

	if (str == NULL)
		str = (precision >= 6) ? "      " : "(null)";

	int length = 0;
	while (str[length] != '\0')
		length++;

	if (precision >= 0 && precision < length)
		length = precision;

	int printed_chars = 0;
	if (width > length)
	{
		if (flags & F_MINUS)
		{
			printed_chars += write(1, str, length);
			for (int i = width - length; i > 0; i--)
				printed_chars += write(1, " ", 1);
			return printed_chars;
		}
		else
		{
			for (int i = width - length; i > 0; i--)
				printed_chars += write(1, " ", 1);
			return printed_chars + write(1, str, length);
		}
	}

	return write(1, str, length);
}

/**
 * print_percent - Prints a percent sign
 */
int print_percent(va_list args, char buffer[],
	int flags, int width, int precision, int size)
{
	(void)args;
	(void)buffer;
	(void)flags;
	(void)width;
	(void)precision;
	(void)size;
	return write(1, "%%", 1);
}

/**
 * print_int - Prints an integer
 */
int print_int(va_list args, char buffer[],
	int flags, int width, int precision, int size)
{
	long int n = va_arg(args, long int);
	unsigned long int num = convert_size_number(n, size);

	int is_negative = (n < 0) ? 1 : 0;

	char num_buffer[BUFF_SIZE];
	int i = BUFF_SIZE - 2;

	if (num == 0)
		num_buffer[i--] = '0';

	while (num > 0)
	{
		num_buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return write_number(is_negative, i, num_buffer, flags, width, precision, size);
}

/**
 * print_binary - Prints an unsigned binary number
 */
int print_binary(va_list args, char buffer[],
	int flags, int width, int precision, int size)
{
	unsigned int v = va_arg(args, unsigned int);
	unsigned int w = 2147483648;
	unsigned int a[32];

	for (int u = 0; u < 32; u++)
	{
		a[u] = (v / w) % 2;
		w /= 2;
	}

	int total = 0;
	int count = 0;

	for (int u = 0; u < 32; u++)
	{
		total += a[u];
		if (total || u == 31)
		{
			char z = '0' + a[u];
			count += write(1, &z, 1);
		}
	}

	return count;
}
