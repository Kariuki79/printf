#include "main.h"

/**
 * fill_long_oct_array - calculates an octal number
 * @bnr: array where is stored the binary
 * @oct: array where is stored the octal
 * Return: binary array
 */
char *fill_long_oct_array(char *bnr, char *oct)
{
	int op, a, j, ioct, limit;

	oct[22] = '\0';
	for (a = 63, ioct = 21; a >= 0; a--, ioct--)
	{
		if (a > 0)
			limit = 4;
		else
			limit = 1;
		for (op = 0, j = 1; j <= limit; j *= 2, a--)
			op = ((bnr[a] - '0') * j) + op;
		a++;
		oct[ioct] = op + '0';
	}
	return (oct);
}
