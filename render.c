/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 22:28:21 by root              #+#    #+#             */
/*   Updated: 2025/04/01 16:03:58 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	render(void *param)
{
	t_fractal	*fractal;

	fractal = (t_fractal *)param;
	if (fractal->renderer_changed)
	{
		if (fractal->name == MANDELBROT)
			mandelbrot(fractal);
		else if (fractal->name == JULIA)
			julia(fractal);
	}
	fractal->renderer_changed = false;
	
}

int	iter_mandel(double x0, double y0)
{
	int	iterations;
	t_complex	z;
	t_complex	c;

	iterations = 0;
	z.real = 0;
	z.imag = 0;
	c.real = x0;
	c.imag = y0;
	while (iterations < ITER)
	{
		z = sum_complex(square_complex(z), c);
		if ((z.real * z.real) + (z.imag * z.imag) > 4)
			break;
		++iterations;	
	}
	return(iterations);
}

void	mandelbrot(t_fractal *fractal)
{
	int	x;
	int	y;
	double	x0;
	double	y0;

	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			x0 = scale(x, 0, WIDTH, fractal->x_axis.min, fractal->x_axis.max);
			y0 = scale(y, 0, HEIGHT, fractal->y_axis.min, fractal->y_axis.max);
			fractal->iter = iter_mandel(x0, y0);
			if (fractal->iter < ITER)
				mlx_put_pixel(fractal->img, x, y, fractal->palette[fractal->iter % ITER]);
			else
				mlx_put_pixel(fractal->img, x, y, fractal->palette[0]);
			y++;
		}
		x++;
	}
}

int	iter_julia(t_fractal *fractal, double x0, double y0)
{
	int	iterations;
	t_complex	z;
	t_complex	c;

	iterations = 0;
	z.real = x0;
	z.imag = y0;
	c.real = fractal->x_julia;
	c.imag = fractal->y_julia;
	while (iterations < ITER)
	{
		z = sum_complex(square_complex(z), c);
		if ((z.real * z.real) + (z.imag * z.imag) > 4)
			break;
		++iterations;	
	}
	return(iterations);
}

void	julia(t_fractal *fractal)
{
	int	x;
	int	y;
	double	x0;
	double	y0;

	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			x0 = scale(x, 0, WIDTH, fractal->x_axis.min, fractal->x_axis.max);
			y0 = scale(y, 0, HEIGHT, fractal->y_axis.min, fractal->y_axis.max);
			fractal->iter = iter_julia(fractal, x0, y0);
			if (fractal->iter < ITER)
				mlx_put_pixel(fractal->img, x, y, fractal->palette[fractal->iter % ITER]);
			else
				mlx_put_pixel(fractal->img, x, y, fractal->palette[0]);
			y++;
		}
		x++;
	}
}