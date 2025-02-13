/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habenydi <habenydi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 15:49:13 by habenydi          #+#    #+#             */
/*   Updated: 2025/02/01 15:52:35 by habenydi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mth.h"

void	msg(int sgn, siginfo_t *awdi, void *cntxt)
{
	static char	c;
	static char	bit_count;
	static int	pid;

	if (pid != awdi->si_pid)
	{
		bit_count = 0;
		c = 0;
		pid = awdi->si_pid;
	}
	(void)cntxt;
	c = (c << 1) | (sgn == SIGUSR1);
	bit_count++;
	if (bit_count == 8)
	{
		if (c == '\0')
			ft_putchar('\n');
		else
			ft_putchar(c);
		bit_count = 0;
		c = 0;
	}
}

int	main(void)
{
	struct sigaction	iwa;

	iwa.sa_sigaction = msg;
	iwa.sa_flags = SA_SIGINFO;
	sigemptyset(&iwa.sa_mask);
	sigaction(SIGUSR1, &iwa, NULL);
	sigaction(SIGUSR2, &iwa, NULL);
	ft_putstr("\033[38;2;255;255;0mhahowa l pid : \033[0m");
	ft_putnbr(getpid());
	ft_putstr("\033[38;2;255;255;0m\n3ish\n\033[0m");
	while (1)
	{
	}
}
