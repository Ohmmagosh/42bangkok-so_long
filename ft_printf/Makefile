# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: psuanpro <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/01 23:10:55 by psuanpro          #+#    #+#              #
#    Updated: 2022/05/23 16:37:27 by psuanpro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a

SRCS	= ft_printf.c \
	  ft_printf_untils_c.c \
	  ft_printf_untils_n.c \
	  ft_printf_check.c

OBJS	= ft_printf.o \
	  ft_printf_untils_c.o \
	  ft_printf_untils_n.o \
	  ft_printf_check.o

LIB	= ar -rcs
CC	= gcc -Wall -Wextra -Werror
RM	= rm -rf

$(NAME): $(SRCS)
	$(CC) -c $(SRCS)
	$(LIB) $(NAME) $(OBJS)

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME) 

re:fclean all

.PHONY: all clean fclean re
