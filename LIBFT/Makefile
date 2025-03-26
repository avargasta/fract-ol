# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anvargas <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/24 20:59:15 by anvargas          #+#    #+#              #
#    Updated: 2023/11/18 13:02:28 by anvargas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#VARIABLES

ARCHIVE_CMD = ar rcs
CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = libft.a

#SOURCE AND OBJECTS

SRC = 	ft_atoi.c \
	ft_isprint.c \
	ft_putchar_fd.c	\
	ft_striteri.c \
	ft_strnstr.c \
	ft_bzero.c \
	ft_itoa.c \
	ft_putendl_fd.c \
	ft_strjoin.c \
	ft_strrchr.c \
	ft_calloc.c \
	ft_memchr.c \
	ft_putnbr_fd.c \
	ft_strlcat.c \
	ft_strtrim.c \
	ft_isalnum.c \
	ft_memcmp.c \
	ft_putstr_fd.c \
	ft_strlcpy.c \
	ft_substr.c \
	ft_isalpha.c \
	ft_memcpy.c \
	ft_split.c \
	ft_strlen.c \
	ft_tolower.c \
	ft_isascii.c \
	ft_memmove.c \
	ft_strchr.c \
	ft_strmapi.c \
	ft_toupper.c \
	ft_isdigit.c \
	ft_memset.c \
	ft_strdup.c \
	ft_strncmp.c

BONUSRC =	ft_lstnew_bonus.c \
		ft_lstadd_front_bonus.c \
		ft_lstsize_bonus.c \
		ft_lstlast_bonus.c \
		ft_lstadd_back_bonus.c \
		ft_lstdelone_bonus.c \
		ft_lstclear_bonus.c \
		ft_lstiter_bonus.c

OBJ = $(SRC:.c=.o)

BONUSOBJ = $(BONUSRC:.c=.o)

#RULES

all: $(NAME)

$(NAME): $(OBJ)
	$(ARCHIVE_CMD) $(NAME) $(OBJ)

bonus: $(OBJ) $(BONUSOBJ)
	$(ARCHIVE_CMD) $(NAME) $(BONUSOBJ) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJ) $(BONUSOBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

rebonus: fclean bonus

.PHONY: all clean fclean re rebonus
