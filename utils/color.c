/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhervoch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 16:36:11 by mhervoch          #+#    #+#             */
/*   Updated: 2024/02/15 23:32:43 by mhervoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Fract_ol.h"

double	map_color(double i, double max)
{
	return (i * 255 / max);
}

unsigned int	get_color(t_data *data, unsigned int color)
{
	unsigned int	res;
	unsigned int	tmp;

	res = color;
	tmp = map_color(data->iter, data->iter_max);
	res += tmp << 16;
	res += tmp << 8;
	res += tmp;
	return (res);
}

void	put_pixel_art(t_data *data, int x, int y, unsigned int color)
{
	int	dx;
	int	dy;

	dx = 0;
	while (dx < data->pixel_size)
	{
		dy = 0;
		while (dy < data->pixel_size)
		{
			if (x + dx < WIDTH && y + dy < HEIGHT)
			{
				mlx_set_image_pixel(data->mlx, data->im, x + dx, y + dy, color);
			}
			dy++;
		}
		dx++;
	}
}

void	change_color(t_data *data, int color)
{
	if (color == 1)
		data->color = 0xFF0000AA;
	if (color == 2)
		data->color = 0xFF00AAAA;
	if (color == 3)
		data->color = 0xFFAA0000;
	if (color == 4)
		data->color = 0xFF0A0A0A;
	if (color == 5)
		data->color = 0xFFAAAA00;
	if (color == 6)
		data->color = 0x00000000;
	print_fractal(data);
}
