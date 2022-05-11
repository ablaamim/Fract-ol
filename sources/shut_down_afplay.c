/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shut_down_afplay.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaamim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 15:57:47 by ablaamim          #+#    #+#             */
/*   Updated: 2022/05/11 15:59:06 by ablaamim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	close_afplay(t_fractal *fractal)
{
	kill(fractal->pid, SIGPIPE);
	exit (EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}
