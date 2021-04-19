# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: user42 <user42@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/07 14:27:46 by pitriche          #+#    #+#              #
#    Updated: 2021/04/18 15:52:03 by user42           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GREY    = \033[030m
RED     = \033[031m
GREEN   = \033[032m
YELLOW  = \033[033m
BLUE    = \033[034m
MAGENTA = \033[035m
CYAN	= \033[036m
RESET   = \033[0m

# **************************************************************************** #

CC = gcc

FLAGS = -Wall -Werror -Wextra
CFLAGS = -c $(FLAGS) -fPIC
CINCLUDE = -I include

NAME = libft_malloc_$(HOSTTYPE).so

SRC = \
ft_bzero.c		\
ft_memmove.c	\
ft_putstr_fd.c	\
ft_putstr.c		\


# \
ft_malloc.c			\
ft_realloc.c		\
show_alloc_mem.c	\

OBJ_DIR = obj/
OBJ = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))

.PHONY: all clean fclean re

all: $(OBJ_DIR) $(NAME)
	@echo "$(CYAN)$(NAME) ready sir !$(RESET)"

$(NAME): $(OBJ)
	@gcc -shared -o $@ $^

$(addprefix $(OBJ_DIR), %.o) : %.c
	@$(CC) $(CINCLUDE) $(CFLAGS) -o $@ $<
	@echo -n '.'

$(OBJ_DIR) :
	@mkdir $(OBJ_DIR)

clean:
	@rm -f $(OBJ)
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re
