#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdarg.h>

int _printf(const char *format, ...);
int spe_dec(char n, va_list ag);
int _putchar(char n);
int _puts(const char *sr);
int print_num(int n);
int con_bin(unsigned int n);

#endif
