/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhervoch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 18:24:57 by mhervoch          #+#    #+#             */
/*   Updated: 2024/02/15 23:31:47 by mhervoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Fract_ol.h"

void	map_julia(t_data *data, double	*zr, double	*zi)
{
	if (WIDTH > HEIGHT)
	{
		*zr = maping(data->x, WIDTH, data->xmin, data->xmax);
		*zi = maping(data->y, HEIGHT, data->ymin * data->ratio \
				, data->ymax * data->ratio);
	}
	else
	{
		*zr = maping(data->x, WIDTH, data->xmin * data->ratio \
				, data->xmax * data->ratio);
		*zi = maping(data->y, HEIGHT, data->ymin, data->ymax);
	}
}

void	calculate_julia(t_data *data)
{
	double	zr;
	double	zi;

	data->xmax = data->center_x + (2.0 / data->zoomf);
	data->xmin = data->center_x - (2.0 / data->zoomf);
	data->ymax = data->center_y + (2.0 / data->zoomf);
	data->ymin = data->center_y - (2.0 / data->zoomf);
	data->x = 0;
	while (data->x < WIDTH)
	{
		data->y = 0;
		while (data->y < HEIGHT)
		{
			map_julia(data, &zr, &zi);
			julia(data, zr, zi);
			data->y += data->pixel_size;
		}
		data->x += data->pixel_size;
	}
}

void	julia(t_data *data, double zr, double zi)
{
	double	tmp;

	data->iter = 0;
	while (zr * zr + zi * zi <= 4 && data->iter < data->iter_max)
	{
		tmp = zr * zr - zi * zi;
		zi = 2 * zr * zi + data->ci;
		zr = tmp + data->cr;
		data->iter++;
	}
	if (data->iter != data->iter_max)
		put_pixel_art(data, data->x, data->y, get_color(data, data->color));
	else
		put_pixel_art(data, data->x, data->y, get_color(data, 0xFFFFFF));
}
