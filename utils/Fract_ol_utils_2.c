/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fract_ol_utils_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhervoch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 17:30:21 by mhervoch          #+#    #+#             */
/*   Updated: 2024/01/23 23:51:06 by mhervoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Fract_ol.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*v;

	i = 0;
	v = (char *) s;
	while (s[i] && (s[i] != (unsigned char)c))
		i++;
	if (!(s[i]) && (unsigned char)c != 0)
		return (NULL);
	return ((char *)(v + i));
}

int	deplacement(int keycode, t_data *data)
{
	if (keycode == 82)
		data->center_y -= 0.5 / data->zoomf;
	if (keycode == 80)
		data->center_x -= 0.5 / data->zoomf;
	if (keycode == 81)
		data->center_y += 0.5 / data->zoomf;
	if (keycode == 79)
		data->center_x += 0.5 / data->zoomf;
	print_fractal(data);
	return (0);
}

void	switch_frac(t_data *data, int fractal)
{
	data->which_frac = fractal;
	print_fractal(data);
}

int	check_error(char **av)
{
	float	cr;
	float	ci;

	cr = ft_atod(av[2]);
	ci = ft_atod(av[3]);
	if ((cr <= 2 && cr >= -2) || (ci <= 2 && ci >= -2))
		return (1);
	else
	{
		write(1, "Les points doivent etre entre 2 et -2\n", 38);
		return (0);
	}
}

void	initialyse_data(t_data *data)
{
	data->zoom = 1;
	data->x = 0;
	data->y = 0;
	data->ci = 0.158;
	data->cr = -0.8;
	data->iter_max = 50;
	data->omin = 0;
	data->center_x = 0;
	data->center_y = 0;
	data->zoomf = 1;
	data->pixel_size = 1;
	data->color = 0xFF0000AA;
	if (WIDTH > HEIGHT)
		data->ratio = (double)HEIGHT / (double)WIDTH;
	else
		data->ratio = (double)WIDTH / (double)HEIGHT;
}
