/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habenydi <habenydi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 15:40:26 by habenydi          #+#    #+#             */
/*   Updated: 2025/02/01 15:48:52 by habenydi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mth.h"

void send_bit(int pid, int bit)
{
	if (bit)
		kill(pid, SIGUSR1);
	else
		kill(pid, SIGUSR2);
	usleep(1);
}

void send_char(int pid, char c)
{
	int	i;

	i = 7;
	while (i >= 0)
		send_bit(pid, (c >> i--) & 1);
}

void	send_msg(int pid, char *str)
{
	while (*str)
		send_char(pid, *str++);
	send_char(pid, '\0');
}

void	received(int sig)
{
	if (sig == SIGUSR1)
		ft_putstr("safi rah wsal ✅");
}
int	main(int ac, char **av)
{
	int	pid;

	if (ac != 3)
	{
		ft_putstr("la ghit 2 arg.. [ ./client <pid> <message> ]");
		return (1);
	}
	pid = ft_atoi(av[1]);
	signal(SIGUSR1, received);
	send_msg(pid, av[2]);
}
