/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idabligi <idabligi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 20:49:31 by idabligi          #+#    #+#             */
/*   Updated: 2023/02/06 11:14:58 by idabligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	*g_str;

void	ft_freee(int sig)
{
	if (sig == 2)
	{
		free(g_str);
		exit (1);
	}
}

void	ft_send(unsigned char c, int pid)
{
	int	i;

	i = 0;
	g_str = ft_dec_bir(c);
	while (i < 8)
	{
		if (g_str[i] == 0)
			kill(pid, SIGUSR1);
		else if (g_str[i] == 1)
			kill(pid, SIGUSR2);
		usleep(500);
		i++;
	}
	free (g_str);
}

int	main(int ac, char **av)
{
	int	pid;
	int	i;

	i = 0;
	if (ac != 3)
		exit (0);
	pid = ft_atoi(av[1]);
	signal(SIGINT, ft_freee);
	while (av[2][i])
	{
		ft_send(av[2][i], pid);
		i++;
	}
}
