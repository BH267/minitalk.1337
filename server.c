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

void	msg(int sgn)
{
	static char	c;
	static char	bit_count;

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
	kill(sender_pid, SIGUSR1);
}

int	main()
{
	signal(SIGUSR1, msg);
	signal(SIGUSR2, msg);
	ft_putstr("hahowa l pid : ");
	ft_putnbr(getpid());
	ft_putstr("\n3ish\n");
	while (1);
}
