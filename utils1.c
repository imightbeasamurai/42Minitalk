#include "minitalk.h"

size_t ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return;
	write (fd, s, ft_strlen(s));
}

void get_panic(char *error)
{
	ft_putstr_fd(error, 2);
	exit(EXIT_FAILURE);
}
