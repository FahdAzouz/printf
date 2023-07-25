#include "main.h"

/**
 * print_string - prints a string.
 * @args: argument list containing the string to be printed.
 * Return: number of characters printed.
 */
int print_string(va_list args)
{
    int i;
    char *str = va_arg(args, char *);
    if (!str)
        str = "(null)";
    for (i = 0; str[i]; i++)
        _putchar(str[i]);
    return (i);
}

/**
 * num_len - calculates the length of a number in digits.
 * @n: number.
 * Return: length of number.
 */
int num_len(int n)
{
    int len = 0;

    while (n)
    {
        len++;
        n /= 10;
    }
    return (len);
}

/**
 * print_char - prints a character.
 * @args: argument list containing the character to be printed.
 * Return: 1 (number of characters printed).
 */
int print_char(va_list args)
{
    _putchar(va_arg(args, int));
    return (1);
}

/**
 * int_to_str - converts an integer to a string.
 * @n: number.
 * Return: pointer to the resulting string.
 */
char *int_to_str(int n)
{
    int len = num_len(n);
    char *str;
    int negative = (n < 0) ? 1 : 0;

    n = (n < 0) ? -n : n;
    len += negative;

    str = malloc(len + 1);
    if (!str)
        return (NULL);
    str[len] = '\0';

    while (len--)
    {
        str[len] = (n % 10) + '0';
        n /= 10;
    }

    if (negative)
        str[0] = '-'; 

    return (str);

}

/**
 * print_int - prints an integer as a string.
 * @args: argument list containing the integer to be printed.
 * Return: number of digits printed.
 */
int print_int(va_list args)
{
    int n = va_arg(args, int);
    char *str = int_to_str(n);
    int len;

    if (!str)
        return (0);

    for (len = 0; str[len]; len++)
        _putchar(str[len]);

    free(str);

    return (len);
}

