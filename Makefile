# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: root <root@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/05 21:45:21 by anvargas          #+#    #+#              #
#    Updated: 2025/04/01 15:53:32 by root             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Variables
NAME := fractol


CC := gcc
#CFLAGS := -Wextra -Wall -Werror -Wunreachable-code -Ofast
CFLAGS := -Wextra -Wall -Wunreachable-code -Ofast


SRC := main.c init.c utils.c render.c zoom.c close.c
OBJ = $(SRC:.c=.o)


LIBMLX_DIR	:= ./MLX42
LIBFT_DIR := ./LIBFT

LIBMLX = $(LIBMLX_DIR)/build/libmlx42.a
LIBFT = $(LIBFT_DIR)/libft.a

LIBS := $(LIBMLX) -ldl -lglfw -pthread -lm $(LIBFT)

HEADERS	:= -I ./ -I $(LIBMLX_DIR)/include -I $(LIBFT_DIR)


#Rules
all: $(LIBMLX) $(LIBFT) $(NAME)

$(LIBMLX):
	@cmake $(LIBMLX_DIR) -B $(LIBMLX_DIR)/build && make -C $(LIBMLX_DIR)/build -j4

$(LIBFT):
	@make bonus -C $(LIBFT_DIR)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(LIBS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@

clean:
	@rm -rf $(OBJ)
	@rm -rf $(LIBMLX_DIR)/build
	@make -C $(LIBFT_DIR) clean

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re, libmlx, libft
