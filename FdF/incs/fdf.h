/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 08:58:16 by zwang             #+#    #+#             */
/*   Updated: 2018/11/07 13:00:57 by zwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "mlx.h"
# include "libft.h"
# include <stdio.h>
# include <math.h>

# define HEIGHT		1200
# define WIDTH		2100
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
# define DEEP_BLUE	0x000077ee
# define RUBY_RED	0x00aa0000
# define H1			"Q W E R A S D F "
# define H2			"RIGHTWARD-ARROW LEFTWARD-ARROW "
# define H3			"UPWARD-ARROW DOWNWARD-ARROW"

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
	int			**color;
	t_point		*p1;
	t_point		*p2;
	t_point		*startp;
	int			v1;
	int			v2;
	int			v3;
	int			v4;
}				t_model;

void			store_map(const char *file_name, t_model *model);

void			draw_line(t_model *model, int color);

void			copy_point(t_point *dst, const t_point *src);
void			move_point(t_point *p, t_bool is_x, int move);

void			draw_map(t_model *model);

#endif
