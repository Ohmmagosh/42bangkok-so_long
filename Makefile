# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: psuanpro <Marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/08 00:34:28 by psuanpro          #+#    #+#              #
#    Updated: 2022/09/15 03:45:27 by psuanpro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRC = so_long.c \
	map.c \
	checker.c \
	flood_fill.c \
	check_token.c \
	window.c \
	sprite.c \
	sprite_utils.c \
	
VAL= valgrind --leak-check=full

OBJS = $(SRC:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

MLXLIB = -Lmlx -lmlx -Llibft -Lgnl -framework OpenGL -framework AppKit

%.o: %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(SRC) $(OBJ) -Lmlx -lmlx -Llibft -Lgnl -framework OpenGL -framework AppKit -o $(NAME) 

all: $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)
	rm -rf a.out

re: fclean all

t: re
	./$(NAME) maps/simple_map.ber

cl:
	gcc *.c ./libft/*c ./gnl/*.c -o so_long
	valgrind --leak-check=full ./$(NAME) maps/simple_map.ber
g:
	gcc $(CFLAGS) *.c ./libft/*c ./gnl/*.c -Lmlx -lmlx -Llibft -Lgnl -framework OpenGL -framework AppKit -o so_long
	./$(NAME) maps/simple_map.ber

n:
	gcc -Wall -Wextra -Werror ./libft/*c ./gnl/*.c ./ft_printf/*.c $(SRC) $(MLXLIB) -o so_long -g

l:
	lldb ./$(NAME) ./maps/simple_map.ber
.PHONY: all clean fclean re 
