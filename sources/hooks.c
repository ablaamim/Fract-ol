/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaamim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 11:29:05 by ablaamim          #+#    #+#             */
/*   Updated: 2022/05/06 10:23:58 by ablaamim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	key(int hook, t_fractal *fractal)
{
	if (hook == ESC)
		exit(EXIT_SUCCESS);

	fractal->fractal.h = 0;
	fractal->fractal.w = 0;
	return (0);
}

int	mouse_hook(int hook, int x, int y, t_fractal *fractal)
{
	return (0);
}
