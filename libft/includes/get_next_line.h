/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-bast <lle-bast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 14:36:30 by lle-bast          #+#    #+#             */
/*   Updated: 2019/01/18 19:44:27 by lle-bast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 10

# include <stdio.h>
# include "libft.h"

int			get_next_line(const int fd, char **line);
int			el_free(char **line, char **stock);
char		*upgrade_line(char **line, int i);
int			fill_line(char *str, char **stock, char **line, int k);
int			check_init(int fd, char **line, char **stock);

#endif
