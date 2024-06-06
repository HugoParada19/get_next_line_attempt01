/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htrindad <htrindad@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 14:10:50 by htrindad          #+#    #+#             */
/*   Updated: 2024/06/06 18:44:05 by htrindad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*get_buf(int fd, char *str)
{
	char	temp[BUFFER_SIZE + 1];
	int		chars_r;
	size_t	i;

	i = 0;
	while (i <= BUFFER_SIZE)
		temp[i++] = 0;
	chars_r = 1;
	while (!ft_strchr(temp, '\n') && chars_r)
	{
		chars_r = read(fd, temp, BUFFER_SIZE);
		if (chars_r < 0 || (!chars_r && !str))
			return (NULL);
		temp[chars_r] = 0;
		if (str == NULL)
			str = ft_strdup(temp);
		else
			str = ft_strjoin(str, temp);
		if (str == NULL)
			return (NULL);
	}
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*next_l = NULL;
	int			i;
	char		*string_r;
	char		*post_str;

	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, 0, 0) < 0)
		return (NULL);
	next_l = get_buf(fd, next_l);
	if (next_l == NULL)
		return (NULL);
	i = 0;
	while (next_l[i] != '\n' && next_l[i])
		i++;
	if (next_l[i] == '\n')
		i++;
	string_r = ft_substr(next_l, 0, i);
	post_str = ft_substr(next_l, i, ft_strlen(next_l) - i);
	free(next_l);
	next_l = post_str;
	return (string_r);
}
/*
#include <fcntl.h>
#include <stdio.h>

int main()
{
	int		fd;
	const int	times = 4;
	char	*str;

	fd = open("test.txt", O_RDONLY);
	for (int i = 0; i < times; i++)
	{
		printf("%s\n", str = get_next_line(fd));
		free(str);
	}
}
*/
