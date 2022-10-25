/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrhexup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafriem <cafriem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 15:31:28 by cafriem           #+#    #+#             */
/*   Updated: 2022/06/17 13:36:50 by cafriem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_nbrhexupst(int n)
{
	if (n < 10)
		ft_putnbr_fd(n, 1);
	if (n == 10)
		write(1, "A", 1);
	if (n == 11)
		write(1, "B", 1);
	if (n == 12)
		write(1, "C", 1);
	if (n == 13)
		write(1, "D", 1);
	if (n == 14)
		write(1, "E", 1);
	if (n == 15)
		write(1, "F", 1);
	return (1);
}

unsigned long	ft_nbrhexup(unsigned int n)
{
	unsigned long	end;
	int				res;

	end = n;
	res = 0;
	if (n > 15)
		ft_nbrhexup(n / 16);
	if (n >= 0)
		ft_nbrhexupst(n % 16);
	while (end >= 16)
	{
		res++;
		end = end / 16;
	}
	return (res + 1);
}
