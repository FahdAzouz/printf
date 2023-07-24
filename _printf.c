#include "main.h"

/**
 * _printf - produces output according to a format.
 * @format: format string with specifiers.
 * Return: number of characters printed.
 */

int _printf(const char *format, ...)
{
    int count = 0;
    va_list args;

    va_start(args, format);

    for (int i = 0; format && format[i]; i++)
    {
        if ((format[i + 1] == 'c' || format[i + 1] == 's' || format[i + 1] == 'd' || format[i + 1] == 'i') && format[i] == '%')
        {
            i++;
            switch (format[i])
            {
                case 'c':
                    count += print_char(args);
                    break;
                case 's':
                    count += print_string(args);
                    break;
                case 'd':
                case 'i':
                    count += print_int(args);
                    break;
            }
        }
        else if (format[i] == '%' && format[i + 1] == '%')
        {
            _putchar('%');
            count++;
            i++;
        }
        else
        {
            _putchar(format[i]);
            count++;
        }
    }

    va_end(args);
    return (count);
}
