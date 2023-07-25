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
	if (*buff_ind == BUFF_SIZE)
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
		buffer[(*buff_ind)++] = s[j];
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

	buffer[*buff_ind++] = perc;
	if (*buff_ind == BUFF_SIZE)
	{
		print_buffer(buffer, buff_ind);
	}
	write(1, &perc, 1);
	(*count)++;
}

/**
 * handle_integer - Entry point
 * @buffer : is a param
 * @buff_ind : is a param
 * @count : is a param
 * @num : is a param
 * Return: nothing
 */

void handle_integer(char buffer[], int *buff_ind, int *count, int num)
{
	char num_str[BUFF_SIZE];
	int j = 0;

	if (num == 0)
	{
		buffer[*buff_ind++] = '0';
		if (*buff_ind == BUFF_SIZE)
		{
			print_buffer(buffer, buff_ind);
		}
		write(1, "0", 1);
		(*count)++;
	}
	else if (num < 0)
	{
		num = -num;
		buffer[*buff_ind++] = '-';
		if (*buff_ind == BUFF_SIZE)
		{
			print_buffer(buffer, buff_ind);
		}
		write(1, "-", 1);
		(*count)++;
	}
	while (num > 0)
	{
		num_str[j++] = num % 10 + '0';
		num /= 10;
	}
	while (j > 0)
	{
		j--;
		buffer[*buff_ind++] = num_str[j];
		if (*buff_ind == BUFF_SIZE)
		{
			print_buffer(buffer, buff_ind);
		}
		write(1, &num_str[j], 1);
		(*count)++;
	}
}
