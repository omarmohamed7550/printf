#include "main.h"

void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - entry point
 * @format: is a param
 * Return: Printed chars.
 */

int _printf(const char *format, ...)
{
	int i = 0;
	int count = 0;
	int buff_ind = 0;
	char buffer[BUFF_SIZE];
	va_list ptr;

	if (format == NULL)
	{
		return (-1);
	}

	va_start(ptr, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buff_ind++] = format[i];
			if (buff_ind == BUFF_SIZE)
			{
				print_buffer(buffer, &buff_ind);
			}
		}
		else
		{
			i++;
			if (format[i] == 'c')
			{
				char c = (char)va_arg(ptr, int);

				buffer[buff_ind++] = c;
				if (buff_ind == BUFF_SIZE)
				{
					print_buffer(buffer, &buff_ind);
				}
			}
			else if (format[i] == 's')
			{
				char *s = va_arg(ptr, char *);

				if (s == NULL)
				{
					return (-1);
				}
				while (*s)
				{
					buffer[buff_ind++] = *s;
					if (buff_ind == BUFF_SIZE)
					{
						print_buffer(buffer, &buff_ind);
					}
					s++;
				}
			}
			else if (format[i] == '%')
			{
				buffer[buff_ind++] = '%';
				if (buff_ind == BUFF_SIZE)
				{
					print_buffer(buffer, &buff_ind);
				}
			}
			else
			{
				return (-1);
			}
		}
	}
	count += buff_ind;
	print_buffer(buffer, &buff_ind);
	va_end(ptr);
	return (count);
}

/**
 * print_buffer - Prints the contents of the buffer if it exists
 * @buffer: is a param
 * @buff_ind: is a param
 * Return: nothing
 */
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
	{
		write(1, buffer, *buff_ind);
	}

	*buff_ind = 0;
}
