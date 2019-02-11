/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sample.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-bast <lle-bast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 14:54:44 by lle-bast          #+#    #+#             */
/*   Updated: 2019/02/01 18:46:44 by lle-bast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			parsing(char *line, int place)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] != '.' && line[i] != '#' && line[i] != '\n')
			return (PARSING_ERROR_1);
		i++;
	}
	if (i == 0 && place != 1)
		return (0);
	if (i != 4)
		return (PARSING_ERROR_2);
	return (0);
}

int			fill_tetri(int i, char **line, t_tetri **node)
{
	if (i == 0)
		return (1);
	else
		(*node)->tab[i - 1] = ft_strdup(*line);
	if (i == 4)
		return (check_shape(node));
	return (0);
}

int			check_shape(t_tetri **node)
{
	int			i;
	int			j;
	int			di;
	static int	link = 0;

	i = 0;
	di = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if ((*node)->tab[i][j] == '#')
			{
				link = check_link(node, i, j, link);
				di++;
			}
			j++;
		}
		i++;
	}
	if ((link != 3 && link != 4) || di != 4)
		return (WRONG_SHAPE);
	link = 0;
	return (0);
}

int			check_link(t_tetri **node, int i, int j, int link)
{
	if ((*node)->tab[i][j + 1] == '#')
		link++;
	if (i < 3)
		if ((*node)->tab[i + 1][j] == '#')
			link++;
	return (link);
}

int			from_dz_to_lttr(t_tetri **node)
{
	int			i;
	int			j;
	static int	cpt = 0;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if ((*node)->tab[i][j] == '#')
				(*node)->tab[i][j] = ('A' + cpt);
			j++;
		}
		i++;
	}
	cpt++;
	return (0);
}
