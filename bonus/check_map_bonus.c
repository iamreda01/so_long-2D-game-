/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-kass <rel-kass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 01:28:46 by rel-kass          #+#    #+#             */
/*   Updated: 2025/01/22 23:24:05 by rel-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

char	*join_map(t_slg *data, char *str)
{
	char	*line;

	valid_struct(data);
	data->fd = open(str, O_RDONLY);
	if (data->fd < 0)
		print_error("Error\nUnable to open the map file!", data);
	data->join = ft_calloc(1, 1);
	line = get_next_line(data->fd);
	while (line)
	{
		if (line[0] == '\n')
			print_error("Error\nInvalid map line detected!", data);
		data->join = ft_strjoin(data->join, line);
		data->nline++;
		free (line);
		line = get_next_line(data->fd);
	}
	return (data->join);
}

void	rec_check(t_slg *data)
{
	int	i;

	valid_struct(data);
	i = 0;
	data->map = ft_split(data->join, '\n');
	if (!data->map)
		print_error("Error\nMemory allocation failed!", data);
	while (data->map[i + 1])
	{
		if ((ft_strlen(data->map[i]) - ft_strlen(data->map[i + 1])) != 0)
			print_error("Error\nThe map is not rectangular!", data);
		i++;
	}
}

void	check_walls(t_slg *data)
{
	int	i;
	int	j;

	valid_struct(data);
	i = 0;
	j = 0;
	if (!data->map[i])
		print_error("Error\nThe map is empty!", data);
	while (data->map[i + 1])
	{
		while (data->map[0][j])
		{
			if (data->map[0][j++] != '1')
				print_error("Error\nThe map must be surrounded by walls!",
					data);
		}
		if (data->map[i][0] != '1'
		|| data->map[i][ft_strlen(data->map[i]) - 1] != '1')
			print_error("Error\nThe map must be surrounded by walls!", data);
		i++;
	}
	j = 0;
	while (data->map[i][j])
		if (data->map[i][j++] != '1')
			print_error("Error\nThe map must be surrounded by walls!", data);
}

void	elements_nbr(t_slg *data)
{
	if (data->element_count.p_count != 1 || data->element_count.e_count != 1
		|| data->element_count.c_count == 0 || data->element_count.w_count == 0
		|| data->element_count.en_count != 1)
		print_error("Error\nElement error in the map!", data);
}

void	check_elements(t_slg *data)
{
	int	i;

	(1) && (valid_struct(data), i = 0);
	while (data->join[i])
	{
		if (data->join[i] == 'P')
			data->element_count.p_count++;
		if (data->join[i] == 'E')
			data->element_count.e_count++;
		if (data->join[i] == 'C')
			data->element_count.c_count++;
		if (data->join[i] == '1')
			data->element_count.w_count++;
		if (data->join[i] == '0')
			data->element_count.b_count++;
		if (data->join[i] == 'N')
			data->element_count.en_count++;
		if (data->join[i] != 'P' && data->join[i] != 'C'
			&& data->join[i] != '0' && data->join[i] != '1'
			&& data->join[i] != 'E' && data->join[i] != 'N'
			&& data->join[i] != '\n')
			print_error("Error\nInvalid map element!", data);
		i++;
	}
	elements_nbr(data);
}
