/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 19:23:39 by anvargas          #+#    #+#             */
/*   Updated: 2025/04/01 16:35:10 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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