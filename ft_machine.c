/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_machine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-der <dvan-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 08:23:44 by dvan-der          #+#    #+#             */
/*   Updated: 2022/02/04 16:22:49 by dvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_var	*input_handler(char *input);
static float	***make_map(char *input, int width_map, int height_map);
static void		fill_row(float ***map, int y, int width_map, char **split_str);
static t_camera	*camera_set(void);

int	ft_machine(char *argv[], t_fdf *fdf)
{
	fdf->var = input_handler(argv[1]);
	if (!fdf->var)
		return (1);
	fdf->map = make_map(argv[1], fdf->var->width_map, fdf->var->height_map);
	ft_check_malloc(fdf->map);
	fdf->camera = camera_set();
	letsdraw(fdf);
	return (0);
}

static t_var	*input_handler(char *input)
{
	t_var	*var;
	char	*str;
	int		fd;

	var = (t_var *)malloc(sizeof(t_var));
	ft_check_malloc(var);
	fd = open(input, O_RDONLY);
	if (fd < 0 | fd > 1024)
	{
		free(var);
		return (NULL);
	}
	str = get_next_line(fd);
	var->width_map = ft_count_splits(str, ' ');
	var->height_map = 0;
	while (str)
	{
		free(str);
		(var->height_map)++;
		str = get_next_line(fd);
	}
	close(fd);
	return (var);
}

static float	***make_map(char *input, int width_map, int height_map)
{
	float	***map;
	char	**split_str;
	char	*str;
	int		y;
	int		fd;

	fd = open(input, O_RDONLY);
	if (fd < 0 | fd > 1024)
		return (NULL);
	map = (float ***)malloc(height_map * sizeof(float **));
	ft_check_malloc(map);
	y = 0;
	while (y < height_map)
	{
		str = get_next_line(fd);
		split_str = ft_split(str, ' ');
		map[y] = (float **)malloc(width_map * sizeof(float **));
		ft_check_malloc(map[y]);
		fill_row(map, y, width_map, split_str);
		free(str);
		ft_free_split_str(split_str);
		y++;
	}
	close(fd);
	return (map);
}

static void	fill_row(float ***map, int y, int width_map, char **split_str)
{
	int	x;

	x = 0;
	while (x < width_map)
	{
		map[y][x] = (float *)malloc(3 * sizeof(float));
		ft_check_malloc(map[y][x]);
		map[y][x][0] = (float)x;
		map[y][x][1] = (float)y;
		map[y][x][2] = (float)ft_atoi(split_str[x]);
		x++;
	}
	return ;
}

static t_camera	*camera_set(void)
{
	t_camera	*camera;

	camera = (t_camera *)malloc(sizeof(t_camera));
	ft_check_malloc(camera);
	camera->zoom = 1;
	camera->size_z = 3;
	camera->x = 0;
	camera->y = 0;
	camera->a_x = 0;
	camera->a_y = 0;
	camera->a_z = 0;
	camera->max_z = 0;
	return (camera);
}
