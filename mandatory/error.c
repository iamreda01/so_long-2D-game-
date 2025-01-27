/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-kass <rel-kass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 15:11:36 by rel-kass          #+#    #+#             */
/*   Updated: 2025/01/22 22:25:44 by rel-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	valid_struct(t_slg *data)
{
	if (!data)
	{
		ft_putstr("Error\nStruct is set to NULL!");
		exit (1);
	}
}

void	print_error(char *str, t_slg *data)
{
	ft_putstr(str);
	if (data->fd >= 0)
		close(data->fd);
	free_func(data);
	exit (1);
}
