#include "main.h"
/**
 * handl_buffer - concatenates the buffer characters
 * @buf: buffer pointer
 * @c: character to concatenate(bring together)
 * @ibuf: index of buffer pointer
 * Return: index of buffer pointer
 */
unsigned int handle_buffer(char *buf, char c, unsigned int ibuf)
{
	if (ibuf == 1024)
	{
		print_buf(buf, ibuf);
		ibuf = 0;
	}
	buf[ibuf] = c;
	ibuf++;
	return (ibuf);
}
