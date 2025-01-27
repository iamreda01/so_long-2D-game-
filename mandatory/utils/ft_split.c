/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-kass <rel-kass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 13:02:47 by rel-kass          #+#    #+#             */
/*   Updated: 2025/01/13 13:11:25 by rel-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static size_t	countword(char const *s, char c)
{
	size_t	count;
	int		inside_word;

	count = 0;
	while (*s)
	{
		inside_word = 0;
		while (*s && *s == c)
			s++;
		while (*s && *s != c)
		{
			if (*s != c && !inside_word)
			{
				inside_word = 1;
				count++;
			}
			s++;
		}
	}
	return (count);
}

static int	safemalloc(char **str, int pst, size_t len)
{
	str[pst] = malloc(sizeof(char) * len);
	if (!str[pst])
	{
		if (pst > 0)
			pst--;
		while (pst >= 0)
		{
			free(str[pst]);
			pst--;
		}
		free(str);
		return (0);
	}
	return (1);
}

static int	fill(char **str, const char *s, char c)
{
	size_t	len;
	int		i;

	i = 0;
	while (*s)
	{
		len = 0;
		while (*s && *s == c)
			s++;
		while (*s && *s != c)
		{
			len++;
			s++;
		}
		if (len)
		{
			if (!safemalloc(str, i, len +1))
				return (0);
			ft_strlcpy(str[i], (s - len), len + 1);
		}
		i++;
	}
	return (1);
}

char	**ft_split(char *s, char c)
{
	char	**str;
	size_t	words;

	if (!s)
		return (NULL);
	words = countword(s, c);
	str = malloc(sizeof(char *) * (words + 1));
	if (!str)
		return (NULL);
	str[words] = NULL;
	if (!fill(str, s, c))
		return (NULL);
	return (str);
}
