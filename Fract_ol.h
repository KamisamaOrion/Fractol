/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhervoch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 00:21:26 by mhervoch          #+#    #+#             */
/*   Updated: 2024/02/28 11:43:25 by mhervoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
# define FRACT_OL_H

# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include "./MacroLibX/includes/mlx.h"

typedef struct s_data
{
	int				which_frac;
	double			iter;
	int				x;
	int				y;
	void			*mlx;
	void			*win;
	void			*im;
	int				iter_max;
	float			zoom;
	char			**fractal;
	int				mouse_x;
	int				mouse_y;
	double			ratio;
	float			xmin;
	float			xmax;
	float			omax;
	double			omin;
	float			ymax;
	float			ymin;
	float			center_x;
	float			center_y;
	float			zoomf;
	double			cr;
	double			ci;
	int				pixel_size;
	unsigned int	color;
}				t_data;

# define HEIGHT 1080
# define WIDTH 1920

double				mandelbrot(t_data *data);
double				module(double zr, double zi);
void				calculate_mandelbrot(t_data *data);
double				ft_atod(const char *nptr);
int					ft_strncmp(const char *s1, const char *s2);
int					ft_strlen(char *s);
double				map_color(double i, double max);
unsigned int		get_color(t_data *data, unsigned int color);
void				zoom_in(t_data *data);
void				zoom_out(t_data *data);
void				destroy(struct s_data *data);
char				*ft_strchr(const char *s, int c);
void				initialyse_burning_ship(t_data *data);
void				julia(t_data *data, double zr, double zi);
int					get_mouse_pos(t_data *data);
void				print_fractal(t_data *data);
int					deplacement(int keycode, t_data *data);
void				map_complex(t_data *data);
double				maping(double x, \
		double in_max, double out_min, double out_max);
void				iter_up(t_data *data);
void				iter_down(t_data *data);
void				put_pixel_art(t_data *data, int x, \
		int y, unsigned int color);
void				pixel_on(t_data *data);
void				pixel_off(t_data *data);
void				change_color(t_data *data, int color);
void				pixel_max(t_data *data);
void				pixel_min(t_data *data);
void				switch_frac(t_data *data, int fractal);
int					check_error(char **av);
void				burning_ship(t_data *data);
void				calculate_burningship(t_data *data);
void				calculate_julia(t_data *data);
void				key_color(int keycode, t_data *data);
void				key_frac(int keycode, t_data *data);
void				initialyse_data(t_data *data);
int					window_event(int event, void *data);
void				change_julia(int keycode, t_data *data);
int					destroy_img(t_data *data);
int					check_re(t_data *data, char **av, int ac);
int					redirection(t_data *data, char **av, int ac);

#endif
