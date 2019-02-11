/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-bast <lle-bast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 19:12:50 by lle-bast          #+#    #+#             */
/*   Updated: 2019/01/17 16:56:19 by lle-bast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int			el_free(char **line, char **stock)
{
	if (line != NULL && *line != NULL)
	{
		free(*line);
		*line = NULL;
	}
	if (stock != NULL && *stock != NULL)
	{
		free(*stock);
		*stock = NULL;
	}
	return (-1);
}

char		*upgrade_line(char **line, int i)
{
	char	*str;
	int		j;

	j = 0;
	if (!(str = ft_strnew((i + 1) * (BUFF_SIZE + 1))))
		return (NULL);
	while ((*line)[j])
	{
		str[j] = (*line)[j];
		j++;
	}
	str[j] = '\0';
	free(*line);
	return (str);
}

int			fill_line(char *str, char **stock, char **line, int k)
{
	int		i;
	int		j;
	int		flag_stop;

	i = 0;
	j = 0;
	flag_stop = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n' && flag_stop == 0)
			flag_stop = 1;
		else if (flag_stop == 0)
			(*line)[k++] = str[i];
		else if (flag_stop == 1)
			(*stock)[j++] = str[i];
		i += 1;
	}
	(*stock)[j] = '\0';
	(*line)[k] = '\0';
	return (flag_stop == 1 ? -1 : k);
}

int			check_init(int fd, char **line, char **stock)
{
	if (fd < 0 || line == NULL)
		return (-1);
	if (!(*line = ft_strnew(BUFF_SIZE + 1)))
		return (el_free(line, stock));
	if (*stock == NULL)
	{
		if (!(*stock = ft_strnew(BUFF_SIZE + 1)))
			return (el_free(line, stock));
	}
	return (0);
}

int			get_next_line(const int fd, char **line)
{
	static char		*stock = NULL;
	char			buf[BUFF_SIZE + 1];
	int				i;
	int				k;
	int				ret;

	i = 0;
	k = 0;
	if (check_init(fd, line, &stock) == -1)
		return (-1);
	if (stock != NULL && ((k = fill_line(stock, &stock, line, k)) == -1))
		return (1);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		i += 1;
		if (k > 0 && (!(*line = upgrade_line(line, i))))
			return (el_free(line, &stock));
		if ((k = fill_line(&(buf[0]), &stock, line, k)) == -1)
			return (1);
	}
	if (ret < 0)
		return (el_free(line, &stock));
	el_free(NULL, &stock);
	return ((*line)[0] != '\0' ? 1 : 0);
}
