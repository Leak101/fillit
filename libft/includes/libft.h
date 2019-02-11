/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-bast <lle-bast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 15:50:23 by lle-bast          #+#    #+#             */
/*   Updated: 2019/01/18 19:50:50 by lle-bast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <limits.h>
# include "get_next_line.h"

void				ft_strclr(char *s);
char				*ft_strcpy(char *dest, const char *src);
char				*ft_strnew(size_t size);
char				*ft_strdup(const char *src);

#endif
