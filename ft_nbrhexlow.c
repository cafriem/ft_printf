/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrhexlow.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafriem <cafriem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 15:52:06 by cafriem           #+#    #+#             */
/*   Updated: 2022/06/17 13:34:14 by cafriem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_nbrhexlowst(int n)
{
	if (n < 10)
		ft_putnbr_fd(n, 1);
	if (n == 10)
		write(1, "a", 1);
	if (n == 11)
		write(1, "b", 1);
	if (n == 12)
		write(1, "c", 1);
	if (n == 13)
		write(1, "d", 1);
	if (n == 14)
		write(1, "e", 1);
	if (n == 15)
		write(1, "f", 1);
}

unsigned long	ft_nbrhexlow(unsigned int n)
{
	unsigned long	end;
	int				res;

	end = n;
	res = 0;
	if (n > 15)
		ft_nbrhexlow(n / 16);
	if (n >= 0)
		ft_nbrhexlowst(n % 16);
	while (end >= 16)
	{
		res++;
		end = end / 16;
	}
	return (res + 1);
}
