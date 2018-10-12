/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 13:38:42 by zwang             #+#    #+#             */
/*   Updated: 2018/10/12 09:01:53 by zwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_stat(t_model *model)
{
	model->param1 = 40;
	model->param2 = 25;
	model->param3 = 15;
	model->param4 = 5;
	draw_map(model);
}

void	incre_height(t_model *model, int key)
{
	if (key == 6)
		model->param4++;
	else
		model->param4--;
	draw_map(model);
}

int		key_handler(int key, t_model *model)
{
	if (key == 53)
	   exit(0);
	ft_printf("key = %d\n", key);
	if (key == 6 || key == 7)
		incre_height(model, key);
	return (0);
}

int		main(int argc, char **argv)
{
	t_model		model;
	t_point		p1;
	t_point		p2;

	if (argc == 2)
	{
		model.mlx = mlx_init();
		model.window = mlx_new_window(model.mlx, 1200, 1200, "My Window");
		model.p1 = &p1;
		model.p2 = &p2;
		store_map(argv[1], &model);
		init_stat(&model);
		mlx_hook(model.window, 2, 2, key_handler, &model);
		mlx_loop(model.mlx);
	}
	return (0);
}
