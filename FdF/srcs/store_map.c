/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 16:14:18 by zwang             #+#    #+#             */
/*   Updated: 2018/10/12 08:52:12 by zwang            ###   ########.fr       */
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
	}
}

void	store_map(const char *file_name, t_model *model)
{
	char	*line;
	char	**str_list;
	int		*int_list;
	size_t	i;
	size_t	j;
	int		fd;

	get_map_size(file_name, model);
	if (!(model->map = (int **)malloc(sizeof(int *) * model->row)))
		perror("malloc");
	fd = open(file_name, O_RDONLY);
	i = 0;
	while (ft_nextline(fd, &line) > 0)
	{
		str_list = ft_strsplit(line, ' ');
		int_list = (int *)malloc(sizeof(int) * model->col);
		j = -1;
		while (str_list[++j])
			int_list[j] = ft_atoi(str_list[j]);
		model->map[i++] = int_list;
	}
}
