NAME = fillit

SRC = arv.c\

OBJ = arv.o\

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