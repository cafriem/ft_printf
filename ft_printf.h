/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafriem <cafriem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 14:33:13 by cafriem           #+#    #+#             */
/*   Updated: 2022/06/17 13:56:18 by cafriem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <string.h>
# include <unistd.h>
# include <stdarg.h>

int				ft_printf(const char *s, ...);
int				ft_putchar_fd(char c, int fd);//char
int				ft_putstr_fd(char *s, int fd);//stirng
int				ft_putnbr_fd(int n, int fd);//num
unsigned long	ft_nbrhexlow(unsigned int n);//hex low
unsigned long	ft_nbrhexup(unsigned int n);//hex high
size_t			ft_strlen(const char *s);//string len
int				ft_putnbrus(unsigned int n, int fd);
unsigned long	ft_voidpointer(char *s);

#endif 
