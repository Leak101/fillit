/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-bast <lle-bast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 14:54:17 by lle-bast          #+#    #+#             */
/*   Updated: 2018/05/30 18:47:27 by lle-bast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	size_t	i;
	char	*tkn;

	i = 0;
	if (!(tkn = malloc(sizeof(*tkn) * size + 1)))
		return (NULL);
	while (i < size)
	{
		tkn[i] = '\0';
		i++;
	}
	tkn[i] = '\0';
	return (tkn);
}
