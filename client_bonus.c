/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idabligi <idabligi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 16:17:25 by idabligi          #+#    #+#             */
/*   Updated: 2023/02/06 12:45:11 by idabligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_bonus.h"

int	*g_str;

void	ft_end(int pid)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		kill(pid, SIGUSR1);
		i++;
		usleep(300);
	}
}

void	ft_write_end(int sig)
{
	if (sig == 30)
		write(1, "Message has been received\n", 26);
}

void	ft_freee_bonus(int sig)
{
	if (sig == 2)
	{
		free(g_str);
		exit (1);
	}
}

void	ft_send_bonus(unsigned char c, int pid)
{
	int	i;

	i = 0;
	g_str = ft_dec_bir_bonus(c);
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
	pid = ft_atoi_bonus(av[1]);
	signal(SIGINT, ft_freee_bonus);
	signal(SIGUSR1, ft_write_end);
	while (av[2][i])
	{
		ft_send_bonus(av[2][i], pid);
		i++;
	}
	ft_end(pid);
}
