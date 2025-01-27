/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-kass <rel-kass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 22:31:55 by rel-kass          #+#    #+#             */
/*   Updated: 2025/01/16 15:29:21 by rel-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*ptr;
	size_t			i;

	i = 0;
	if (count < 0 || size < 0)
		return (NULL);
	ptr = malloc(count * size);
	if (ptr == NULL)
		return (ptr);
	while (i < (size * count))
	{
		ptr[i] = '\0';
		i++;
	}
	return ((void *)ptr);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	unsigned char	uc;
	int				i;

	uc = (unsigned char)c;
	i = 0;
	while (s[i] && s[i] != uc)
		i++;
	if (s[i] != uc)
		return (NULL);
	return ((char *)(s + i));
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*uns_dst;
	unsigned char	*uns_src;
	size_t			i;

	uns_dst = (unsigned char *)dst;
	uns_src = (unsigned char *)src;
	i = 0;
	if (!dst && !src)
		return (NULL);
	if (src == dst)
		return (dst);
	while (i < n)
	{
		uns_dst[i] = uns_src[i];
		i++;
	}
	return (dst);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	size_t	s1len;
	size_t	s2len;

	if (!s1 || !s2)
		return (free(s1), NULL);
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	str = malloc(sizeof(char) * (s1len + s2len + 1));
	if (!str || !s1 || !s2)
		return (free(s1), NULL);
	ft_memcpy(str, s1, s1len);
	ft_memcpy((str + s1len), s2, s2len);
	str[s1len + s2len] = '\0';
	return (free(s1), str);
}
