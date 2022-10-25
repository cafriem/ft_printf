/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafriem <cafriem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 16:14:43 by cafriem           #+#    #+#             */
/*   Updated: 2022/08/18 15:48:09 by cafriem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_conditions(const char *s, int c, va_list letter)
{
	int	end;

	end = 0;
	if (s[c] == '%' && s[c + 1] == 'c')
		end = end + ft_putchar_fd(va_arg(letter, int), 1);
	if (s[c] == '%' && (s[c + 1] == 'd' || s[c + 1] == 'i'))
		end = end + ft_putnbr_fd(va_arg(letter, int), 1);
	if (s[c] == '%' && s[c + 1] == 'u')
		end = end + ft_putnbrus(va_arg(letter, int), 1);
	if (s[c] == '%' && s[c + 1] == 'x')
		end = end + ft_nbrhexlow(va_arg(letter, int));
	if (s[c] == '%' && s[c + 1] == 'X')
		end = end + ft_nbrhexup(va_arg(letter, int));
	if (s[c] == '%' && s[c + 1] == '%')
		end = end + write(1, &s[c], 1);
	if (s[c] == '%' && s[c + 1] == 's')
		end = end + ft_putstr_fd(va_arg(letter, char *), 1);
	if (s[c] == '%' && s[c + 1] == 'p')
		end = end + ft_voidpointer(va_arg(letter, char *));
	return (end);
}

int	ft_printf(const char *s, ...)
{
	int		c;
	int		end;
	va_list	letter;

	c = 0;
	end = 0;
	va_start(letter, s);
	while (s[c] != '\0')
	{
		if (s[c] != '%')
		{
			end = end + write(1, &s[c], 1);
			c++;
		}
		if (s[c] == '%')
		{
			end = end + ft_conditions(s, c, letter);
			c = c + 2;
		}
	}
	va_end(letter);
	return (end);
}

// int	main(void)
// {
// 	char	string[] = "hipjpjkpoki";
// 	char	text[] = "a";
// 	long	age = 50395;
// 	int		test = 16;
// 	char	letter = 'I';

// 	printf("%x\n", test);
// 	ft_printf("%x\n", test);
// 	write(1, "", 1);
// }
// +⡴⠑⡄⠀⠀⠀⠀⠀⠀⠀ ⣀⣀⣤⣤⣤⣀⡀
// +⠸⡇⠀⠿⡀⠀⠀⠀⣀⡴⢿⣿⣿⣿⣿⣿⣿⣿⣷⣦⡀
// +⠀⠀⠀⠀⠑⢄⣠⠾⠁⣀⣄⡈⠙⣿⣿⣿⣿⣿⣿⣿⣿⣆
// +⠀⠀⠀⠀⢀⡀⠁⠀⠀⠈⠙⠛⠂⠈⣿⣿⣿⣿⣿⠿⡿⢿⣆
// +⠀⠀⠀⢀⡾⣁⣀⠀⠴⠂⠙⣗⡀⠀⢻⣿⣿⠭⢤⣴⣦⣤⣹⠀⠀⠀⢀⢴⣶⣆
// +⠀⠀⢀⣾⣿⣿⣿⣷⣮⣽⣾⣿⣥⣴⣿⣿⡿⢂⠔⢚⡿⢿⣿⣦⣴⣾⠸⣼⡿
// +⠀⢀⡞⠁⠙⠻⠿⠟⠉⠀⠛⢹⣿⣿⣿⣿⣿⣌⢤⣼⣿⣾⣿⡟⠉
// +⠀⣾⣷⣶⠇⠀⠀⣤⣄⣀⡀⠈⠻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇
// +⠀⠉⠈⠉⠀⠀⢦⡈⢻⣿⣿⣿⣶⣶⣶⣶⣤⣽⡹⣿⣿⣿⣿⡇
// +⠀⠀⠀⠀⠀⠀⠀⠉⠲⣽⡻⢿⣿⣿⣿⣿⣿⣿⣷⣜⣿⣿⣿⡇
// +⠀⠀ ⠀⠀⠀⠀⠀⢸⣿⣿⣷⣶⣮⣭⣽⣿⣿⣿⣿⣿⣿⣿⠇
// +⠀⠀⠀⠀⠀⠀⣀⣀⣈⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠇
// +⠀⠀⠀⠀⠀⠀⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠃
// +  I am cute <*o*>