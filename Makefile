# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dvan-der <dvan-der@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/15 08:23:59 by dvan-der          #+#    #+#              #
#    Updated: 2022/01/28 10:21:45 by dvan-der         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# -*- Makefile -*-

NAME := fdf

SRCS := \
main.c \
ft_machine.c \
convert_utils.c \
drawlines.c \
setup_controls.c \
letsdraw.c \
keypress.c \
zoom.c \
rotate.c \
move.c \
flatten.c \
free_copied_map.c \
make_colour.c

MLX := 			minilibx_macos/libmlx.a
LIBFT := 		libft/libft.a

ifdef debug
	CFLAGS := -Wall -Wextra -fsanitize=address -g
else
	CFLAGS := -Wall -Werror -Wextra
endif

all: $(NAME)

$(NAME): $(SRCS) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) $^ -o $@ -framework OpenGL -framework AppKit

$(LIBFT):
	$(MAKE) bonus -C libft CFLAGS="$(CFLAGS)"

$(MLX):
	$(MAKE) -C minilibx_macos

clean:
	$(MAKE) clean -C libft
	$(MAKE) clean -C minilibx_macos
	rm -f $(OBJS)

fclean: clean
	$(MAKE) fclean -C libft
	rm -f $(NAME) $^

re:	fclean all

.PHONY: all, clean, fclean, re