#ifndef FT_MINITALK_H
# define FT_MINITALK_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <stdio.h>


size_t	ft_strlen(const char *str);
void	ft_putstr_fd(char *s, int fd);
void	get_panic(char *error);
void	ft_putnbr_fd(int n, int fd);
int		ft_atoi(const char *str);
int		ft_str_isnum(char *str);

#endif