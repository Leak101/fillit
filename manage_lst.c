/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_lst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-bast <lle-bast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 15:00:34 by lle-bast          #+#    #+#             */
/*   Updated: 2019/01/23 20:43:55 by lle-bast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		tetri_add(t_tetri **lst, t_tetri *new_node)
{
	debug_print("tetri_add debut", DEBUG_PRINT);
	if (*lst == NULL)
		*lst = new_node;
	else if ((*lst)->next == NULL)
		(*lst)->next = new_node;
	else
		tetri_add(&((*lst)->next), new_node);
	debug_print("tetri_add fin", DEBUG_PRINT);
}

t_tetri		*tetri_new(void)
{
	t_tetri		*node;

	debug_print("tetri_new debut", DEBUG_PRINT);
	if (!(node = malloc(sizeof(*node))))
		return (NULL);
	if (!(node->tab = malloc(sizeof(char*) * 5)))
		return (NULL);
	node->next = NULL;
	node->tab[0] = NULL;
	node->tab[1] = NULL;
	node->tab[2] = NULL;
	node->tab[3] = NULL;
	debug_print("tetri_new fin", DEBUG_PRINT);
	return (node);
}

void		lst_free(t_tetri **lst)
{
	int		i;
	t_tetri	*node_manip;
	t_tetri	*node_stock;

	debug_print("lst_free debut", DEBUG_PRINT);
	if (lst != NULL && *lst != NULL)
	{
		node_manip = *lst;
		while (node_manip != NULL)
		{
			node_stock = node_manip->next;
			i = 0;
			while (i < 4)
			{
				free(node_manip->tab[i]);
				node_manip->tab[i] = NULL;
				i++;
			}
			free(node_manip);
			node_manip = NULL;
			node_manip = node_stock;
		}
		*lst = NULL;
	}
	debug_print("lst_free fin", DEBUG_PRINT);
}

void		lst_print(t_tetri **lst)
{
	int		i;
	t_tetri	*node;

	debug_print("lst_print debut", DEBUG_PRINT);
	if (lst != NULL && *lst != NULL)
	{
		node = *lst;
		while (node != NULL)
		{
			i = 0;
			while (i < 4)
			{
				printf("%s\n", node->tab[i]);
				i++;
			}
			printf("\n");
			node = node->next;
		}
	}
	debug_print("lst_print fin", DEBUG_PRINT);
}
