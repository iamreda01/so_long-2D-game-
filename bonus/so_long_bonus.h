/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-kass <rel-kass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 22:55:03 by rel-kass          #+#    #+#             */
/*   Updated: 2025/01/22 22:29:34 by rel-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

// headers ;
# include <stdlib.h>
# include <unistd.h>
# include <mlx.h>
# include "utils/get_next_line_bonus.h"
# include <libc.h>
# include <fcntl.h>

// structs;
typedef struct element_count
{
	int	p_count;
	int	c_count;
	int	e_count;
	int	w_count;
	int	b_count;
	int	player_moves;
	int	en_count;
	int	timer;
}	t_elements;

typedef struct so_long
{
	t_elements	element_count;
	void		*mlx_ptr;
	void		*win_ptr;
	char		*textures[6];
	char		*img_ptr;
	int			win_width;
	int			win_height;
	char		**map;
	char		**map_copy;
	int			fd;
	char		*join;
	int			nline;
	int			img_w;
	int			img_h;
}	t_slg;

// utils;
void	ft_putstr(char *s);
void	ft_putnbr(int n);
char	**ft_split(char *s, char c);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*ft_itoa(int n);
int		find_pos_x(t_slg *data, char c, int x, int y);
int		find_pos_y(t_slg *data, char c, int x, int y);

//map_check_funcs
void	init_var(t_slg *data);
void	check_name(char *str);
char	*join_map(t_slg *data, char *str);
void	rec_check(t_slg *data);
void	check_walls(t_slg *data);
void	check_elements(t_slg *data);
void	elements_nbr(t_slg *data);
void	find_pos(t_slg *data);
void	check_path(t_slg *data, int x, int y);
void	check_coll(t_slg *data);

// game_ren;
void	create_win(t_slg *data);
void	init_xpm(t_slg *data);
char	*get_image(t_slg *data, int x, int y);
void	game_rendring(t_slg *data);
void	quit(t_slg *data);

// events
int		destroy_win(t_slg *data);
int		events_handling(int key_code, t_slg *data);
void	move_up(t_slg *data, int x, int y);
void	move_down(t_slg *data, int x, int y);
void	move_right(t_slg *data, int x, int y);
void	move_left(t_slg *data, int x, int y);

// enemy;
int		enemy_moves(t_slg *data);
void	e_left(t_slg *data, int x, int y);
void	e_right(t_slg *data, int x, int y);
void	e_up(t_slg *data, int x, int y);
void	e_down(t_slg *data, int x, int y);
void	enemy_random_moves(t_slg *data, int x, int y);

//errors
void	print_error(char *str, t_slg *data);
void	free_map(t_slg *data);
void	free_str(t_slg *data);
void	free_func(t_slg *data);
void	valid_struct(t_slg *data);

#endif