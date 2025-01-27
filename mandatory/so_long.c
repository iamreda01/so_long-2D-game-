/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-kass <rel-kass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 15:20:25 by rel-kass          #+#    #+#             */
/*   Updated: 2025/01/27 12:00:18 by rel-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_name(char *str)
{
	int	len;

	len = ft_strlen(str);
	if (len < 5)
	{
		ft_putstr("Error\nInvalid map name provided!");
		exit (0);
	}
	if (str[len - 1] != 'r' || str[len - 2] != 'e'
		|| str[len - 3] != 'b' || str[len - 4] != '.')
	{
		ft_putstr("Error\nInvalid map name provided!");
		exit (0);
	}
}

void	init_var(t_slg *data)
{
	data->mlx_ptr = NULL;
	data->win_ptr = NULL;
	data->textures[0] = NULL;
	data->textures[1] = NULL;
	data->textures[2] = NULL;
	data->textures[3] = NULL;
	data->textures[4] = NULL;
	data->fd = 0;
	data->map = NULL;
	data->element_count.p_count = 0;
	data->element_count.e_count = 0;
	data->element_count.c_count = 0;
	data->element_count.w_count = 0;
	data->element_count.b_count = 0;
	data->nline = 0;
	data->img_h = 0;
	data->img_w = 0;
	data->element_count.player_moves = 0;
}

void	create_win(t_slg *data)
{
	valid_struct(data);
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		print_error("Error\nFailed to establish connection with MLX!", data);
	data->win_width = ft_strlen(data->map[0]);
	data->win_height = data->nline;
	if (data->win_width >= 5120 || data->win_height >= 2880)
		print_error("Error\nWindow size is too large!", data);
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->win_width * 64,
			data->win_height * 64, "so_long");
	if (!data->win_ptr)
		print_error("Error\nFailed to create the window!", data);
	init_xpm(data);
	game_rendring(data);
	mlx_hook(data->win_ptr, 17, 0, &destroy_win, data);
	mlx_hook(data->win_ptr, 2, 0, &events_handling, data);
	mlx_loop(data->mlx_ptr);
}

int	main(int ac, char **av)
{
	t_slg	data;

	if (ac != 2)
	{
		ft_putstr("Error\nMap path is missing!");
		return (1);
	}
	init_var(&data);
	check_name(av[1]);
	join_map(&data, av[1]);
	rec_check(&data);
	check_walls(&data);
	check_elements(&data);
	find_pos(&data);
	create_win(&data);
	return (0);
}
