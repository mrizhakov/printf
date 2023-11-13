# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mrizakov <mrizakov@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/02 21:22:52 by mrizakov          #+#    #+#              #
#    Updated: 2023/01/21 21:22:35 by mrizakov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libftprintf.a
CC= cc
CFLAGS= -Wall -Wextra -Werror
OBJ = $(SRC:.c=.o)
SRC =  ft_printf.c ft_printf_utils.c ft_printf_utils_hex.c\

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) -I. -c $(SRC)
	ar -rc $(NAME) $(OBJ)

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

test: all
	$(CC) $(CFLAGS) *.o *.a

ct: fclean
	/bin/rm a.out


re: fclean all
