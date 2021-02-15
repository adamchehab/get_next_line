/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abronn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 10:48:14 by abronn            #+#    #+#             */
/*   Updated: 2021/02/02 10:48:14 by abronn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	size_t	l1;
	size_t	l2;
	char	*ptr;

	if (!s1 && !s2)
		return (ft_strdup(""));
	if (s1 && !s2)
		return (ft_strdup(s1));
	if (!s1 && s2)
		return (ft_strdup(s2));
	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	ptr = malloc(l1 + l2 + 1);
	if (!ptr)
		return (0);
	ft_memmove(ptr, s1, l1);
	ft_memmove(ptr + l1, s2, l2);
	ptr[l1 + l2] = '\0';
	return (ptr);
}

int			check_str_left(char **str_left, char **line)
{
	char *p_newline;
	char *tmp;

	if (*str_left == 0)
		return (1);
	if ((p_newline = ft_strchr(*str_left, '\n')))
	{
		*p_newline = '\0';
		tmp = *line;
		*line = ft_strdup(*str_left);
		free(tmp);
		tmp = *str_left;
		*str_left = ft_strdup(++p_newline);
		free(tmp);
		return (0);
	}
	else
	{
		tmp = *line;
		*line = ft_strjoin(*line, *str_left);
		free(*str_left);
		*str_left = 0;
		free(tmp);
		return (1);
	}
}

static int	copy(char **x, char **line)
{
	char *tmp;

	tmp = *line;
	*line = ft_strjoin(*line, *x);
	free(tmp);
	if (*line == 0)
	{
		free(*x);
		return (0);
	}
	return (1);
}

int			get_line(int fd, char **buff, char **str_left, char **line)
{
	int		res;
	int		read_byte;
	char	*p_newline;

	read_byte = 0;
	res = check_str_left(str_left, line);
	while (res == 1 && (read_byte = read(fd, *buff, BUFFER_SIZE)) > 0)
	{
		(*buff)[read_byte] = '\0';
		if ((p_newline = ft_strchr(*buff, '\n')))
		{
			*p_newline = '\0';
			*str_left = ft_strdup(++p_newline);
			if (!copy(buff, line))
				return (-1);
			free(*buff);
			return (1);
		}
		if (!copy(buff, line))
			return (-1);
	}
	free(*buff);
	if (read_byte < 0)
		return (-1);
	return ((res == 0) ? 1 : 0);
}

int			get_next_line(int fd, char **line)
{
	int			res;
	static char *str_left;
	char		*buff;

	if (!(buff = (char*)malloc(sizeof(char) * BUFFER_SIZE + 1)))
		return (-1);
	if (fd < 0 || BUFFER_SIZE <= 0 || !line || (read(fd, buff, 0)))
		return (-1);
	*line = ft_strdup("");
	res = get_line(fd, &buff, &str_left, line);
	if (res != 0)
		return ((res == 1) ? 1 : -1);
	return (0);
}
