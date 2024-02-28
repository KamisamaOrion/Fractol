/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhervoch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 16:37:48 by mhervoch          #+#    #+#             */
/*   Updated: 2024/02/15 23:33:22 by mhervoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Fract_ol.h"

double	maping(double x, double in_max, double out_min, double out_max)
{
	return (((x) * (out_max - out_min) / (in_max) + out_min));
}

void	zoom_in(t_data *data)
{
	double	zoom;
	double	rmouse;
	double	imouse;

	mlx_mouse_get_pos(data->mlx, &data->mouse_x, &data->mouse_y);
	zoom = 1.2;
	rmouse = maping(data->mouse_x, WIDTH, data->center_x - 2 / \
			data->zoomf, data->center_x + 2 / data->zoomf);
	imouse = maping(data->mouse_y, HEIGHT, data->center_y - 2 / \
			data->zoomf, data->center_y + 2 / data->zoomf);
	data->zoomf *= zoom;
	data->center_x = rmouse + (data->center_x - rmouse) / zoom;
	data->center_y = imouse + (data->center_y - imouse) / zoom;
	print_fractal(data);
}

void	zoom_out(t_data *data)
{
	double	zoom;
	double	rmouse;
	double	imouse;

	mlx_mouse_get_pos(data->mlx, &data->mouse_x, &data->mouse_y);
	zoom = 0.8;
	rmouse = maping(data->mouse_x, WIDTH, data->center_x - 2 / \
			data->zoomf, data->center_x + 2 / data->zoomf);
	imouse = maping(data->mouse_y, HEIGHT, data->center_y - 2 / \
			data->zoomf, data->center_y + 2 / data->zoomf);
	data->zoomf *= zoom;
	data->center_x = rmouse + (data->center_x - rmouse) / zoom;
	data->center_y = imouse + (data->center_y - imouse) / zoom;
	print_fractal(data);
}

void	destroy(struct s_data *data)
{
	mlx_loop_end(data->mlx);
	if (data->im)
		mlx_destroy_image(data->mlx, data->im);
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx)
		mlx_destroy_display(data->mlx);
	free(data);
	exit(0);
}

void	iter_up(t_data *data)
{
	data->iter_max += 10;
	print_fractal(data);
}
