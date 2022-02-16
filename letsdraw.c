/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   letsdraw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-der <dvan-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 08:23:51 by dvan-der          #+#    #+#             */
/*   Updated: 2022/01/28 10:18:22 by dvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static float	***copydata(t_fdf *fdf);
static void		convert(t_fdf *fdf);
static void		z_value(t_fdf *fdf, int x, int y);

void	letsdraw(t_fdf *fdf)
{
	fdf->copied_map = copydata(fdf);
	fdf->camera->max_z = 0;
	convert(fdf);
	drawlines(fdf);
	free_copied_map(fdf, fdf->copied_map);
	mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr, fdf->img, 0, 0);
	setup_controls(fdf);
	mlx_loop(fdf->mlx_ptr);
	return ;
}

static float	***copydata(t_fdf *fdf)
{
	float	***map;
	int		y;
	int		x;

	map = (float ***)malloc(fdf->var->height_map * sizeof(float **));
	ft_check_malloc(map);
	y = 0;
	while (y < fdf->var->height_map)
	{
		map[y] = (float **)malloc(fdf->var->width_map * sizeof(float **));
		ft_check_malloc(map[y]);
		x = 0;
		while (x < fdf->var->width_map)
		{
			map[y][x] = (float *)malloc(4 * sizeof(float));
			ft_check_malloc(map[y][x]);
			map[y][x][0] = fdf->map[y][x][0];
			map[y][x][1] = fdf->map[y][x][1];
			map[y][x][2] = fdf->map[y][x][2];
			x++;
		}
		y++;
	}
	return (map);
}

static void	convert(t_fdf *fdf)
{
	int			x;
	int			y;

	calc_pix_dist(fdf, fdf->copied_map[0][0][0], fdf->copied_map[0][0][1]);
	y = 0;
	while (y < fdf->var->height_map)
	{
		x = 0;
		while (x < fdf->var->width_map)
		{
			apply_zoom(fdf, x, y);
			z_value(fdf, x, y);
			rotation(fdf, x, y);
			isometric_scale(fdf, x, y, fdf->var->pix_dist);
			translation(fdf, x, y, fdf->var->pix_dist);
			x++;
		}
		y++;
	}
}

static void	z_value(t_fdf *fdf, int x, int y)
{
	if (fdf->camera->size_z > 0)
	{
		if (fdf->copied_map[y][x][3] > fdf->camera->max_z)
			fdf->camera->max_z = fdf->copied_map[y][x][3];
	}
	else
	{
		if (fdf->copied_map[y][x][3] < fdf->camera->max_z)
			fdf->camera->max_z = fdf->copied_map[y][x][3];
	}
	return ;
}

void	my_mlx_pixel_put(t_fdf *fdf, int x, int y, int color)
{
	char	*dst;

	dst = fdf->addr + (y * fdf->line_length + x * (fdf->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
