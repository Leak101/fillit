/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-bast <lle-bast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 19:08:49 by lle-bast          #+#    #+#             */
/*   Updated: 2019/02/04 22:30:00 by lle-bast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			main(int ac, char **av)
{
	char	*line;
	t_tetri	*list;
	t_tetri	*node_cur;
	int		fd;
	int		flag;
	int		ret;
	int		i;
	int		err;

	ret = 0;
	err = 0;
	i = 1;
	flag = 1;
	if (ac != 2)
		return (kfkerror(FALSE_NB_FILES));
	if ((fd = open(av[1], O_RDONLY)) < 0)
		return (kfkerror(OPEN_ERROR));
	list = NULL;
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		if (i > 105)
			return (kfkerror(NB_PIECE_ERROR));
		if (flag == 1)
		{
			node_cur = tetri_new();
			tetri_add(&list, node_cur);
		}
		if ((err = parsing(line, i)) < 0)
			return (kfkerror(err));
		if ((flag = fill_tetri(i % 5, &line, &node_cur)) < 0)
			return (kfkerror(flag));
		if ((i % 5) == 4)
			from_dz_to_lttr(&node_cur);
		i++;
	}
	lst_print(&list);
	lst_free(&list);
	close(fd);
	printf("ok cool\n");
	return (0);
}
