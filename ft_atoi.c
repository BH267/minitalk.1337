/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habenydi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 10:05:45 by habenydi          #+#    #+#             */
/*   Updated: 2025/02/02 15:26:53 by habenydi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mth.h"

int	ft_isdigit(int n)
{
	return ('0' <= n && n <= '9');
}

void	is_end(const char *nbr, int n)
{
	if (*nbr != '\0' || n == 0)
	{
		ft_putstr("\033[38;2;255;0;0m		[ BAD PID ]\n\033[0m");
		exit(1);
	}
}

int	ft_atoi(const char *nbr)
{
	int	n;
	int	s;

	s = 1;
	n = 0;
	while (!ft_isdigit(*nbr) && *nbr != '-' && *nbr != '+')
	{
		if ((9 <= *nbr && *nbr <= 13) || *nbr == 32)
			nbr++;
		else
			is_end("iwa", 0);
	}
	if (*nbr == '-' || *nbr == '+')
	{
		if (*nbr == '-')
			s = -1;
		nbr++;
	}
	while (ft_isdigit(*nbr))
	{
		n = n * 10 + (*nbr - '0');
		nbr++;
	}
	return (is_end(nbr, n), n * s);
}
