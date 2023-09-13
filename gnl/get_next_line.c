#include "get_next_line.h"

char *get_line(int fd)
{
	char *s = malloc(10000);
	char *c = s;
	while(read(fd, c, 1) > 0 && *c++ != '\n');
	if (c > s)
	{
		*c = '\0';
		return (s);
	}
	else
	{
		free(s);
		return (NULL);
	}
}

int ft_strlen(char *str)
{
	int i = 0;

	while(str[i] != '\0')
	{
		i++;
	}
	return (i);
}
char *get_next_line(int fd)
{
	char *s;
	char *str;
	int i = 0;
	s = get_line(fd);
	if (s == NULL)
		return (NULL);
	str = malloc(sizeof(char) * (ft_strlen(s) + 1));
	while (s[i] != '\0')
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	free(s);
	return (str);
}
