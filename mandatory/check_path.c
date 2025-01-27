/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-kass <rel-kass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 00:24:02 by rel-kass          #+#    #+#             */
/*   Updated: 2025/01/22 22:25:44 by rel-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_path(t_slg *data, int x, int y)
{
	if (data->map_copy[x][y] == '1')
		return ;
	if (data->map_copy[x][y] == 'R')
		return ;
	if (data->map_copy[x][y] == 'E')
	{
		data->map_copy[x][y] = 'Z';
		return ;
	}
	data->map_copy[x][y] = 'R';
	check_path(data, x + 1, y);
	check_path(data, x - 1, y);
	check_path(data, x, y + 1);
	check_path(data, x, y - 1);
}

void	check_coll(t_slg *data)
{
	int	x;
	int	y;

	x = 0;
	if (!data->map_copy)
		print_error("Error\nMemory allocation failed!", data);
	while (data->map_copy[x])
	{
		y = 0;
		while (data->map_copy[x][y])
		{
			if (data->map_copy[x][y] == 'E')
				print_error("Error\nInvalid path in the map!", data);
			if (data->map_copy[x][y] == 'C')
				print_error("Error\nNot all collectibles were collected!",
					data);
			y++;
		}
		x++;
	}
}

void	find_pos(t_slg *data)
{
	int	x;
	int	y;

	valid_struct(data);
	x = 0;
	while (data->map[x])
	{
		y = 0;
		while (data->map[x][y])
		{
			if (data->map[x][y] == 'P')
				break ;
			y++;
		}
		if (data->map[x][y] == 'P')
			break ;
		x++;
	}
	data->map_copy = ft_split(data->join, '\n');
	check_path(data, x, y);
	check_coll(data);
}
