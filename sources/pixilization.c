/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixilization.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaamim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 18:44:29 by ablaamim          #+#    #+#             */
/*   Updated: 2022/05/09 16:27:45 by ablaamim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_rgb_randomizer(t_fractal *fractal)
{
	fractal->color.red += 10;
	fractal->color.green += 40;
	fractal->color.blue += 15;
}

void	ft_put_pixel(t_fractal *fractal, int depth)
{
	int	pos;

	pos = (fractal->fractal.h + (fractal->fractal.w * WIDTH)) * 4;
	if (fractal->fractal.h < WIDTH \
			&& fractal->fractal.w < HEIGHT \
			&& depth == fractal->fractal.iteration)
	{
		fractal->mlx.addr[pos] = 0x00;
		fractal->mlx.addr[pos + 1] = 0x00;
		fractal->mlx.addr[pos + 2] = 0x00;
	}
	else if (fractal->fractal.h < WIDTH && fractal->fractal.w < HEIGHT)
	{
		fractal->mlx.addr[pos] = fractal->color.red + (depth * 2.42);
		fractal->mlx.addr[pos + 1] = fractal->color.green + (depth * 3.52);
		fractal->mlx.addr[pos + 2] = fractal->color.blue + (depth * 4.65);
	}
}
