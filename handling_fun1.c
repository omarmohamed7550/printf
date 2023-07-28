#include "main.h"

/**
 * handle_character - Entry point
 * @buffer : is a param
 * @buff_ind : is a param
 * @count : is a param
 * @c : is a param
 * Return: nothing
 */

void handle_character(char buffer[], int *buff_ind, int *count, char c)
{
	buffer[*buff_ind++] = c;
	{
		print_buffer(buffer, buff_ind);
	}
	write(1, &c, 1);
	(*count)++;
}

/**
 * handle_string - Entry point
 * @buffer : is a param
 * @buff_ind : is a param
 * @count : is a param
 * @s : is a param
 * Return: nothing
 */

void handle_string(char buffer[], int *buff_ind, int *count, char *s)
{
	int j;

	for (j = 0; s[j] != '\0'; j++)
	{
		if (*buff_ind == BUFF_SIZE)
		{
			print_buffer(buffer, buff_ind);
		}
	write(1, &s[j], 1);
	(*count)++;
	}
}

/**
 * handle_percent - Entry point
 * @buffer : is a param
 * @buff_ind : is a param
 * @count : is a param
 * Return: nothing
 */

void handle_percent(char buffer[], int *buff_ind, int *count)
{
	char perc = '%';

	if (*buff_ind == BUFF_SIZE)
	{
		print_buffer(buffer, buff_ind);
	}
	write(1, &perc, 1);
	(*count)++;
}
