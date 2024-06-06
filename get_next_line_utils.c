/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htrindad <htrindad@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 14:39:27 by htrindad          #+#    #+#             */
/*   Updated: 2024/06/06 18:13:21 by htrindad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char const *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(char const *s)
{
	char	*str;
	size_t	i;

	str = malloc(ft_strlen(s) + 1);
	if (str == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = 0;
	return (str);
}

char	*ft_strjoin(char *dest, char const *src)
{
	char	*ptr;
	size_t	i;
	size_t	j;

	ptr = malloc(ft_strlen(dest) + ft_strlen(src) + 1);
	if (ptr == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (dest[i])
	{
		ptr[i] = dest[i];
		i++;
	}
	while (src[j])
	{
		ptr[i + j] = src[j];
		j++;
	}
	free(dest);
	ptr[i + j] = 0;
	return (ptr);
}

char	*ft_strchr(char const *str, int c)
{
	char	*ptr;

	if (str == NULL)
		return (NULL);
	ptr = (char *)str;
	while (*ptr)
	{
		if (*ptr == (char)c)
			return (ptr);
		ptr++;
	}
	if (!c)
		return (ptr);
	return (NULL);
}

char	*ft_substr(char const *str, size_t begin, size_t len)
{
	char	*ptr;
	size_t	i;

	if (!str || !len || begin >= ft_strlen(str))
		return (NULL);
	if (begin + len > ft_strlen(str))
		len = ft_strlen(str) - begin;
	ptr = malloc(len + 1);
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		ptr[i] = str[i + begin];
		i++;
	}
	ptr[i] = 0;
	return (ptr);
}
