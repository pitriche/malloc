# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: brunomartin <brunomartin@student.42.fr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/07 14:27:46 by pitriche          #+#    #+#              #
#    Updated: 2021/04/21 12:49:58 by brunomartin      ###   ########.fr        #
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

FLAGS = -Wall -Wextra -Wconversion -Wuninitialized
CFLAGS = -c $(FLAGS) -fPIC
CINCLUDE = -I include


ifndef HOSTTYPE
HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

NAME = libft_malloc_$(HOSTTYPE).so
LINK_NAME = libft_malloc.so

SRC = \
ft_bzero.c			\
ft_memmove.c		\
ft_putstr_fd.c		\
ft_putstr.c			\
ft_putnbr_base_fd.c	\
ft_putnbr.c	\
\
ft_malloc_utils.c	\
show_alloc_mem.c	\
ft_malloc.c			\
ft_free.c			\
ft_realloc.c		\


OBJ_DIR = obj/
OBJ = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))

.PHONY: all clean fclean re


all: $(OBJ_DIR) $(NAME) $(LINK_NAME)
	@echo "$(CYAN)$(LINK_NAME) ready sir !$(RESET)"

$(LINK_NAME):
	@echo "$(CYAN)$(NAME) ready sir !$(RESET)"
	@ln -s $(NAME) $(LINK_NAME)

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
	@rm -f $(LINK_NAME)

re: fclean all

.PHONY: all, clean, fclean, re
