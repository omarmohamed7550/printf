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
#endif
