/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 20:32:32 by msalmon-          #+#    #+#             */
/*   Updated: 2023/01/28 00:50:55 by msalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_handler(int signal, siginfo_t *info, __attribute__((unused)) void *c)
{
	static char	x;
	static int	i = 7;
	int const	client = (int)info->si_pid;

	if (signal == SIGUSR1)
		x = x | (1 << i);
	i--;
	if (i == -1)
	{
		write(1, &x, 1);
		x = 0;
		i = 7;
	}
	usleep(10);
	kill(client, SIGUSR1);
}

int	main(void)
{
	struct sigaction	action;
	pid_t				my_pid;
	int					n_char;

	my_pid = getpid();
	action.sa_sigaction = ft_handler;
	sigemptyset(&action.sa_mask);
	action.sa_flags = SA_SIGINFO;
	n_char = 0;
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
	write(1, "mi pid es:", 10);
	ft_putnbr_fd(my_pid, 1);
	write(1, "\n", 1);
	while (1 == 1)
	{
		pause();
	}
	return (0);
}
