/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 16:14:18 by zwang             #+#    #+#             */
/*   Updated: 2018/10/23 18:15:47 by zwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	get_map_size(const char *file_name, t_model *model)
{
	int		fd;
	char	*line;

	fd = open(file_name, O_RDONLY);
	model->row = 0;
	model->col = 0;
	while (ft_nextline(fd, &line) > 0)
	{
		if (!model->col)
			model->col = ft_strccount(line, ' ');
		model->row++;
		free(line);
	}
}

void	set_init_color(t_model *model)
{
	int	i;
	int	j;

	if (!(model->color = (int **)malloc(sizeof(int *) * model->row)))
		perror("malloc");
	i = -1;
	while (++i < model->row)
	{
		if (!(model->color[i] = (int *)malloc(sizeof(int) * model->col)))
			perror("malloc");
		j = -1;
		while (++j < model->col)
			model->color[i][j] = DEEP_BLUE;
	}
}

void	store_map(const char *file_name, t_model *model)
{
	char	*ptr;
	char	**str_list;
	int		*int_list;
	size_t	i;
	size_t	j;
	int		fd;

	get_map_size(file_name, model);
	if (!(model->map = (int **)malloc(sizeof(int *) * model->row)))
		perror("malloc");
	set_init_color(model);
	fd = open(file_name, O_RDONLY);
	i = -1;
	while (ft_nextline(fd, &ptr) > 0)
	{
		str_list = ft_strsplit(ptr, ' ');
		free(ptr);
		if (!(model->map[++i] = (int *)malloc(sizeof(int) * model->col)))
			perror("malloc");
		j = -1;
		while (str_list[++j])
		{
			model->map[i][j] = ft_atoi(str_list[j]);
			if ((ptr = ft_strchr(str_list[j], ',')))
				model->color[i][j] = ft_atoi_base(ptr + 3, 16);
		}
		ft_strarrdel(str_list);
	}
}
