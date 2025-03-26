/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvargas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 11:58:59 by anvargas          #+#    #+#             */
/*   Updated: 2025/03/04 11:58:59 by anvargas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "MLX42/include/MLX42/MLX42.h"
#include "PRINTF/ft_printf.h"
#include "LIBFT/libft.h"
#define WIDTH 1280
#define HEIGHT 720
#define ITER 200

typedef enum e_sets
{
	MANDELBROT,
	JULIA
}				t_sets;

typedef struct s_fractal
{
	mlx_t	*mlx;
	mlx_image_t	*img;
	t_sets		name;
	int 	iter;
	uint32_t	palette[ITER];
	
}	t_fractal;

typedef struct s_complex
{
	double real;
	double imag;
}	t_complex;


void init(t_fractal *fractal, int argc, char **argv);

void parse_argv(t_fractal *fractal, int argc, char **argv);

void	throw_error(char *str, t_fractal *fractal);

void	start_mlx(mlx_t *mlx, t_fractal *fractal);

t_complex	sum_complex(t_complex z_1, t_complex z_2);

t_complex	square_complex(t_complex z);

double scale(double unscaled_num, double new_min, double new_max, double old_min, double old_max);

void	init_color_palette(t_fractal *fractal);


int	iter_mandel(double x0, double y0);

void	mandelbrot(t_fractal *fractal);

void	render(void *param);



#endif