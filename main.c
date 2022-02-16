/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-der <dvan-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 08:23:54 by dvan-der          #+#    #+#             */
/*   Updated: 2022/02/09 15:02:56 by dvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char *argv[])
{
	t_fdf	fdf;

	if (argc == 2)
	{
		fdf.mlx_ptr = mlx_init();
		fdf.win_ptr = mlx_new_window(fdf.mlx_ptr, \
						SCREEN_W, SCREEN_H, "FDF");
		fdf.img = mlx_new_image(fdf.mlx_ptr, SCREEN_W, SCREEN_H);
		fdf.addr = mlx_get_data_addr(fdf.img, &(fdf.bits_per_pixel), \
					&(fdf.line_length), &(fdf.endian));
		if (ft_machine(argv, &fdf))
			write(2, "Sorry, incorrect input...\n", 26);
	}
	else
		write(2, "Sorry, incorrect input...\n", 26);
}
