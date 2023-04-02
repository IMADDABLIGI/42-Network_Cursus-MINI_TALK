/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idabligi <idabligi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 18:58:59 by idabligi          #+#    #+#             */
/*   Updated: 2023/02/06 12:58:37 by idabligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	ft_bzero(void *s, int n)
{
	int		i;
	void	*potr;

	i = 0;
	potr = s;
	while (i < n)
	{
		*(unsigned char *)potr++ = '\0';
		i++;
	}
}

void	*ft_calloc(char *p1, int count)
{
	if (p1 == NULL)
	{
		p1 = malloc(count * (sizeof(char)));
		if (!p1)
			exit (1);
	}
	ft_bzero(p1, count);
	return (p1);
}

void	ft_putchar_fd(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr_fd(int n)
{
	long	nb;

	nb = n;
	if (nb < 0)
	{
		ft_putchar_fd('-');
		nb *= -1;
	}
	if (nb > 9)
	{
		ft_putnbr_fd(nb / 10);
		ft_putnbr_fd(nb % 10);
	}
	if (nb >= 0 && nb <= 9)
	{
		ft_putchar_fd(nb + '0');
	}
}

int	ft_atoi(const char *str)
{
	int				i;
	int				sign;
	unsigned long	rst;

	i = 0;
	rst = 0;
	sign = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
		rst = rst * 10 + str[i++] - '0';
	return ((int)rst * sign);
}
