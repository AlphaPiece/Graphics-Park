/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/02 18:38:42 by zwang             #+#    #+#             */
/*   Updated: 2018/10/15 16:43:01 by zwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_x_dimen(t_model *model)
{
	t_point	startp;
	int		i;
	int		j;

	copy_point(&startp, model->startp);
	i = -1;
	while (++i < model->row)
	{
		j = -1;
		copy_point(model->p1, &startp);
		if (model->map[i][0])
			move_point(model->p1, y_axis, -model->map[i][0] * model->param4);
		while (++j < model->col - 1)
		{
			copy_point(model->p2, &startp);
			move_point(model->p2, x_axis, (j + 1) * model->param1);
			move_point(model->p2, y_axis, -model->map[i][j + 1] * model->param4);
			draw_line(model, (model->color[i][j] != DEEP_BLUE &&
								model->color[i][j] == model->color[i][j + 1]) ?
								model->color[i][j] : DEEP_BLUE);
			copy_point(model->p1, model->p2);
		}
		move_point(&startp, y_axis, model->param2);
		move_point(&startp, x_axis, -model->param3);
	}
}

void	draw_y_dimen(t_model *model)
{
	t_point	startp;
	int		i;
	int		j;

	copy_point(&startp, model->startp);
	j = -1;
	while (++j < model->col)
	{
		i = -1;
		copy_point(model->p1, &startp);
		if (model->map[0][j])
			move_point(model->p1, y_axis, -model->map[0][j] * model->param4);
		while (++i < model->row - 1)
		{
			copy_point(model->p2, &startp);
			move_point(model->p2, y_axis, (i + 1) * model->param2);
			move_point(model->p2, x_axis, (i + 1) * -model->param3);
			move_point(model->p2, y_axis, -model->map[i + 1][j] * model->param4);
			draw_line(model, (model->color[i][j] != DEEP_BLUE &&
								model->color[i][j] == model->color[i + 1][j]) ?
								model->color[i][j] : DEEP_BLUE);
			copy_point(model->p1, model->p2);
		}
		move_point(&startp, x_axis, model->param1);
	}			
}

void	draw_map(t_model *model)
{
	draw_x_dimen(model);
	draw_y_dimen(model);
}
