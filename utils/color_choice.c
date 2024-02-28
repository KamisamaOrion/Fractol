/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_choice.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhervoch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 18:31:04 by mhervoch          #+#    #+#             */
/*   Updated: 2024/01/19 18:33:45 by mhervoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Fract_ol.h"

void	key_color(int keycode, t_data *data)
{
	if (keycode == 89)
		change_color(data, 1);
	if (keycode == 90)
		change_color(data, 2);
	if (keycode == 91)
		change_color(data, 3);
	if (keycode == 92)
		change_color(data, 4);
	if (keycode == 93)
		change_color(data, 5);
	if (keycode == 94)
		change_color(data, 6);
}

void	key_frac(int keycode, t_data *data)
{
	if (keycode == 30)
		switch_frac(data, 1);
	if (keycode == 31)
		switch_frac(data, 2);
	if (keycode == 32)
		switch_frac(data, 3);
}
