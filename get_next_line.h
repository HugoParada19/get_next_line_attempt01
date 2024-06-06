/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htrindad <htrindad@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 14:09:18 by htrindad          #+#    #+#             */
/*   Updated: 2024/06/06 18:30:53 by htrindad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <string.h>
# include <unistd.h>

size_t	ft_strlen(char const *s);
char	*ft_strdup(char const *s);
char	*ft_strjoin(char *dest, char const *src);
char	*ft_strchr(char const *str, int c);
char	*get_next_line(int fd);
char	*ft_substr(char const *str, size_t begin, size_t len);

#endif
