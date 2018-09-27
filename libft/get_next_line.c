/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmashigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 10:02:49 by tmashigo          #+#    #+#             */
/*   Updated: 2018/09/24 10:02:55 by tmashigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_getline(int fd, char **part)
{
	char	*buff;
	char	*hold;
	int		bytes;

	if (!(buff = ft_strnew(sizeof(char) * BUFF_SIZE + 1)))
		return (-1);
	bytes = read(fd, buff, BUFF_SIZE);
	if (bytes > 0)
	{
		buff[bytes] = '\0';
		hold = ft_strjoin(*part, buff);
		if (!hold)
			return (-1);
		free(*part);
		*part = hold;
	}
	free(buff);
	return (bytes);
}

int			saves_line(char **line, char **endline, char **str)
{
	*line = ft_strsub(*str, 0, ft_strlen(*str) - ft_strlen(*endline));
	*endline = ft_strdup(*endline + 1);
	free(*str);
	*str = *endline;
	return (1);
}

int			get_next_line(const int fd, char **line)
{
	static char	*str;
	char		*endline;
	int			gl;

	if ((!str && (str = ft_strnew(sizeof(*str))) == NULL) || !line)
		return (-1);
	while (!(endline = ft_strchr(str, '\n')))
	{
		if ((gl = ft_getline(fd, &str)) == 0)
		{
			if (ft_strlen(str) == 0)
				return (0);
			str = ft_strjoin(str, "\n");
		}
		if (gl < 0)
			return (-1);
		else
			endline = ft_strchr(str, '\n');
	}
	return (saves_line(line, &endline, &str));
}
