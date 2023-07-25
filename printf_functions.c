#include "main.h"

/**
 * spe_dec - function for detecting the specifier
 * @n: which specifier
 * @ag: argument
 *
 * Return: the number of char
 */
int spe_dec(char n, va_list ag)
{
	int result = 0;

	if (n == 'c')
	{
		result = _putchar(va_arg(ag, int));
	}
	else if (n == '%')
	{
		result = _putchar('%');
	}
	else if (n == 's')
	{
		result = _puts(va_arg(ag, char *));
	}
	else if (n == 'd' || n == 'i')
	{
		result = print_num(va_arg(ag, int));
	}
	else if (n == 'b')
	{
		result = con_bin(va_arg(ag, unsigned int));
	}
	else
	{
		return (-1);
	}
	return (result);
}

/**
 * con_bin - converts to binary
 * @n: decimal
 * Return: num of character
 */
int con_bin(unsigned int n)
{
	int num = 0;
	int i = 0;
	char numb[30];
	int x;

	if (n == 0)
	{
		num += _putchar('0');
		return (1);
	}
	while (n >= 1)
	{
		numb[i++] = n % 2;
		n /= 2;
	}
	for (x = i - 1 ; x >= 0 ; x--)
	{
		_putchar(numb[x] + '0');
		num++;
	}
	return (num);
}

/**
 * print_num - print an intiger
 * @n: the intiger
 * Return: the number of digits
 */
int print_num(int n)
{
	int num = 0;

	if (n == 0)
	{
		num += _putchar('0');
		return (num);
	}

	if (n == -2147483648)
	{
		num += _putchar('-');
		num += _putchar('2');
		n = 147483648;
	}

	if (n < 0)
	{
		num += _putchar('-');
		n = -n;
	}

	if (n / 10)
	{
		num += print_num(n / 10);
	}
	num += _putchar('0' + (n % 10));

	return (num);
}

/**
 * _puts - print a sting of chars
 * @sr: the string
 *
 * Return: the number of character
 */
int _puts(const char *sr)
{
	int i = 0;

	if (!sr)
	{
		sr = "(null)";
	}

	while (sr[i])
	{
		_putchar(sr[i]);
		i++;
	}
	return (i);
}

/**
 * _putchar - function
 * @n: var
 * Return: the char
 */
int _putchar(char n)
{
	return (write(1, &n, 1));
}
