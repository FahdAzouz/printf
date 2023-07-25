#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

int _printf(const char *format, ...);
int print_char(va_list arg);
int print_string(va_list arg);
int print_percent(va_list arg);
int print_int(va_list arg);
int is_specifier(char c, specifier_t *spec);
int recursive_print(int n);

/**
 * struct specifier - Struct for format specifiers.
 * @spec: The specifier.
 * @f: The function associated.
 */
typedef struct specifier {
    char spec;
    int (*f)(va_list);
} specifier_t;

#endif /* MAIN_H */

