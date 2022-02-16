/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-der <dvan-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 08:23:41 by dvan-der          #+#    #+#             */
/*   Updated: 2022/02/04 16:13:01 by dvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define SCREEN_W 1000
# define SCREEN_H 1000

# include "minilibx_macos/mlx.h"
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include "libft/libft.h"
# include "libft/get_next_line.h"

// STRUCTS:

typedef struct s_var
{
	int		height_map;
	int		width_map;
	float	pix_dist;
	int		x0;
	int		y0;
	int		z0;
	int		x1;
	int		y1;
	int		z1;
	int		dx;
	int		dy;
	int		dz;
	int		xs;
	int		ys;
}	t_var;

typedef struct s_camera
{
	float	zoom;
	float	x;
	float	y;
	float	size_z;
	float	a_x;
	float	a_y;
	float	a_z;
	float	max_z;
}	t_camera;

typedef struct s_fdf
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	float		***map;
	float		***copied_map;
	t_var		*var;
	t_camera	*camera;
}	t_fdf;

// FUNCTIONS:

int		ft_machine(char *argv[], t_fdf *fdf);

void	letsdraw(t_fdf *fdf);

void	calc_pix_dist(t_fdf *fdf, float x0, float y0);
void	apply_zoom(t_fdf *fdf, int x, int y);
void	rotation(t_fdf *fdf, int x, int y);
void	isometric_scale(t_fdf *fdf, int x, int y, float u);
void	translation(t_fdf *fdf, int x, int y, float u);

void	drawlines(t_fdf *fdf);
int		make_colour(t_fdf *fdf, int startx, int starty);
void	my_mlx_pixel_put(t_fdf *fdf, int x, int y, int color);

void	setup_controls(t_fdf *fdf);

int		key_press(int key, void *param);
void	make_black(t_fdf *fdf);

void	zoom(int key, void *param);
void	move(int key, void *param);
void	flatten(int key, void *param);
void	rotate(int key, void *param);

void	free_copied_map(t_fdf *fdf, float ***copied_map);

#endif
