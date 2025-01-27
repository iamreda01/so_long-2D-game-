/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_patrol.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-kass <rel-kass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 00:06:29 by rel-kass          #+#    #+#             */
/*   Updated: 2025/01/22 13:53:44 by rel-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	enemy_random_moves(t_slg *data, int x, int y)
{
	int	e_moves;

	e_moves = (rand() % 4);
	if (data->element_count.timer == 3000)
	{
		if (e_moves == 0)
		{
			data->textures[5] = mlx_xpm_file_to_image(data->mlx_ptr,
					"img/enemy_left.xpm", &data->img_w, &data->img_h);
			e_left(data, x, y);
		}
		if (e_moves == 1)
		{
			data->textures[5] = mlx_xpm_file_to_image(data->mlx_ptr,
					"img/enemy.xpm", &data->img_w, &data->img_h);
			e_right(data, x, y);
		}
		if (e_moves == 2)
			e_up(data, x, y);
		if (e_moves == 3)
			e_down(data, x, y);
	}
}

int	enemy_moves(t_slg *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	x = find_pos_x(data, 'N', x, y);
	y = find_pos_y(data, 'N', x, y);
	enemy_random_moves(data, x, y);
	data->element_count.timer++;
	if (data->element_count.timer > 3000)
		data->element_count.timer = -1;
	return (0);
}
