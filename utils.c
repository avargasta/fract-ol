/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 22:32:10 by root              #+#    #+#             */
/*   Updated: 2025/05/29 21:04:22 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	ft_atod(const char *str)
{
	size_t	i;
	double		dec;
	double		sign;
	double		num;

	i = 0;
	dec = 1;
	sign = 1;
	num = abs(ft_atoi(str));
	while (str[i] != '.')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	i++;
	while (str[i] >= '0' && str[i] <= '9' && str[i] != '\0')
	{
		dec = 0.1 * dec;
		num = num + dec * (str[i] - '0');
		i++;
	}
	return (num * sign);
}

void	throw_error(char *str, t_fractal *fractal)
{
	ft_putstr_fd(str, 1);
	if (fractal->mlx)
	{
		mlx_close_window(fractal->mlx);
		mlx_terminate(fractal->mlx);
	}
	exit(1);
}

t_complex	sum_complex(t_complex z_1, t_complex z_2)
{
	t_complex	result;

	result.real = z_1.real + z_2.real;
	result.imag = z_1.imag + z_2.imag;
	return(result);
}

t_complex	square_complex(t_complex z)
{
	t_complex	result;

	result.real = z.real * z.real - z.imag * z.imag;
	result.imag = 2 * z.real * z.imag;
	return(result);
}

// SCALE! I have to change the range from [0...WIDTH] and [0...HEIGHT] (window size in pixels) to [-2,2] and [-2,2] (fractal size in real numbers)
double scale(double unscaled_num, double old_min, double old_max, double new_min, double new_max)
{
	double	scaled_num;

	scaled_num = ((unscaled_num - old_min) * (new_max - new_min) / (old_max - old_min)) + new_min; // Easy rule of three
	return (scaled_num);
} 