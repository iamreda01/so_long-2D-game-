/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-kass <rel-kass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 00:10:28 by rel-kass          #+#    #+#             */
/*   Updated: 2025/01/22 13:53:44 by rel-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	destroy_win(t_slg *data)
{
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	free(data->mlx_ptr);
	ft_putstr("Exiting the game...");
	exit (0);
}

void	move_up(t_slg *data, int x, int y)
{
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	if (data->map[x - 1][y] != '1')
	{
		if (data->map[x - 1][y] == 'C')
			data->element_count.c_count--;
		if (data->map[x - 1][y] == 'E' && !data->element_count.c_count)
		{
			print_error("YOU WON!", data);
			data->element_count.player_moves++;
		}
		if (data->map[x - 1][y] == 'N')
		{
			print_error("Game Over: You lost!", data);
			data->element_count.player_moves++;
		}
		if (data->map[x - 1][y] != 'E')
		{
			data->map[x][y] = '0';
			data->map[x - 1][y] = 'P';
			data->element_count.player_moves++;
		}
	}
	game_rendring(data);
}

void	move_down(t_slg *data, int x, int y)
{
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	if (data->map[x + 1][y] != '1')
	{
		if (data->map[x + 1][y] == 'C')
			data->element_count.c_count--;
		if (data->map[x + 1][y] == 'E' && !data->element_count.c_count)
		{
			print_error("YOU WON!", data);
			data->element_count.player_moves++;
		}
		if (data->map[x + 1][y] == 'N')
		{
			print_error("Game Over: You lost!", data);
			data->element_count.player_moves++;
		}
		if (data->map[x + 1][y] != 'E')
		{
			data->map[x][y] = '0';
			data->map[x + 1][y] = 'P';
			data->element_count.player_moves++;
		}
	}
	game_rendring(data);
}

void	move_right(t_slg *data, int x, int y)
{
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	if (data->map[x][y + 1] != '1')
	{
		if (data->map[x][y + 1] == 'C')
			data->element_count.c_count--;
		if (data->map[x][y + 1] == 'E' && !data->element_count.c_count)
		{
			print_error("YOU WON!", data);
			data->element_count.player_moves++;
		}
		if (data->map[x][y + 1] == 'N')
		{
			print_error("Game Over: You lost!", data);
			data->element_count.player_moves++;
		}
		if (data->map[x][y + 1] != 'E')
		{
			data->map[x][y] = '0';
			data->map[x][y + 1] = 'P';
			data->element_count.player_moves++;
		}
	}
	game_rendring(data);
}

void	move_left(t_slg *data, int x, int y)
{
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	if (data->map[x][y - 1] != '1')
	{
		if (data->map[x][y - 1] == 'C')
			data->element_count.c_count--;
		if (data->map[x][y - 1] == 'E' && !data->element_count.c_count)
		{
			print_error("YOU WON!", data);
			data->element_count.player_moves++;
		}
		if (data->map[x][y - 1] == 'N')
		{
			print_error("Game Over: You lost!", data);
			data->element_count.player_moves++;
		}
		if (data->map[x][y - 1] != 'E')
		{
			data->map[x][y] = '0';
			data->map[x][y - 1] = 'P';
			data->element_count.player_moves++;
		}
	}
	game_rendring(data);
}
