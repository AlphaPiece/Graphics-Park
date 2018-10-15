/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 13:38:42 by zwang             #+#    #+#             */
/*   Updated: 2018/10/15 10:04:24 by zwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_stat(t_model *model)
{
	model->startp->x = 700;
	model->startp->y = 400;
	model->param1 = 40;
	model->param2 = 25;
	model->param3 = 15;
	model->param4 = 4;
	draw_map(model);
}

t_bool	is_valid_key(int key)
{
	return (key == KEY_SPACE || key == KEY_UP || key == KEY_DOWN ||
			key == KEY_RIGHT || key == KEY_LEFT ||
			key == KEY_Q || key == KEY_W || key == KEY_E || key == KEY_R ||
			key == KEY_A || key == KEY_S || key == KEY_D || key == KEY_F);
}

void	change_param(t_model *model, int key)
{
	if (key == KEY_UP)
		model->startp->y -= 10;
	else if (key == KEY_DOWN)
		model->startp->y += 10;
	else if (key == KEY_RIGHT)
		model->startp->x += 10;
	else if (key == KEY_LEFT)
		model->startp->x -= 10;
	else if (key == KEY_W)
		model->param2--;
	else if (key == KEY_S)
		model->param2++;
	else if (key == KEY_E)
		model->param4++;
	else if (key == KEY_D)
		model->param4--;
	else if (key == KEY_Q)
		model->param1--;
	else if (key == KEY_R)
		model->param1++;
	else if (key == KEY_A)
		model->param3++;
	else if (key == KEY_F)
		model->param3--;
}


int		key_handler(int key, t_model *model)
{
	if (key == ESC)
	   exit(0);
	if (is_valid_key(key))
	{
		mlx_clear_window(model->mlx, model->window);
		if (key == KEY_SPACE)
			init_stat(model);
		else
			change_param(model, key);
		draw_map(model);
	}
	return (0);
}

int		main(int argc, char **argv)
{
	t_model		model;
	t_point		p1;
	t_point		p2;
	t_point		startp;

	if (argc == 2)
	{
		model.mlx = mlx_init();
		model.window = mlx_new_window(model.mlx, 2100, 1200, "My Window");
		model.p1 = &p1;
		model.p2 = &p2;
		model.startp = &startp;
		store_map(argv[1], &model);
		init_stat(&model);
		mlx_hook(model.window, 2, 2, key_handler, &model);
		mlx_loop(model.mlx);
	}
	return (0);
}
