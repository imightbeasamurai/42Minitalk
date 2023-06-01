#include "minitalk.h"

void send_signal(char bin_char, int pid)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if ((bin_char >> i) & 1)
		{
			if (kill(pid, SIGUSR1) == -1)
				get_panic("\033[91mError: kill\033[0m");
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				get_panic("\033[91mError: kill\033[0m");
		}
		usleep(800);
		i--;
	}
}

int main(int ac, char *av[])
{
	pid_t	sr_pid;
	size_t	i;

	if (ac == 3 && ft_str_isnum(av[1]))
	{
		if (ft_atoi(av[1]) == 0)
			get_panic("\033[91mError: used PID 0\033[0m");
		sr_pid = ft_atoi(av[1]);
		i = 0;
		while (av[2][i])
			{
				send_signal(av[2][i], sr_pid);
				i++;
			}
	}
	else
		get_panic("\033[91mError: invalid arguments\033[0m");
	return (0);
}
