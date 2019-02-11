/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debugingage.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-bast <lle-bast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 18:08:47 by lle-bast          #+#    #+#             */
/*   Updated: 2019/01/24 17:12:28 by lle-bast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			kfkerror(int error)
{
	if (error == PARSING_ERROR_1)
		printf("Parsing error 1\n");
	else if (error == PARSING_ERROR_2)
		printf("Parsing error 2\n");
	else if (error == OPEN_ERROR)
		printf("Open error\n");
	else if (error == NB_PIECE_ERROR)
		printf("Nb piece error\n");
	else if (error == FALSE_NB_FILES)
		printf("tetri_file\n");
	else if (error == FALSE_NB_DIESES)
		printf("Wrong nb of dieses\n");
	else if (error == WRONG_SHAPE)
		printf("Shape error\n");
	return (-1);
}

void		debug_print(char *name, int print)
{
	if (print == 1)
		printf("%s\n", name);
}
