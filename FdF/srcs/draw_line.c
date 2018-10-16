/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/02 18:00:56 by zwang             #+#    #+#             */
/*   Updated: 2018/10/15 16:01:26 by zwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	swap_address(t_point **p1, t_point **p2)
{
	t_point	*tmp;

	tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

static void	draw_under_45d(t_model *model, int dx, int dy, int color)
{
	double	i;
	double	j;
	double	k;
	t_point	*p1;
	t_point	*p2;

	p1 = model->p1;
	p2 = model->p2;
	if (p2->x < p1->x)
		swap_address(&p1, &p2);
	k = (double)dy / (double)dx;
	k = (p1->y > p2->y) ? -k : k;
	i = p1->x;
	j = p1->y;
	while (i < p2->x)
	{
		mlx_pixel_put(model->mlx, model->window, (int)i, (int)j, color);
		i += 1;
		j += k;
	}
}

static void	draw_above_45d(t_model *model, int dx, int dy, int color)
{
	double	i;
	double	j;
	double	k;
	t_point	*p1;
	t_point	*p2;

	p1 = model->p1;
	p2 = model->p2;
	if (p2->y < p1->y)
		swap_address(&p1, &p2);
	k = (double)dx / (double)dy;
	k = (p1->x > p2->x) ? -k : k;
	i = p1->y;
	j = p1->x;
	while (i < p2->y)
	{
		mlx_pixel_put(model->mlx, model->window, (int)j, (int)i, color);
		i += 1;
		j += k;
	}
}

void		draw_line(t_model *model, int color)
{
	int		dx;
	int		dy;

	dx = ABS(model->p2->x - model->p1->x);
	dy = ABS(model->p2->y - model->p1->y);
	if (dx >= dy)
		draw_under_45d(model, dx, dy, color);
	else
		draw_above_45d(model, dx, dy, color);
}
