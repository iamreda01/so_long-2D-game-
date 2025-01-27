/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-kass <rel-kass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 15:25:33 by rel-kass          #+#    #+#             */
/*   Updated: 2025/01/22 14:26:16 by rel-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	srclen;
	size_t	i;
	int		j;

	srclen = ft_strlen(src);
	i = 0;
	j = 0;
	if (dstsize == 0)
		return (srclen);
	while (src[i] && i < dstsize - 1)
	{
		dst[j] = src[i];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (srclen);
}

void	ft_putnbr(int n)
{
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
	{
		n += 48;
		write(1, &n, 1);
	}
}

static int	intlen(long nbr)
{
	int	count;

	count = 0;
	if (nbr == 0)
		return (1);
	if (nbr < 0)
	{
		count++;
		nbr = -nbr;
	}
	while (nbr)
	{
		nbr /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*str;
	long	nbr;
	int		sign;
	int		len;

	nbr = n;
	len = intlen(nbr);
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	if (nbr < 0)
		sign = 1;
	else
		sign = 0;
	if (sign)
	{
		(1) && (str[0] = '-', nbr = -nbr);
	}
	str[len] = '\0';
	while (len > sign)
	{
		str[len - 1] = (nbr % 10) + 48;
		(1) && (nbr /= 10, len--);
	}
	return (str);
}
