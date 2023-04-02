/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idabligi <idabligi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 11:28:00 by idabligi          #+#    #+#             */
/*   Updated: 2023/02/06 13:22:21 by idabligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static char	*g_str;

void	ft_free(int sig)
{
	if (sig == 2)
	{
		free(g_str);
		exit (1);
	}
}

void	ft_binary(int sig, struct __siginfo *info, void *nsense)
{
	static int	i;
	static int	client_pid;
	int			num;

	(void )nsense;
	if (client_pid != (info->si_pid))
	{
		i = 0;
		client_pid = (info->si_pid);
		g_str = ft_calloc(g_str, 8);
	}	
	if (sig == 30)
		g_str[i] = '0';
	else if (sig == 31)
		g_str[i] = '1';
	i++;
	if (i == 8)
	{
		num = ft_bir_dec(ft_atoi(g_str));
		ft_putchar_fd(num);
		i = 0;
		g_str = ft_calloc(g_str, 8);
	}
}

int	main(int ac, char **av)
{
	int					pid;
	struct sigaction	sig;

	(void )av;
	(void )ac;
	pid = getpid();
	ft_putnbr_fd(pid);
	sig.sa_sigaction = ft_binary;
	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL);
	signal(SIGINT, ft_free);
	while (1)
		pause();
	return (0);
}
