/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idabligi <idabligi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 21:39:32 by idabligi          #+#    #+#             */
/*   Updated: 2023/02/06 14:14:54 by idabligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	ft_bir_dec(long binary)
{
	int	decimal;
	int	weight;
	int	store;

	decimal = 0;
	weight = 1;
	while (binary != 0)
	{
		store = binary % 10;
		decimal = decimal + (store * weight);
		binary /= 10;
		weight = weight * 2;
	}
	return (decimal);
}

static int	*fullofzero(int size)
{
	int	*ntr;
	int	i;

	i = 0;
	ntr = (int *)malloc(size * sizeof(int));
	if (!ntr)
		exit (1);
	while (size > 0)
	{
		ntr[i] = 0;
		i++;
		size--;
	}
	return (ntr);
}

int	*ft_dec_bir(int decimal)
{
	int	*str;
	int	size;

	size = 7;
	str = fullofzero(8);
	while (decimal != 0)
	{
		str[size] = (decimal % 2);
		decimal /= 2;
		size--;
	}
	return (str);
}
