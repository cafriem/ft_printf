# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cafriem <cafriem@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/17 13:18:31 by cafriem           #+#    #+#              #
#    Updated: 2022/06/17 13:20:35 by cafriem          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = ft_nbrhexlow.c \
ft_printf.c \
ft_putnbr_fd.c \
ft_putstr_fd.c \
ft_voidpointer.c \
ft_nbrhexup.c \
ft_putchar_fd.c \
ft_putnbrus.c \
ft_strlen.c

OBJS = $(SRCS:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all