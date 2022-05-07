/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaamim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 11:29:05 by ablaamim          #+#    #+#             */
/*   Updated: 2022/05/07 18:38:34 by ablaamim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	key_hook(int hook, t_fractal *fractal)
{
	if (hook == ESC)
		exit(EXIT_SUCCESS);
	else if (hook == SPACE)
		ft_rgb_randomizer(fractal);
	else if (hook == UP)
		fractal->fractal.y_im += 10 / fractal->fractal.scale;
	else if (hook == DOWN)
		fractal->fractal.y_im -= 10 / fractal->fractal.scale;
	else if (hook == LEFT)
		fractal->fractal.x_real += 10 / fractal->fractal.scale;
	else if (hook == RIGHT)
		fractal->fractal.x_real -= 10 / fractal->fractal.scale;
	fractal->fractal.h = 0;
	fractal->fractal.w = 0;
	ft_draw(fractal);
	return (EXIT_SUCCESS);
}

void	ft_zoom_in(int x, int y, t_fractal *fractal)
{
	double	scalar;

	if (fractal->fractal.scale >= SCALE_LIMIT)
		return ;
	else
	{
		scalar = fractal->fractal.scale * SCALE_PERC;
		fractal->fractal.x_real = ((double) x / fractal->fractal.scale \
				+ fractal->fractal.x_real - (scalar / 2));
		fractal->fractal.x_real += (scalar / 2) - ((double)x / scalar);
		fractal->fractal.y_im = ((double) y / fractal->fractal.scale + \
				fractal->fractal.y_im) - (scalar / 2);
		fractal->fractal.y_im += (scalar / 2) - ((double) y / scalar);
		fractal->fractal.scale *= SCALE_PERC;
		fractal->fractal.iteration += SCALE_ITER;
	}
}

void	ft_zoom_out(int x, int y, t_fractal *fractal)
{
	double	scalar;

	scalar = fractal->fractal.scale / SCALE_PERC;
	fractal->fractal.x_real = ((double) x / fractal->fractal.scale + \
			fractal->fractal.x_real) - (scalar / 2);
	fractal->fractal.x_real += (scalar / 2) - ((double) x / scalar);
	fractal->fractal.y_im = ((double) y / fractal->fractal.scale + \
			fractal->fractal.y_im) - (scalar / 2);
	fractal->fractal.y_im += (scalar / 2) - ((double)y / scalar);
	fractal->fractal.scale /= SCALE_PERC;
	fractal->fractal.iteration -= SCALE_ITER;
}

int	mouse_hook(int hook, int x, int y, t_fractal *fractal)
{
	if (hook == SCROLL_DOWN)
		ft_zoom_in(x, y, fractal);
	if (hook == SCROLL_UP)
		ft_zoom_out(x, y, fractal);
	fractal->fractal.h = 0x0;
	fractal->fractal.w = 0x0;
	ft_draw(fractal);
	return (EXIT_SUCCESS);
}
