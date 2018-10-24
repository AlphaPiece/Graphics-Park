# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zwang <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/11 12:45:02 by zwang             #+#    #+#              #
#    Updated: 2018/10/23 17:13:42 by zwang            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS = srcs/fdf.c srcs/draw_line.c srcs/store_map.c srcs/point.c \
	   srcs/draw_map.c
LIBS = libs/libmlx.a libs/libft.a
INCS = -I incs/ -I libs/minilibx_macos/ -I libs/libft/incs/

all: $(NAME)

$(NAME):
	$(CC) -o $(NAME) -framework OpenGL -framework APPkit $(LIBS) $(SRCS) $(INCS)

fclean:
	rm -rf $(NAME)

re: fclean all
