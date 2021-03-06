# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmiralle <rmiralle@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/31 18:41:51 by rmiralle          #+#    #+#              #
#    Updated: 2018/01/05 18:49:51 by rmiralle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC =	fillit.c\
		ft_piece.c\

OBJ = ${SRC:.c=.o}

CC = clang

CFLAGS = -Wall -Wextra -Werror -I Libft 

LDFLAGS = -L Libft -l ft

all: $(NAME)

$(NAME): libft $(OBJ)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $(NAME) $(OBJ)

libft:
	Make -C Libft

clean:
	rm -rf $(OBJ)
	Make -C Libft clean

fclean: clean
	rm -rf $(NAME)
	Make -C Libft fclean

re: fclean all
	Make -C Libft re

.PHONY: libft