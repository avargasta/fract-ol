/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvargas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 19:23:39 by anvargas          #+#    #+#             */
/*   Updated: 2025/03/20 15:10:15 by anvargas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void init(t_fractal *fractal, int argc, char **argv)
{
	parse_argv(fractal, argc, argv);
	init_color_palette(fractal);
	start_mlx(mlx_init(WIDTH, HEIGHT, "Fractol", true), fractal);
}

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

void parse_argv(t_fractal *fractal, int argc, char **argv)
{
	if (argc == 1)
		throw_error("enter mandelbrot or julia", fractal);
	if (ft_strncmp(argv[1], "mandelbrot", 10) == 0 && argc == 2)
		fractal->name = MANDELBROT;
	else if (ft_strncmp(argv[1], "julia", 5) == 0 && argc == 4)
	{
		fractal->name = JULIA;
		fractal->x_julia = ft_atod(argv[2]);
		fractal->y_julia = ft_atod(argv[3]);
		printf("x_julia: %f, y_julia: %f\n", fractal->x_julia, fractal->y_julia);
	}
	else
		throw_error("enter mandelbrot or julia [r] [i]", fractal);
}

void	throw_error(char *str, t_fractal *fractal)
{
	ft_putstr_fd(str, 1);
	if (fractal->mlx)
	{
		mlx_close_window(fractal->mlx);
		mlx_terminate(fractal->mlx);
	}
}

void	start_mlx(mlx_t *mlx, t_fractal *fractal)
{
	if (!mlx)
		throw_error("mlx_init failed", fractal);
	fractal->mlx = mlx;
	fractal->img = mlx_new_image(mlx, WIDTH, HEIGHT);
	if (!fractal->img)
		throw_error("mlx_new_image failed", fractal);
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

void	init_color_palette(t_fractal *fractal)
{
	int		i;
	double	t;
	int		r;
	int		g;
	int		b;

	i = 1;
	fractal->palette[0] = 0xEE;
	while (i < ITER)
	{
		t = (double)i / (ITER / 2);
		r = (int)(9 * (1 - t) * t * t * t * 255);
		g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
		b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
		fractal->palette[i] = (r << 24) | (g << 16) | (b << 8) | 255;
		i++;
	}
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
			x0 = scale(x, 0, WIDTH, -2, +2);
			y0 = scale(y, 0, HEIGHT, -2, +2);
			fractal->iter = iter_mandel(x0, y0);
			if (fractal->iter < ITER)
			{
				mlx_put_pixel(fractal->img, x, y, fractal->palette[fractal->iter % ITER]);
			}
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
			x0 = scale(x, 0, WIDTH, -2, +2);
			y0 = scale(y, 0, HEIGHT, -2, +2);
			fractal->iter = iter_julia(fractal, x0, y0);
			if (fractal->iter < ITER)
			{
				mlx_put_pixel(fractal->img, x, y, fractal->palette[fractal->iter % ITER]);
			}
			else
				mlx_put_pixel(fractal->img, x, y, fractal->palette[0]);
			y++;
		}
		x++;
	}
}


void	render(void *param)
{
	t_fractal	*fractal;

	fractal = (t_fractal *)param;
	if (fractal->name == MANDELBROT)
		mandelbrot(fractal);
	else if (fractal->name == JULIA)
		julia(fractal);
}


int main(int argc, char **argv)
{
	t_fractal	fractal;

	init(&fractal, argc, argv);
	mlx_image_to_window(fractal.mlx, fractal.img, 0, 0);
	mlx_loop_hook(fractal.mlx, &render, &fractal);
	mlx_loop(fractal.mlx);
	mlx_terminate(fractal.mlx);
	return(0);
}