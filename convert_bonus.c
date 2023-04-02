/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idabligi <idabligi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 19:08:25 by idabligi          #+#    #+#             */
/*   Updated: 2023/02/06 14:15:31 by idabligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_bonus.h"

int	ft_bir_dec_bonus(long binary)
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

static int	*fullofzero_bonus(int size)
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

int	*ft_dec_bir_bonus(int decimal)
{
	int	*str;
	int	size;
	int	j;

	j = 0;
	size = 7;
	str = fullofzero_bonus(8);
	while (decimal != 0)
	{
		str[size] = (decimal % 2);
		decimal /= 2;
		size--;
	}
	return (str);
}
