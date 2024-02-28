/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_event.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhervoch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:48:40 by mhervoch          #+#    #+#             */
/*   Updated: 2024/02/28 11:44:24 by mhervoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Fract_ol.h"

int	window_event(int event, void *data)
{
	if (event == 0)
		destroy(data);
	return (0);
}

void	change_julia(int keycode, t_data *data)
{
	if (keycode == 7)
		data->cr += 0.05;
	if (keycode == 26)
		data->ci += 0.05;
	if (keycode == 4)
		data->cr -= 0.05;
	if (keycode == 22)
		data->ci -= 0.05;
	print_fractal(data);
}

int	destroy_img(t_data *data)
{
	if (data->im)
		mlx_destroy_image(data->mlx, data->im);
	return (1);
}

int	check_re(t_data *data, char **av, int ac)
{
	if (!redirection(data, av, ac))
	{
		write (1, "nombre de parametre incorrecte, pour pouvoir lancer fractol veuiller choisir parmis les \
fractals suivantes :\n\n-./fract_ol mandelbrot\n-./fract_ol julia [parametre 1 \
: cr] [parametre 2 : ci]\n-./fractol burningship\n", 213);
		destroy(data);
		return (0);
	}
	return (1);
}
