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
#include "LIBFT/libft.h"
#define WIDTH 1250
#define HEIGHT 1250

#define ITER 200

typedef enum e_sets
{
	MANDELBROT,
	JULIA
}				t_sets;

typedef struct s_axis
{
	double		min;
	double		max;
}				t_axis;

typedef struct s_zoom
{
	double		x;
	double		y;
	double		factor;
}				t_zoom;

typedef struct s_mouse
{
	int32_t		x;
	int32_t		y;
}				t_mouse;

typedef struct s_fractal
{
	mlx_t	*mlx;
	mlx_image_t	*img;
	t_sets		name;
	int 	iter;
	uint32_t	palette[ITER];
	double	x_julia;
	double	y_julia;
	bool	renderer_changed;
	t_axis	x_axis;
	t_axis	y_axis;
	t_zoom	zoom;
	t_mouse	mouse;
}	t_fractal;

typedef struct s_complex
{
	double real;
	double imag;
}	t_complex;

/* UTILS **************************************************************/

double	ft_atod(const char *str);

void	throw_error(char *str, t_fractal *fractal);

t_complex	sum_complex(t_complex z_1, t_complex z_2);

t_complex	square_complex(t_complex z);

double scale(double unscaled_num, double old_min, double old_max, double new_min, double new_max);

/* RENDER **************************************************************/

int	iter_julia(t_fractal *fractal, double x0, double y0);

void	julia(t_fractal *fractal);

int	iter_mandel(double x0, double y0);

void	mandelbrot(t_fractal *fractal);

void	render(void *param);

/* ZOOM **************************************************************/

void	update_range(t_axis *axis, double center, double factor);

void	zoom(t_fractal *fractal);

void	update_mouse_pos(t_fractal *fractal);

void	scroll_hook(double xdelta, double ydelta, void *param);

/* CLOSE **************************************************************/

void	close_program(void *param);

void	key_hook(mlx_key_data_t kd, void *param);

/* INIT **************************************************************/

void init(t_fractal *fractal, int argc, char **argv);

void parse_argv(t_fractal *fractal, int argc, char **argv);

void	construct_fractal(t_fractal *fractal);

void	start_mlx(mlx_t *mlx, t_fractal *fractal);

void	init_color_palette(t_fractal *fractal);


#endif