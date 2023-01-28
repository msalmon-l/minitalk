/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 17:57:56 by msalmon-          #+#    #+#             */
/*   Updated: 2023/01/28 17:54:58 by msalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_send_bit(int pid_server, unsigned char x)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if (x & 1 << i)
			kill(pid_server, SIGUSR1);
		else
			kill(pid_server, SIGUSR2);
		pause();
		usleep(10);
		i--;
	}
}

static void	ft_handler(int signa)
{
	write(1, "recivida ", 9);
	if (signa == SIGUSR1)
		write(1, "30\n", 3);
}

int	main(int argc, char **argv)
{
	int					i;
	pid_t				pid_server;
	struct sigaction	action;

	if (argc != 3)
		return (0);
	action.sa_handler = ft_handler;
	sigemptyset(&action.sa_mask);
	action.sa_flags = 0;
	i = 0;
	sigaction(SIGUSR1, &action, NULL);
	pid_server = ft_atoi(argv[1]);
	while (argv[2][i])
	{
		ft_send_bit(pid_server, argv[2][i]);
		i++;
	}
	return (0);
}
