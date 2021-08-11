/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teppei <teppei@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 13:31:18 by tkitagaw          #+#    #+#             */
/*   Updated: 2021/08/11 16:00:59 by teppei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	my_mkline(char **line, char **save, char *nl, int ret)
{
	char	*tmp;

	*line = gnl_ft_strdup(*save);
	if (!(*line))
	{
		free(*save);
		return (1);
	}
	if (ret == 1)
	{
		tmp = gnl_ft_strdup(nl + 1);
		if (!tmp)
		{
			free(*save);
			return (1);
		}
		free(*save);
		*save = tmp;
	}
	else
		free(*save);
	return (0);
}

static int	my_chkline(char **line, char **save, int rc)
{
	int		ret;
	char	*nl;

	ret = 0;
	if (rc < 0)
	{
		free(*save);
		return (-1);
	}
	if (!*save)
	{
		*line = gnl_ft_strdup("");
		if (!(*line))
			return (-1);
		return (0);
	}
	nl = gnl_ft_strchr(*save, '\n');
	if (nl)
	{
		*nl = '\0';
		ret = 1;
	}
	if (my_mkline(line, save, nl, ret) == 0)
		return (ret);
	return (-1);
}

static int	my_mksave(char **save, char **buf)
{
	char	*tmp;

	if (!*save)
	{
		*save = gnl_ft_strdup(*buf);
		if (!(*save))
		{
			free(*buf);
			return (-1);
		}
	}
	else
	{
		tmp = gnl_ft_strjoin(*save, *buf);
		if (!tmp)
		{
			free(*save);
			free(*buf);
			return (-1);
		}
		free(*save);
		*save = tmp;
	}
	return (1);
}

int	get_next_line(int fd, char **line)
{
	static char	*save[256];
	char		*buf;
	int			rc;

	if (fd < 0 || fd == 1 || fd == 2 || !line || BUFFER_SIZE < 1)
		return (-1);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
	{
		free(save[fd]);
		return (-1);
	}
	rc = read(fd, buf, BUFFER_SIZE);
	while (rc > 0)
	{
		buf[rc] = '\0';
		if (my_mksave(&save[fd], &buf) == -1)
			return (-1);
		if (gnl_ft_strchr(save[fd], '\n'))
			break ;
		rc = read(fd, buf, BUFFER_SIZE);
	}
	free(buf);
	return (my_chkline(line, &save[fd], rc));
}
