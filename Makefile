# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lle-bast <lle-bast@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/23 16:34:57 by lle-bast          #+#    #+#              #
#    Updated: 2019/02/04 22:29:28 by lle-bast         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= fillit

SRC	=	main.c			\
		manage_sample.c	\
		debugingage.c	\
		manage_lst.c

OBJ		= $(addprefix ./obj/,$(SRC:.c=.o))

CC		= gcc
CFLAGS	=
GGGGCFLAGS	= -Wall -Wextra -Werror -g3

LIBFTA	= ./libft/libft.a
LIBINCL = -I ./libft/includes
LIBLINK	= -L ./libft -lft

all: obj $(LIBFTA) $(NAME)

obj:
	mkdir -p ./obj/

./obj/%.o:./srcs/%.c
	$(CC) $(CFLAGS) $(LIBINCL) -I includes -o $@ -c $<

$(LIBFTA):
	make -C ./libft

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LIBLINK)

clean:
	rm -rf ./obj/
	make -C ./libft clean

fclean: clean
	rm -rf $(NAME)
	make -C ./libft fclean

re: fclean all

.PHONY: all clean fclean re
