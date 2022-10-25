/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafriem <cafriem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 16:18:46 by cafriem           #+#    #+#             */
/*   Updated: 2022/06/17 13:46:27 by cafriem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_print(char l, int fd)
{
	write (fd, &l, 1);
}

static unsigned int	ft_sizeint(unsigned int n)
{
	int	c1;

	c1 = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / 10;
		c1++;
	}
	return (c1);
}

int	ft_putnbrus(unsigned int n, int fd)
{
	int	end;

	end = ft_sizeint(n);
	if (n > 9)
		ft_putnbrus(n / 10, fd);
	if (n >= 0)
		ft_print('0' + n % 10, fd);
	return (end);
}
