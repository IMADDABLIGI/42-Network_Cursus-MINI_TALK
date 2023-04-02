/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idabligi <idabligi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 14:24:16 by idabligi          #+#    #+#             */
/*   Updated: 2023/02/06 13:22:15 by idabligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <stdio.h>
# include <unistd.h>
# include <signal.h>
# include <stdlib.h>

void	*ft_calloc(char *p1, int count);
int		ft_bir_dec(long binary);
int		*ft_dec_bir(int decimal);
void	ft_putnbr_fd(int n);
void	ft_putchar_fd(char c);
int		ft_atoi(const char *str);

#endif