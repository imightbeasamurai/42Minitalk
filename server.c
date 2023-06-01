#include "minitalk.h"

pid_t	g_pid;

int	binary_c(int power)
{
	int	base;
	int	ret;

	if (!power)
		return (1);
	base = 2;
	ret = 2;
	while (power > 1)
	{
		ret *= base;
		power--;
	}
	return (ret);
}

void catcher(int sig, siginfo_t *data, void *empty)
{
	static int	pos = 7;
	static int	sum = 0;

	(void)empty;
	if (g_pid != data->si_pid)
	{
		g_pid = data->si_pid;
		pos = 7;
		sum = 0;
	}
	if (sig == SIGUSR1)
	{
		sum += binary_c(pos);
		pos--;
	}
	else
		pos--;
	if (pos == -1)
	{
		write(1, &sum, 1);
		pos = 7;
		sum = 0;
	}
}

int main(int ac, char *av[])
{
	(void)av;
	pid_t				sr_pid;
	struct sigaction	sig;
	if (ac == 1)
	{
	write(1, "\033[32mServer PID: \033[0m", 22);
	sr_pid = getpid();
	ft_putnbr_fd(sr_pid, 1);
	write(1, "\n", 1);
	sig.sa_sigaction = catcher; 
	sigemptyset(&sig.sa_mask);
	sig.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR2, &sig, NULL);
	sigaction(SIGUSR1, &sig, NULL);
	while (1)
		pause();
	}
	else
		get_panic("\033[91mError: invalid arguments\033[0m");
	return (0);
}
