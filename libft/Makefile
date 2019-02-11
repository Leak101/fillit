# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lle-bast <lle-bast@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/23 16:34:57 by lle-bast          #+#    #+#              #
#    Updated: 2019/01/18 19:43:42 by lle-bast         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS += -Wall -Wextra -Werror

CFLAGS += -Iincludes/

NAME = libft.a

SRCS =		ft_strcpy.c		\
			ft_strnew.c		\
			ft_strclr.c		\
			ft_strdup.c		\
			get_next_line.c

OBJS = $(SRCS:.c=.o)

$(NAME):	 $(OBJS)
		ar rc $(NAME) $(OBJS)
		ranlib $(NAME)

all : $(NAME)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re: fclean all
