/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhervoch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 23:10:51 by mhervoch          #+#    #+#             */
/*   Updated: 2024/02/15 23:31:04 by mhervoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Fract_ol.h"

/*void	initialyse_burning_ship(t_data *data)
{
	p->x1 = -2.1;
	p->x2 = 0.6;
	p->y1 = -1.2;
	p->y2 = 1.2;
	data->zoom = 300;
	data->x = -1;
	data->y = -1;
	data->iter_max = 50;
}*/

void	calculate_burningship(t_data *data)
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
			burning_ship(data);
			data->y += data->pixel_size;
		}
		data->x += data->pixel_size;
	}
}

void	burning_ship(t_data *data)
{
	float	tmp;
	double	zr;
	double	zi;

	zr = 0;
	zi = 0;
	data->iter = 0;
	while (zr * zr + zi * zi <= 4 && data->iter < data->iter_max)
	{
		zr = fabs(zr);
		zi = fabs(zi);
		tmp = zr * zr - zi * zi + data->cr;
		zi = 2 * zi * zr + data->ci;
		zr = tmp;
		data->iter++;
	}
	if (data->iter == data->iter_max)
		put_pixel_art(data, data->x, data->y, get_color(data, data->color));
	else
		put_pixel_art(data, data->x, data->y, data->color);
}
