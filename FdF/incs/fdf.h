/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 08:58:16 by zwang             #+#    #+#             */
/*   Updated: 2018/10/15 09:59:39 by zwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "mlx.h"
# include "libft.h"
# include <stdio.h>
# include <math.h>

# define KEY_SPACE	49
# define KEY_LEFT	123
# define KEY_RIGHT	124
# define KEY_DOWN	125
# define KEY_UP		126
# define KEY_Q		12
# define KEY_W		13
# define KEY_E		14
# define KEY_R		15
# define KEY_A		0
# define KEY_S		1
# define KEY_D		2
# define KEY_F		3
# define ESC		53

enum			{x_axis, y_axis};

typedef struct	s_point
{
	int			x;
	int			y;
}				t_point;

typedef struct	s_model
{
	void		*mlx;
	void		*window;
	int			row;
	int			col;
	int			**map;
	t_point		*p1;
	t_point		*p2;
	t_point		*startp;
	int			param1;
	int			param2;
	int			param3;
	int			param4;
}				t_model;

void	store_map(const char *file_name, t_model *model);

void	draw_line(t_model *model);

void	copy_point(t_point *dst, const t_point *src);
void	move_point(t_point *p, t_bool is_x, int move);

void	draw_map(t_model *model);

#endif
