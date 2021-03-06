/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 13:38:42 by zwang             #+#    #+#             */
/*   Updated: 2018/11/07 12:52:16 by zwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		g_x = 2100;
int		g_y = 1200;

void	init_stat(t_model *model)
{
	model->startp->x = g_x / 5;
	model->startp->y = g_y / 5;
	model->v1 = g_x / (model->col + 50);
	model->v2 = g_y / (model->row + 50);
	model->v3 = model->v1 / 3;
	model->v4 = 4;
	draw_map(model);
	mlx_string_put(model->mlx, model->window, 4, 2, RUBY_RED, H1 H2 H3);
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
		model->v2--;
	else if (key == KEY_S)
		model->v2++;
	else if (key == KEY_E)
		model->v4++;
	else if (key == KEY_D)
		model->v4--;
	else if (key == KEY_Q)
		model->v1--;
	else if (key == KEY_R)
		model->v1++;
	else if (key == KEY_A)
		model->v3++;
	else if (key == KEY_F)
		model->v3--;
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
		mlx_string_put(model->mlx, model->window, 4, 2, RUBY_RED, H1 H2 H3);
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
		store_map(argv[1], &model);
		model.mlx = mlx_init();
		model.window = mlx_new_window(model.mlx, g_x, g_y, "My Window");
		model.p1 = &p1;
		model.p2 = &p2;
		model.startp = &startp;
		init_stat(&model);
		mlx_hook(model.window, 2, 2, key_handler, &model);
		mlx_loop(model.mlx);
	}
	return (0);
}
