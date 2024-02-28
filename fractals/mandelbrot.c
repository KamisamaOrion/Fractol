/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhervoch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 14:10:40 by mhervoch          #+#    #+#             */
/*   Updated: 2024/02/15 23:32:25 by mhervoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Fract_ol.h"
#include <math.h>

void	calculate_mandelbrot(t_data *data)
{
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
			map_complex(data);
			mandelbrot(data);
			data->y += data->pixel_size;
		}
		data->x += data->pixel_size;
	}
}

void	map_complex(t_data *data)
{
	if (WIDTH > HEIGHT)
	{
		data->cr = (data->x - data->omin) * (data->xmax - \
				data->xmin) / (WIDTH - data->omin) + data->xmin;
		data->ci = (data->y - data->omin) * ((data->ymax * data->ratio) - \
				(data->ymin * data->ratio)) / (HEIGHT - \
					data->omin) + (data->ymin * data->ratio);
	}
	else
	{
		data->cr = (data->x - data->omin) * (data->xmax * \
				data->ratio - data->ymin * data->ratio) / (WIDTH - \
					data->omin) + data->xmin * data->ratio;
		data->ci = (data->y - data->omin) * (data->ymax - \
				data->ymin) / (HEIGHT - data->omin) + data->ymin;
	}
}

double	mandelbrot(t_data *data)
{
	float	zr;
	float	zi;	
	float	tmp;

	zr = 0;
	zi = 0;
	data->iter = 0;
	while (zr * zr + zi * zi <= 4 && data->iter < data->iter_max)
	{
		tmp = zr * zr - zi * zi + data->cr;
		zi = 2 * zi * zr + data->ci;
		zr = tmp;
		data->iter++;
	}
	if (data->iter != data->iter_max)
		put_pixel_art(data, data->x, data->y, get_color(data, data->color));
	else
		put_pixel_art(data, data->x, data->y, 0xFF000000);
	return (0);
}
