#include "main.h"

/**
 * print_char - Prints a character.
 * @arg: va_list argument.
 *
 * Return: Number of characters printed.
 */
int print_char(va_list arg)
{
    char c = va_arg(arg, int);
    write(1, &c, 1);
    return (1);
}

/**
 * print_string - Prints a string.
 * @arg: va_list argument.
 *
 * Return: Number of characters printed.
 */
int print_string(va_list arg)
{
    int i;
    char *str = va_arg(arg, char *);

    if (!str)
        str = "(null)";
    for (i = 0; str[i]; i++)
        write(1, &str[i], 1);
    return (i);
}

/**
 * print_percent - Prints a percent sign.
 * @arg: va_list argument (unused).
 *
 * Return: Number of characters printed.
 */
int print_percent(va_list arg)
{
    (void)arg; /* arg is unused */
    write(1, "%", 1);
    return (1);
}

/**
 * print_int - Prints an integer.
 * @arg: va_list argument.
 *
 * Return: Number of characters printed.
 */
int print_int(va_list arg)
{
    int n = va_arg(arg, int);
    int count = 0;

    if (n < 0)
    {
        write(1, "-", 1);
        count++;
        n = -n;
    }
    count += recursive_print(n);
    return (count);
}

/**
 * recursive_print - Prints an integer recursively.
 * @n: Integer.
 *
 * Return: Number of characters printed.
 */
int recursive_print(int n)
{
    int count = 0;

    if (n / 10)
        count += recursive_print(n / 10);
    write(1, (char[]) {n % 10 + '0'}, 1);
    return (count + 1);
}

