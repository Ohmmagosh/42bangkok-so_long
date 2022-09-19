# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: psuanpro <Marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/08 00:34:28 by psuanpro          #+#    #+#              #
#    Updated: 2022/09/19 11:24:53 by psuanpro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
LIBDIR = ./libft
MLXDIR = ./mlx
SRC = so_long.c \
	map.c \
	checker.c \
	flood_fill.c \
	check_token.c \
	window.c \
	window_utils.c \
	sprite.c \
	sprite_utils.c \

OBJS = $(SRC:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror
MLXLIB = -Lmlx -lmlx -Llibft -lft -framework OpenGL -framework AppKit

%.o: %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

$(NAME): $(OBJ)
	make -C $(LIBDIR)
	make -C $(MLXDIR)
	$(CC) $(SRC) $(OBJ) -o $(NAME) $(MLXLIB)

all: $(NAME)

clean:
	rm -rf $(OBJS)
	make -C $(LIBDIR) clean
	make -C $(MLXDIR) clean

fclean: clean
	rm -rf $(NAME)
	make -C  $(LIBDIR) fclean

re: fclean all
	make -C $(LIBDIR) re
	make -C $(MLXDIR) re


.PHONY: all clean fclean re 
