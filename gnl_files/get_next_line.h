/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abronn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 10:48:14 by abronn            #+#    #+#             */
/*   Updated: 2021/02/02 10:48:14 by abronn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

size_t		ft_strlen(const char *str);
char		*ft_strchr(char *str, char ch);
char		*ft_strdup(const char *str);
void		*ft_memmove(void *destination, const void *source, size_t n);
void		*ft_memcpy(void *destination, const void *source, size_t n);
char		*ft_strjoin(char const *s1, char const *s2);
int			proverim(char **v, char **line);
int			perenos(int fd, char **x, char **v, char **line);
int			get_next_line(int fd, char **line);

#endif
