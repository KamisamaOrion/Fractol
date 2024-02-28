/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fract_ol_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhervoch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 16:32:58 by mhervoch          #+#    #+#             */
/*   Updated: 2024/02/04 19:36:06 by mhervoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Fract_ol.h"

int	ft_atoi(const char *nptr, int *i)
{
	int	sign;
	int	sum;

	sign = 1;
	sum = 0;
	while (nptr[*i] == 32 || (nptr[*i] >= 9 && nptr[*i] <= 13))
		(*i)++;
	if ((nptr[*i] == '+' || nptr[*i] == '-'))
	{
		if (nptr[*i] == '-')
			sign = -sign;
		(*i)++;
	}
	while (nptr[*i] >= 48 && nptr[*i] <= 57)
	{
		sum = sum / 10 + nptr[*i] - 48;
		(*i)++;
	}
	return (sum * sign);
}

double	ft_atod(const char *nptr)
{
	int		i;
	double	j;
	double	sum;

	i = 0;
	j = 1;
	sum = 0;
	sum = (double)ft_atoi(nptr, &i);
	if (!ft_strchr(nptr, 46))
		return (sum);
	i++;
	while (nptr[i] >= 48 && nptr[i] <= 57)
	{
		j /= 10;
		sum += j * (nptr[i] - 48);
		i++;
	}
	return (sum);
}

double	module(double zr, double zi)
{
	return (sqrt((zr * zr) + (zi * zi)));
}

int	ft_strncmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s2[i])
	{
		if (s1[i] != s2[i])
		{
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		}
		i++;
	}
	if (i < ft_strlen((char *)s1))
		return ((unsigned char) s1[i] - (unsigned char) s2[i]);
	return (0);
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
