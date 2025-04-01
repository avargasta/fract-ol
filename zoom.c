/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 22:26:52 by root              #+#    #+#             */
/*   Updated: 2025/04/01 16:43:14 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	update_range(t_axis *axis, double center, double factor)
{
	axis->min = center - (center - axis->min) * factor;
	axis->max = center + (axis->max - center) * factor;
}

void	zoom(t_fractal *fractal)
{
	fractal->zoom.x = fractal->x_axis.min + 
            (fractal->x_axis.max - fractal->x_axis.min) *
            (fractal->mouse.x / (double)fractal->mlx->width);
    fractal->zoom.y = fractal->y_axis.min +
            (fractal->y_axis.max - fractal->y_axis.min) *
            (fractal->mouse.y / (double)fractal->mlx->height);
	update_range(&fractal->x_axis, fractal->zoom.x, fractal->zoom.factor);
	update_range(&fractal->y_axis, fractal->zoom.y, fractal->zoom.factor);
}

void	update_mouse_pos(t_fractal *fractal)
{
	int32_t	x;
	int32_t	y;

	mlx_get_mouse_pos(fractal->mlx, &x, &y);
	if (x < 0)
		x = 0;
	else if (x > fractal->mlx->width)
		x = fractal->mlx->width;
	if (y < 0)
		y = 0;
	else if (y > fractal->mlx->height)
		y = fractal->mlx->height;
    fractal->mouse.x = x;
    fractal->mouse.y = y;
}


void	scroll_hook(double xdelta, double ydelta, void *param)
{
	t_fractal	*fractal;

	fractal = (t_fractal*)param;
	if (ydelta > 0)
        fractal->zoom.factor = 0.9;
	else
        fractal->zoom.factor = 1.1;
	update_mouse_pos(fractal);
	zoom(fractal);
	fractal->renderer_changed = true;
}