/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 19:23:39 by anvargas          #+#    #+#             */
/*   Updated: 2025/03/31 23:03:23 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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

void	start_mlx(mlx_t *mlx, t_fractal *fractal)
{
	if (!mlx)
		throw_error("mlx_init failed", fractal);
	fractal->mlx = mlx;
	fractal->img = mlx_new_image(mlx, WIDTH, HEIGHT);
	if (!fractal->img)
		throw_error("mlx_new_image failed", fractal);
}


void init(t_fractal *fractal, int argc, char **argv)
{
	parse_argv(fractal, argc, argv);
	init_color_palette(fractal);
	start_mlx(mlx_init(WIDTH, HEIGHT, "Fractol", true), fractal);
}

int main(int argc, char **argv)
{
	t_fractal	fractal;

	init(&fractal, argc, argv);
	mlx_key_hook(fractal.mlx, &key_hook, &fractal);
	mlx_scroll_hook(fractal.mlx, &scroll_hook, &fractal);
	mlx_close_hook(fractal.mlx, &close_program, &fractal);
	mlx_image_to_window(fractal.mlx, fractal.img, 0, 0);
	mlx_loop_hook(fractal.mlx, &render, &fractal);
	mlx_loop(fractal.mlx);
	mlx_terminate(fractal.mlx);
	return(0);
}