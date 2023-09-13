#include <unistd.h>

int	check_char(char c, char *str)
{
	int	i;

	i = 0;
	if (str[0] == '\0')
		return (1);
	while (str[i] != '\0')
	{
		if (str[i] == c)
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int str_len(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	main(int argc, char *argv[])
{
	char	str[255];
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	str[k] = '\0';
	if (argc <= 2)
		{
			write (1, "\n", 1);
			return (0);
		}
	while (argv[1][i] != '\0')
	{
		while (argv[2][j] != '\0')
		{
			if (argv[1][i] == argv[2][j])
			{
				if (check_char(argv[1][i], str))
				{
					str[k] = argv[1][i];
					k++;
					str[k] = '\0';
				}
			}
			j++;
		}
		j = 0;
		i++;
	}
	str[k] = '\n';
	str[k + 1] = '\0';
	write (1, str, str_len(str));
	return (0);
}
