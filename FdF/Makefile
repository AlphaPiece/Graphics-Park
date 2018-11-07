# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zwang <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/11 12:45:02 by zwang             #+#    #+#              #
#    Updated: 2018/11/07 13:09:42 by zwang            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS = srcs/fdf.c srcs/draw_line.c srcs/store_map.c srcs/point.c \
	   srcs/draw_map.c
LIBS = libs/libmlx/libmlx.a libs/libft/libft.a
INCS = -I incs/ -I libs/minilibx_macos/ -I libs/libft/incs/

all: $(NAME)

$(NAME):
	@make -C libs/libft/
	@make -C libs/libmlx/
	@$(CC) -o $(NAME) $(CFLAGS) -framework OpenGL -framework APPkit $(LIBS) \
		$(SRCS) $(INCS)

clean:
	@make -C libs/libft/ clean
	@make -C libs/libmlx/ clean

fclean:
	@make -C libs/libft/ fclean
	@make -C libs/libmlx/ fclean
	@rm -rf $(NAME)

re: fclean all
