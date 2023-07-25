#include "main.h"

/**
 * _printf - Our custom printf function.
 * @format: Format string.
 *
 * Return: Number of characters printed.
 */
int _printf(const char *format, ...)
{
    unsigned int i = 0, count = 0;
    va_list arg;
    specifier_t specifiers[] = {
        {'c', print_char},
        {'s', print_string},
        {'%', print_percent},
        {'d', print_int},
        {'i', print_int},
        {'\0', NULL}
    };

    if (!format)
        return (-1);

    va_start(arg, format);
    while (format && format[i])
    {
        if (format[i] == '%' && is_specifier(format[i + 1], specifiers) != -1)
        {
            count += specifiers[is_specifier(format[i + 1], specifiers)].f(arg);
            i++;
        }
        else
        {
            write(1, &format[i], 1);
            count++;
        }
        i++;
    }
    va_end(arg);
    return (count);
}

/**
 * is_specifier - Checks if character matches a format specifier.
 * @c: Character to check.
 * @spec: Array of struct specifier.
 *
 * Return: Index in the spec array or -1 if no match.
 */
int is_specifier(char c, specifier_t *spec)
{
    int i;

    for (i = 0; spec[i].spec; i++)
    {
        if (spec[i].spec == c)
            return (i);
    }
    return (-1);
}

