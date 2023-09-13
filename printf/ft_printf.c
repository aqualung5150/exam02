#include "ft_printf.h"
#include <stdio.h>
char *ft_itoa(long long num)
{
	long long n = num;
	int count = 0;
	char *str;
	if (num == 0)
	{
		str = malloc(sizeof(char) * 2);
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}
	while (n != 0)
	{
		n = n / 10;
		count++;
	}
	str = malloc(sizeof(char) * (count + 1));
	if (str == NULL)
		return (NULL);
	n = num;
	str[count] = '\0';
	count--;
	while (count >= 0)
	{
		str[count] = (n % 10) + '0';
		n = n / 10;
		count--;
	}
	return (str);
}

char *change_hex(int num)
{
	unsigned int n = num;
	char *hexstr = "0123456789abcdef";
	char *str;
	int count = 0;

	while (n != 0)
	{
		n = n / 16;
		count++;
	}
	n = num;
	str = malloc(sizeof(char) * (count + 1));
	if (str == NULL)
		return (NULL);
	str[count] = '\0';
	count--;
	while (n != 0)
	{
		str[count] = hexstr[n % 16];
		count--;
		n = n / 16;
	}
	return (str);
}

int ft_strlen(char *str)
{
	int i = 0;

	while (str[i] != '\0')
		i++;
	return (i);
}

int ft_printf(const char *str, ...)
{
	va_list ap;
	char *s;
	int readsize = 0;
	int i = 0;
	long long decimal;
	int hex;

	va_start(ap, str);
	while (str[i] != '\0')
	{
		if (str[i] != '%')
		{
			readsize += write(1, &str[i], 1);
		}
		else if (str[i] == '%')
		{
			i++;
			if (str[i] == 'd')
			{
				decimal = va_arg(ap, int);
				if(decimal < 0)
				{
					readsize += write(1, "-", 1);
					decimal *= -1;
				}
				s = ft_itoa(decimal);
				if (s == 0)
					return (0);
				readsize += write(1, s, ft_strlen(s));
				free(s);
			}
			else if(str[i] == 's')
			{
				s = va_arg(ap, char *);
				if (s == NULL)
					s = "(null)";
				readsize += write(1, s, ft_strlen(s));
			}
			else if(str[i] == 'x')
			{
				hex = va_arg(ap, int);
				if (hex == 0)
					readsize += write(1, "0", 1);
				else
				{
					s = change_hex(hex);
					if (s == NULL)
						return(0);
					readsize += write(1, s, ft_strlen(s));
					free(s);
				}
			}
		}
		if (str[i])
			i++;
	}
	return (readsize);
}
