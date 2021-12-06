# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arohmann <arohmann@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/16 11:23:08 by arohmann          #+#    #+#              #
#    Updated: 2021/07/23 09:27:38 by arohmann         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc

LPATH = ./libft/

CFLAGS = -Wall -Werror -Wextra

SRC = ft_printf.c \
ft_put.c \
ft_put_c.c \
ft_put_s.c \
ft_put_d.c \
ft_put_p.c \
ft_put_u.c \
ft_put_x.c \
ft_lengths.c \
ft_checks.c \
ft_helpers.c \
ft_helpers2.c

all: subsys $(NAME)

$(NAME):
	$(CC) $(CFLAGS) -c $(SRC)
	ar -crs $(NAME) *.o $(LPATH)*.o
	
subsys:
	make -C $(LPATH)
	
clean:
	rm -f *.o
	make clean -C $(LPATH)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LPATH)

re: fclean all

bonus: subsys $(NAME)
