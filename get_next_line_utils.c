/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teppei <teppei@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 14:09:24 by tkitagaw          #+#    #+#             */
/*   Updated: 2021/08/11 16:01:35 by teppei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	gnl_ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*gnl_ft_strdup(const char *src)
{
	char	*dest;
	int		src_len;
	int		i;

	src_len = gnl_ft_strlen(src);
	dest = (char *)malloc(sizeof(char) * (src_len + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (i < src_len)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*gnl_ft_strchr(const char *s, int c)
{
	char	*out;

	out = (char *)s;
	while (*out)
	{
		if (*out == (char)c)
			return (out);
		out++;
	}
	if (*out == '\0' && c == '\0')
		return (out);
	return (0);
}

static	char	*gnl_ft_strcat(char *dst, char const *s)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (dst[i])
		i++;
	while (s[j])
	{
		dst[i + j] = s[j];
		j++;
	}
	dst[i + j] = '\0';
	return (dst);
}

char	*gnl_ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	len;

	if (!s1 || !s2)
		return (NULL);
	len = gnl_ft_strlen(s1) + gnl_ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[0] = '\0';
	gnl_ft_strcat(str, s1);
	gnl_ft_strcat(str, s2);
	return (str);
}
