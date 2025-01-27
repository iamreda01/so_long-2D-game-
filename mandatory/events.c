/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-kass <rel-kass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 15:12:37 by rel-kass          #+#    #+#             */
/*   Updated: 2025/01/22 15:12:41 by rel-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
			ft_putstr("moves : ");
			ft_putnbr(data->element_count.player_moves);
			ft_putstr("\n");
		}
		if (data->map[x - 1][y] != 'E')
		{
			data->map[x][y] = '0';
			data->map[x - 1][y] = 'P';
			data->element_count.player_moves++;
			ft_putstr("moves : ");
			ft_putnbr(data->element_count.player_moves);
			ft_putstr("\n");
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
			ft_putstr("moves : ");
			ft_putnbr(data->element_count.player_moves);
			ft_putstr("\n");
		}
		if (data->map[x + 1][y] != 'E')
		{
			data->map[x][y] = '0';
			data->map[x + 1][y] = 'P';
			data->element_count.player_moves++;
			ft_putstr("moves : ");
			ft_putnbr(data->element_count.player_moves);
			ft_putstr("\n");
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
			ft_putstr("moves : ");
			ft_putnbr(data->element_count.player_moves);
			ft_putstr("\n");
		}
		if (data->map[x][y + 1] != 'E')
		{
			data->map[x][y] = '0';
			data->map[x][y + 1] = 'P';
			data->element_count.player_moves++;
			ft_putstr("moves : ");
			ft_putnbr(data->element_count.player_moves);
			ft_putstr("\n");
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
			ft_putstr("moves : ");
			ft_putnbr(data->element_count.player_moves);
			ft_putstr("\n");
		}
		if (data->map[x][y - 1] != 'E')
		{
			data->map[x][y] = '0';
			data->map[x][y - 1] = 'P';
			data->element_count.player_moves++;
			ft_putstr("moves : ");
			ft_putnbr(data->element_count.player_moves);
			ft_putstr("\n");
		}
	}
	game_rendring(data);
}
