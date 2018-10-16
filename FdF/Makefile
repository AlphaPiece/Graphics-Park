# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zwang <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/11 12:45:02 by zwang             #+#    #+#              #
#    Updated: 2018/10/15 15:04:00 by zwang            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS = srcs/fdf.c srcs/draw_line.c srcs/store_map.c srcs/point_util.c \
	   srcs/draw_map.c
INCS = -I incs/ -I minilibx_macos/ -I srcs/libft/incs/

all: $(NAME)

$(NAME):
	$(CC) -o $(NAME) -framework OpenGL -framework APPkit libmlx.a libft.a \
		$(SRCS) $(INCS)
fclean:
	rm -rf fdf

re: fclean all
