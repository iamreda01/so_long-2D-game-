/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_moves_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-kass <rel-kass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 23:18:33 by rel-kass          #+#    #+#             */
/*   Updated: 2025/01/22 23:22:22 by rel-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	e_left(t_slg *data, int x, int y)
{
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	if (data->map[x][y - 1] != '1' && data->map[x][y - 1] != 'C'
		&& data->map[x][y - 1] != 'E')
	{
		if (data->map[x][y - 1] == 'P')
			print_error("Game Over: You lost!", data);
		data->map[x][y] = '0';
		data->map[x][y - 1] = 'N';
	}
	game_rendring(data);
}

void	e_right(t_slg *data, int x, int y)
{
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	if (data->map[x][y + 1] != '1' && data->map[x][y + 1] != 'C'
		&& data->map[x][y + 1] != 'E')
	{
		if (data->map[x][y + 1] == 'P')
			print_error("Game Over: You lost!", data);
		data->map[x][y] = '0';
		data->map[x][y + 1] = 'N';
	}
	game_rendring(data);
}

void	e_up(t_slg *data, int x, int y)
{
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	if (data->map[x - 1][y] != '1' && data->map[x - 1][y] != 'C'
		&& data->map[x - 1][y] != 'E')
	{
		if (data->map[x - 1][y] == 'P')
			print_error("Game Over: You lost!", data);
		data->map[x][y] = '0';
		data->map[x - 1][y] = 'N';
	}
	game_rendring(data);
}

void	e_down(t_slg *data, int x, int y)
{
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	if (data->map[x + 1][y] != '1' && data->map[x + 1][y] != 'C'
		&& data->map[x + 1][y] != 'E')
	{
		if (data->map[x + 1][y] == 'P')
			print_error("Game Over: You lost!", data);
		data->map[x][y] = '0';
		data->map[x + 1][y] = 'N';
	}
	game_rendring(data);
}
