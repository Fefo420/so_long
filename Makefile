# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fileonar <fileonar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/08 18:19:50 by fileonar          #+#    #+#              #
#    Updated: 2025/01/03 14:32:48 by fileonar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
LIBMLX = ./MLX42
CFLAGS = -Wall -Werror -Wextra -g
LIB = -lft -Llibft/ -lmlx42 -L$(LIBMLX)/build -lglfw
HEADER = -I $(LIBMLX)/include -I libft/

NAME = so_long
DEPS = so_long.h 
SRC = main.c misc.c get_map.c parse_map.c main_menu.c

OBJS = $(SRC:%.c=bin/%.o)

bin:
	@mkdir -p bin

all: clean_when_debug $(NAME)

bin/%.o : %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS) $(HEADER)

$(LIBMLX)/build/libmlx42.a:
	@git submodule update --init $(LIBMLX)
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

./libft/libft.a:
	@git submodule update --init ./libft
	@make -C ./libft

$(NAME): $(LIBMLX)/build/libmlx42.a ./libft/libft.a $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(LIB) -ldl $(HEADER) $(CFLAGS)


clean:
	@rm -fr bin/*

fclean: clean
	@rm -f $(NAME)


re: fclean all

.PHONY: all clean fclean re clean_when_debug

ifeq ($(DEBUG),1)
CFLAGS+=-g3
clean_when_debug: fclean
endif