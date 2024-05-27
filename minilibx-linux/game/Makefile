# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bmota-si <bmota-si@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/17 12:06:49 by bmota-si          #+#    #+#              #
#    Updated: 2023/05/25 16:46:45 by bmota-si         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
SRCS = main.c map.c utils.c move.c free.c \
		check.c check2.c coordenates.c\

LIBFT = ../libft/libft.a
MINILIBX = ../minilibx-linux/libmlx_Linux.a

CC = cc -g
CFLAGS = -Wall -Wextra -Werror
MFLAGS = -lX11 -lXext
RM = rm -rf

OBJS = $(SRCS:%.c=%.o)

all: $(NAME)

$(LIBFT):
	$(MAKE) -C ../libft

$(MINILIBX):
	$(MAKE) -C ../minilibx-linux

$(NAME): $(OBJS) $(LIBFT) $(MINILIBX)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MINILIBX) -o $(NAME) -lX11 -lXext

clean:
	$(MAKE) clean -C ../libft
	$(MAKE) clean -C ../minilibx-linux
	$(RM) $(OBJS)

fclean: clean
	$(MAKE) fclean -C ../libft
	$(MAKE) clean -C ../minilibx-linux
	$(RM) $(NAME)

re: fclean all
