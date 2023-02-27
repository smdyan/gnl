# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smdyan <smdyan@student.21-school.ru>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/01 20:03:23 by smdyan            #+#    #+#              #
#    Updated: 2022/01/04 00:29:15 by smdyan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = main.out

SRC = get_next_line.c get_next_line_utils.c main.c

INCLUDE = ./

LIBFT = /Users/lily/libft

OBJ = $(SRC:.c=.o)

CC = gcc

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

%.o : %.c
	$(CC) $(FLAGS) -c $< -o $@ -I$(LIBFT)

$(NAME): $(OBJ) 
	$(CC) -o $(NAME) $(SRC) -I$(LIBFT) -L$(LIBFT) -lft
clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
