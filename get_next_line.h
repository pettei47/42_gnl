/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teppei <teppei@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 13:41:36 by tkitagaw          #+#    #+#             */
/*   Updated: 2021/08/11 16:00:28 by teppei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stddef.h>

# define BUFFER_SIZE 256

int		get_next_line(int fd, char **line);
char	*gnl_ft_strjoin(char const *s1, char const *s2);
size_t	gnl_ft_strlen(const char *s);
char	*gnl_ft_strdup(const char *src);
char	*gnl_ft_strchr(const char *s, int c);

#endif
