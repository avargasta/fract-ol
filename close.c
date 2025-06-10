/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 22:41:49 by root              #+#    #+#             */
/*   Updated: 2025/05/29 21:01:43 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	close_program(void *param)
{
	t_fractal	*fractal;

	fractal = (t_fractal *)param;
	if (fractal->mlx)
	{
		mlx_close_window(fractal->mlx);
		mlx_terminate(fractal->mlx);
	}
	exit(0);
}

void	key_hook(mlx_key_data_t kd, void *param)
{
	t_fractal	*fractal;

	(void)kd;
	fractal = (t_fractal *)param;
	if (mlx_is_key_down(fractal->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(fractal->mlx);
	fractal->renderer_changed = true;
}