# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mihail <mihail@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/10/07 02:00:01 by mgolban           #+#    #+#              #
#    Updated: 2016/11/04 21:02:00 by mgolban          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC = main.c ft_clear_xy.c ft_create_list.c ft_create_map.c ft_exit.c \
	  ft_free_list.c ft_free_map.c ft_strnew.c ft_strtrim.c ft_memset.c \
	  ft_print_map.c ft_putendl.c ft_solve_fillit.c ft_strdup.c ft_strlen.c \
	  ft_valide_fillit.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) $(SRC) -c
	$(CC) $(OBJ) -o $(NAME)
	@echo "Executable file $@ is created"	

.PHONY: clean

clean:
	/bin/rm -rf $(OBJ)
	@echo "Delete C object files"

fclean: clean
	/bin/rm -f $(NAME)
	@echo "Delete executable file $(NAME)"

re: fclean all
