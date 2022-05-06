# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ablaamim <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/02 12:37:59 by ablaamim          #+#    #+#              #
#    Updated: 2022/05/06 17:49:12 by ablaamim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

CC = gcc
FLAGS = -Wall -Wextra -Werror
RM = rm -rf

HEADER = ./includes/fractol.h

SRC = ./sources/main.c \
	  ./sources/draw.c \
	  ./sources/hooks.c \
	  ./sources/ft_mandelbrot_constructor.c \
	  ./sources/libft_utils.c

OBJ = $(patsubst %.c,%.o,$(SRC))

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(FLAGS) -lmlx -framework OpenGL -framework AppKit $(OBJ) -o $(NAME)

%.o : %.c Makefile $(HEADER)
	$(CC) $(FLAGS) -Imlx -c $< -o $@

clean :
	$(RM) $(OBJ)

fclean :
	$(RM) fractol $(OBJ)


re : fclean all

.PHONY : all clean fclean re
