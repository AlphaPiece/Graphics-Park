# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zwang <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/11 12:45:02 by zwang             #+#    #+#              #
#    Updated: 2018/10/11 13:08:02 by zwang            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS = main.c draw_line.c store_map.c point_util.c draw_map.c
INCS = incs/

all: $(NAME)

$(NAME):
	$(CC) -g -o $(NAME) -framework OpenGL -framework APPkit libmlx.a libft.a \
		$(SRCS) -I minilibx_macos -I libft/incs/

fclean:
	rm -rf fdf

re: fclean all
