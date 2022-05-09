/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaamim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 11:38:57 by ablaamim          #+#    #+#             */
/*   Updated: 2022/05/09 17:24:49 by ablaamim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	ft_draw(t_fractal *fractal)
{
	int		depth;
	double	temp_width;

	temp_width = fractal->fractal.w;
	while (fractal->fractal.h < WIDTH)
	{
		fractal->fractal.w = temp_width;
		while (fractal->fractal.w < WIDTH)
		{
			if (fractal->fractal.type == 1)
				depth = ft_mandelbrot_constructor(fractal);
			ft_put_pixel(fractal, depth);
			fractal->fractal.w += 1;
		}
		fractal->fractal.h += 1;
	}
	mlx_put_image_to_window(fractal->mlx.mlx, fractal->mlx.win, \
				fractal->mlx.img, 0, 0);
	return (EXIT_SUCCESS);
}
