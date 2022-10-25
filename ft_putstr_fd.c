/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafriem <cafriem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 14:15:15 by cafriem           #+#    #+#             */
/*   Updated: 2022/06/17 13:26:05 by cafriem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr_fd(char *s, int fd)
{
	int	c;
	int	c1;

	c1 = 0;
	if (s == NULL)
	{
		write (1, "(null)", 6);
		return (6);
	}
	c = ft_strlen(s);
	while (c != c1)
	{
		write(fd, &s[c1], 1);
		c1++;
	}
	return (c);
}
