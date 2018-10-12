/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 08:58:16 by zwang             #+#    #+#             */
/*   Updated: 2018/10/12 08:54:19 by zwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "mlx.h"
# include "libft.h"
# include <stdio.h>
# include <math.h>

# define M1	40				// horizontal distance between points
# define M2 25				// y-component of vertical distance between points
# define M3	15				// x-component of vertical distance between points
# define M4	5				// z-axis value 

# define MOVE_LEFT	123
# define MOVE_RIGHT	124
# define MOVE_DOWN	125
# define MOVE_UP	126

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
