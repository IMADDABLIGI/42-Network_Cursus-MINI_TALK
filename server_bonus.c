/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idabligi <idabligi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 16:11:31 by idabligi          #+#    #+#             */
/*   Updated: 2023/02/06 12:45:27 by idabligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_bonus.h"

static char	*g_str;

void	ft_free_bonus(int sig)
{
	if (sig == 2)
	{
		free(g_str);
		exit (1);
	}
}

void	ft_binary_bonus(int sig, struct __siginfo *info, void *nsense)
{
	static int	i;
	static int	client_pid;
	int			num;

	(void )nsense;
	if (client_pid != (info->si_pid))
	{
		i = 0;
		client_pid = (info->si_pid);
		g_str = ft_calloc_bonus(g_str, 8);
	}	
	if (sig == 30)
		g_str[i] = '0';
	else if (sig == 31)
		g_str[i] = '1';
	i++;
	if (i == 8)
	{
		num = ft_bir_dec_bonus(ft_atoi_bonus(g_str));
		if (num == 0)
			kill(client_pid, SIGUSR1);
		ft_putchar_fd_bonus(num);
		i = 0;
	}
}

int	main(int ac, char **av)
{
	int					pid;
	struct sigaction	sig;

	(void )av;
	(void )ac;
	pid = getpid();
	ft_putnbr_fd_bonus(pid);
	sig.sa_sigaction = ft_binary_bonus;
	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL);
	signal(SIGINT, ft_free_bonus);
	while (1)
		pause();
	return (0);
}
