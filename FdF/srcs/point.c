/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 12:23:26 by zwang             #+#    #+#             */
/*   Updated: 2018/10/23 17:07:13 by zwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	copy_point(t_point *dst, const t_point *src)
{
	dst->x = src->x;
	dst->y = src->y;
}

void	move_point(t_point *p, int axis, int move)
{
	if (axis == x_axis)
		p->x += move;
	else
		p->y += move;
}
