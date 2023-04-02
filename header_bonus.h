/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idabligi <idabligi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 16:13:20 by idabligi          #+#    #+#             */
/*   Updated: 2023/02/05 20:25:26 by idabligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_BONUS_H
# define HEADER_BONUS_H

# include <stdio.h>
# include <unistd.h>
# include <signal.h>
# include <stdlib.h>

void	*ft_calloc_bonus(char *p1, int count);
int		ft_bir_dec_bonus(long binary);
int		*ft_dec_bir_bonus(int decimal);
void	ft_putnbr_fd_bonus(int n);
void	ft_putchar_fd_bonus(char c);
int		ft_atoi_bonus(const char *str);

#endif