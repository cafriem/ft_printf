/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafriem <cafriem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 14:59:19 by cafriem           #+#    #+#             */
/*   Updated: 2022/06/17 13:49:22 by cafriem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_print(char l, int fd)
{
	write (fd, &l, 1);
}

static int	ft_sizeint(int n)
{
	int	c1;
	int	minus;

	c1 = 0;
	minus = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		if (n < 0)
		{
			n = n * -1;
			minus++;
		}
		n = n / 10;
		c1++;
	}
	if (minus == 1)
		c1++;
	return (c1);
}

int	ft_putnbr_fd(int n, int fd)
{
	int	loop;

	if (n == -2147483648LL)
	{
		write (fd, "-2147483648", 11);
		return (11);
	}
	loop = ft_sizeint(n);
	if (n < 0)
	{
		ft_print('-', fd);
		ft_putnbr_fd(-n, fd);
	}
	else if (n > 9)
		ft_putnbr_fd(n / 10, fd);
	if (n >= 0)
	{
		ft_print('0' + n % 10, fd);
	}
	return (loop);
}
