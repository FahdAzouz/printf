#include "main.h"
/**
 * _printf - print string and nbr
 * @format: variable
 * @...: characters
 * Return: the nbr of characters
 */
int _printf(const char *format, ...)
{
	va_list ag;
	int x = 0;
	int nbr = 0;
	int result;

	va_start(ag, format);

	if (!format)
		return (-1);
	while (*(format + x))
	{
		if (*(format + x) == '%')
		{
			x++;
			while (*(format + x) == ' ')
			{
				x++;
			}
			if (*(format + x) == '\0')
				return (-1);
			result = spe_dec(*(format + x), ag);
			if (result == -1)
			{
				nbr = nbr + _putchar('%');
				nbr += _putchar(*(format + x));
			}
			else
			{
				nbr += result;
			}
		}
		else
		{
			nbr += _putchar(*(format + x));
		}
		x++;
	}

	va_end(ag);
	return (nbr);
}
