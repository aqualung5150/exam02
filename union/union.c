#include <unistd.h>

int	check_char(char c, char *str)
{
	int i;

	i = 0;
	if (str[0] == '\0')
		return (1);
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (0);
		i++;
	}
	return (1);
}

int	str_len(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	main(int argc, char *argv[])
{
	char	str[255];
	int		i;
	int		k;

	i = 0;
	k = 0;
	str[k] = '\0';
	if (argc <= 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	while (argv[1][i] != '\0')
	{
		if (check_char(argv[1][i], str))
		{
			str[k] = argv[1][i];
			k++;
			str[k] = '\0';
		}
		i++;
	}
	i = 0;
	while (argv[2][i] != '\0')
	{
		if (check_char(argv[2][i], str))
		{
			str[k] = argv[2][i];
			k++;
			str[k] = '\0';
		}
		i++;
	}
	write (1, str, str_len(str) + 1);
	return (0);
}
