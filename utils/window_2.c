/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhervoch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 18:42:41 by mhervoch          #+#    #+#             */
/*   Updated: 2024/02/15 23:33:53 by mhervoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Fract_ol.h"

void	iter_down(t_data *data)
{
	data->iter_max -= 10;
	print_fractal(data);
}

void	pixel_on(t_data *data)
{
	if (data->pixel_size < 15)
		data->pixel_size++;
	print_fractal(data);
}

void	pixel_off(t_data *data)
{
	if (data->pixel_size > 1)
		data->pixel_size--;
	print_fractal(data);
}

void	pixel_max(t_data *data)
{
	data->pixel_size = 16;
	print_fractal(data);
}

void	pixel_min(t_data *data)
{
	data->pixel_size = 1;
	print_fractal(data);
}
