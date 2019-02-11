/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-bast <lle-bast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 14:57:36 by lle-bast          #+#    #+#             */
/*   Updated: 2019/02/04 22:29:35 by lle-bast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <limits.h>
# include <fcntl.h>
# include "libft.h"

# define OPEN_ERROR -2
# define PARSING_ERROR_1 -31
# define PARSING_ERROR_2 -32
# define NB_PIECE_ERROR -4
# define FALSE_NB_FILES -5
# define FALSE_NB_DIESES -6
# define WRONG_SHAPE -7
# define DEBUG_PRINT 0

typedef struct		s_tetri
{
	char			**tab;
	struct s_tetri	*next;
}					t_tetri;

/*
** debugingage.c
*/
void				debug_print(char *name, int print);
int					kfkerror(int error);

/*
** manage_sample.c
*/
int					parsing(char *line, int place);
int					fill_tetri(int i, char **line, t_tetri **node);
int					check_shape(t_tetri **node);
int					check_link(t_tetri **node, int i, int j, int link);

/*
** manage_lst.c
*/
void				tetri_add(t_tetri **lst, t_tetri *new_node);
t_tetri				*tetri_new();
void				lst_print(t_tetri **lst);
void				lst_free(t_tetri **lst);
int					from_dz_to_lttr(t_tetri **node);




#endif