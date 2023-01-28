/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 00:43:14 by msalmon-          #+#    #+#             */
/*   Updated: 2023/01/28 00:43:18 by msalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include <stdio.h>
# include <signal.h>
# include <sys/types.h>
# include <unistd.h>
# include <stdlib.h>

void	ft_send_bit(int pid_server, unsigned char x);
int		ft_atoi(const char *str);
void	ft_putnbr_fd(int n, int fd);

#endif
