/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-kass <rel-kass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 21:58:24 by rel-kass          #+#    #+#             */
/*   Updated: 2025/01/22 21:58:41 by rel-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	free_map(t_slg *data)
{
	int	i;

	i = 0;
	if (!data->map)
		return ;
	while (data->map[i])
	{
		free(data->map[i]);
		i++;
	}
	free(data->map);
}

void	free_str(t_slg *data)
{
	if (!data->join)
		return ;
	free(data->join);
}

void	free_map_cpy(t_slg *data)
{
	int	i;

	i = 0;
	if (!data->map_copy)
		return ;
	while (data->map_copy[i])
	{
		free(data->map_copy[i]);
		i++;
	}
	free(data->map_copy);
}

void	free_func(t_slg *data)
{
	if (data->map)
		free_map(data);
	if (data->join)
		free_str(data);
	if (data->map_copy)
		free_map_cpy(data);
}
