/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abronn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 21:39:56 by abronn            #+#    #+#             */
/*   Updated: 2021/01/25 21:39:56 by abronn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t		ft_strlen(const char *str)
{
	int i;

	i = 0;
	while (*(str++))
		i++;
	return (i);
}

char		*ft_strchr(char *str, char ch)
{
	if (ch == '\0')
		return (str + ft_strlen(str));
	while (*str != '\0')
	{
		if (*str == ch)
			return (str);
		str++;
	}
	return (0);
}

char		*ft_strdup(const char *str)
{
	char	*dest;
	char	*src;
	size_t	len;

	src = (char *)str;
	len = ft_strlen(src);
	dest = (char *)malloc(len + 1);
	if (dest == 0)
		return (0);
	return (ft_memcpy(dest, src, len + 1));
}

void		*ft_memmove(void *destination, const void *source, size_t n)
{
	unsigned char *dest;
	unsigned char *src;

	dest = (unsigned char *)destination;
	src = (unsigned char *)source;
	if (!dest && !src)
		return (destination);
	if (src < dest)
		while (n--)
			dest[n] = src[n];
	else
		while (n--)
			*(dest++) = *(src++);
	return (destination);
}

void		*ft_memcpy(void *destination, const void *source, size_t n)
{
	unsigned char *dest;
	unsigned char *src;

	dest = (unsigned char *)destination;
	src = (unsigned char *)source;
	if (!dest && !src)
		return (0);
	while (n--)
		*(dest++) = *(src++);
	return (destination);
}
