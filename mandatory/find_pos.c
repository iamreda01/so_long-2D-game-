/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_pos.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-kass <rel-kass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 15:12:49 by rel-kass          #+#    #+#             */
/*   Updated: 2025/01/22 15:13:18 by rel-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	find_pos_x(t_slg *data, char c, int x, int y)
{
	x = 0;
	while (data->map[x])
	{
		y = 0;
		while (data->map[x][y])
		{
			if (data->map[x][y] == c)
				break ;
			y++;
		}
		if (data->map[x][y] == c)
			break ;
		x++;
	}
	return (x);
}

int	find_pos_y(t_slg *data, char c, int x, int y)
{
	x = 0;
	while (data->map[x])
	{
		y = 0;
		while (data->map[x][y])
		{
			if (data->map[x][y] == c)
				break ;
			y++;
		}
		if (data->map[x][y] == c)
			break ;
		x++;
	}
	return (y);
}
