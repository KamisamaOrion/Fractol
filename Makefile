# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhervoch <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/02 13:55:03 by mhervoch          #+#    #+#              #
#    Updated: 2024/02/28 11:44:36 by mhervoch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

CC = clang

CFLAGS = -Wall -Wextra -Werror -g

SRCS = ./Fract_ol.c \
	   ./fractals/mandelbrot.c \
	   ./utils/color.c \
	   ./utils/window.c \
	   ./utils/Fract_ol_utils.c \
	   ./utils/Fract_ol_utils_2.c \
	   ./fractals/burningship.c \
	   ./fractals/julia.c \
	   ./utils/color_choice.c \
	   ./utils/window_2.c \
	   ./utils/window_event.c

HEAD =	Fract_ol.h

OBJS = $(SRCS:.c=.o)

all:$(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -I ./  -c $< -o $@ 

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -lm ./MacroLibX/libmlx.so -lSDL2

fclean: clean
	rm -f $(NAME)

clean:
	rm -f $(OBJS)

re: fclean all

.PHONY: all fclean clean re
