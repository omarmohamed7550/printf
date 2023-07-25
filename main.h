#ifndef MAIN_H
#define MAIN_H


#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>


#define BUFF_SIZE 1024

void print_buffer(char buffer[], int *buff_ind);
int _printf(const char *format, ...);
void print_buffer(char buffer[], int *buff_ind);
void handle_character(char buffer[], int *buff_ind, int *count, char c);
void handle_string(char buffer[], int *buff_ind, int *count, char *s);
void handle_percent(char buffer[], int *buff_ind, int *count);
void handle_integer(char buffer[], int *buff_ind, int *count, int num);
void handle_binary(char buffer[], int *buff_ind, int *count, unsigned int num);
void handle_octal(char buffer[], int *buff_ind, int *count, unsigned int num);
void handle_hexadecimal(char buffer[], int *buff_ind, int *count, unsigned int num, bool uppercase);
void handle_unsigned(char buffer[], int *buff_ind, int *count, unsigned int num);
void handle_string_upper(char buffer[], int *buff_ind, int *count, char *s);
void handle_pointer(char buffer[], int *buff_ind, int *count, void *ptr);
void handle_reverse(char buffer[], int *buff_ind, int *count, char *s);
void handle_rot13(char buffer[], int *buff_ind, int *count, char *s);

#endif
