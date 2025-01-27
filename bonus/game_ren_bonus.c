/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_ren_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-kass <rel-kass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 01:41:37 by rel-kass          #+#    #+#             */
/*   Updated: 2025/01/22 22:29:34 by rel-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	init_xpm(t_slg *data)
{
	data->textures[0] = mlx_xpm_file_to_image(data->mlx_ptr, "img/path.xpm",
			&data->img_w, &data->img_h);
	data->textures[1] = mlx_xpm_file_to_image(data->mlx_ptr, "img/wall.xpm",
			&data->img_w, &data->img_h);
	data->textures[2] = mlx_xpm_file_to_image(data->mlx_ptr, "img/player.xpm",
			&data->img_w, &data->img_h);
	data->textures[3] = mlx_xpm_file_to_image(data->mlx_ptr, "img/coll.xpm",
			&data->img_w, &data->img_h);
	data->textures[4] = mlx_xpm_file_to_image(data->mlx_ptr, "img/exit.xpm",
			&data->img_w, &data->img_h);
	data->textures[5] = mlx_xpm_file_to_image(data->mlx_ptr, "img/enemy.xpm",
			&data->img_w, &data->img_h);
	if (!data->textures[0] || !data->textures[1] || !data->textures[2]
		|| !data->textures[3] || !data->textures[4] || !data->textures[5])
		print_error("Error\nFailed to load XPM file!", data);
}

char	*get_image(t_slg *data, int x, int y)
{
	if (data->map[x][y] == '0')
		return (data->textures[0]);
	if (data->map[x][y] == '1')
		return (data->textures[1]);
	if (data->map[x][y] == 'P')
		return (data->textures[2]);
	if (data->map[x][y] == 'C')
		return (data->textures[3]);
	if (data->map[x][y] == 'E')
		return (data->textures[4]);
	if (data->map[x][y] == 'N')
		return (data->textures[5]);
	return (NULL);
}

void	game_rendring(t_slg *data)
{
	char	*str;
	int		x;
	int		y;

	x = 0;
	while (data->map[x])
	{
		y = 0;
		while (data->map[x][y])
		{
			data->img_ptr = get_image(data, x, y);
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr,
				y * 64, x * 64);
			y++;
		}
		x++;
	}
	str = ft_itoa(data->element_count.player_moves);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 10, 0xffffff, str);
	free(str);
}

void	quit(t_slg *data)
{
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	free (data->mlx_ptr);
	ft_putstr("Exiting the game...");
	exit (0);
}

int	events_handling(int key_code, t_slg *data)
{
	int	x;
	int	y;

	(1) && (x = 0, y = 0);
	x = find_pos_x(data, 'P', x, y);
	y = find_pos_y(data, 'P', x, y);
	if (key_code == 53)
		quit(data);
	if (key_code == 13)
		move_up(data, x, y);
	if (key_code == 1)
		move_down(data, x, y);
	if (key_code == 2)
	{
		data->textures[2] = mlx_xpm_file_to_image(data->mlx_ptr,
				"img/player.xpm", &data->img_w, &data->img_h);
		move_right(data, x, y);
	}
	if (key_code == 0)
	{
		data->textures[2] = mlx_xpm_file_to_image(data->mlx_ptr,
				"img/player_left.xpm", &data->img_w, &data->img_h);
		move_left(data, x, y);
	}
	return (0);
}
