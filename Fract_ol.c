/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fract_ol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhervoch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 00:46:24 by mhervoch          #+#    #+#             */
/*   Updated: 2024/02/28 11:44:13 by mhervoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fract_ol.h"
#include "MacroLibX/includes/mlx.h"

int	get_mouse_key(int keycode, void *data)
{
	if (keycode == 1)
		zoom_in(data);
	if (keycode == 2)
		zoom_out(data);
	return (0);
}

int	get_key(int keycode, void *data)
{
	if (keycode == 41)
		destroy(data);
	if (keycode == 87)
		iter_up(data);
	if (keycode == 86)
		iter_down(data);
	if (keycode == 82 || keycode == 81 || keycode == 80 || keycode == 79)
		deplacement(keycode, data);
	if (keycode == 46)
		pixel_on(data);
	if (keycode == 45)
		pixel_off(data);
	if (keycode == 89 || keycode == 90 || keycode == 91 || keycode == 92 \
			|| keycode == 93 || keycode == 94)
		key_color(keycode, data);
	if (keycode == 84)
		pixel_min(data);
	if (keycode == 85)
		pixel_max(data);
	if (keycode == 30 || keycode == 31 || keycode == 32)
		key_frac(keycode, data);
	if (keycode == 7 || keycode == 4 || keycode == 26 || keycode == 22)
		change_julia(keycode, data);
	return (0);
}

void	print_fractal(t_data *data)
{
	if (data->which_frac == 1)
		calculate_mandelbrot(data);
	if (data->which_frac == 2)
		calculate_julia(data);
	if (data->which_frac == 3)
		calculate_burningship(data);
}

int	redirection(t_data *data, char **av, int ac)
{
	if (!ft_strncmp(av[1], "mandelbrot"))
		data->which_frac = 1;
	else if (!ft_strncmp(av[1], "julia"))
	{
		data->which_frac = 2;
		if (ac == 4)
		{
			if (check_error(av))
			{
				data->cr = ft_atod(av[2]);
				data->ci = ft_atod(av[3]);
			}
		}
	}
	else if (!ft_strncmp(av[1], "burningship"))
		data->which_frac = 3;
	else
		return (0);
	print_fractal(data);
	return (1);
}

int	main(int ac, char **av)
{
	t_data			*data;

	if ((ac == 2 || ac == 4))
	{
		data = malloc(sizeof(t_data));
		if (!data)
		{
			free(data);
			return (0);
		}
		initialyse_data(data);
		data->mlx = mlx_init();
		data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "fractol");
		data->im = mlx_new_image(data->mlx, WIDTH, HEIGHT);
		mlx_put_image_to_window(data->mlx, data->win, data->im, 0, 0);
		mlx_on_event(data->mlx, data->win, 0, get_key, data);
		mlx_on_event(data->mlx, data->win, 4, get_mouse_key, data);
		mlx_on_event(data->mlx, data->win, 5, window_event, data);
		if (!check_re(data, av, ac))
			return (0);
		mlx_loop(data->mlx);
	}
	else
		write (1, "nombre de parametre incorrecte, pour pouvoir lancer fractol veuiller choisir parmis les \
fractals suivantes :\n\n-./fract_ol mandelbrot\n-./fract_ol julia [parametre 1 \
: cr] [parametre 2 : ci]\n-./fractol burningship\n", 213);
}
