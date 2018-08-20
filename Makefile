# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/11 22:46:39 by ablizniu          #+#    #+#              #
#    Updated: 2018/08/07 18:56:24 by ablizniu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ablizniu.filler
NAME_VISUAL = ablizniu.visual
PATH_LB = libft/
NAME_LB = $(PATH_LB)libft.a
FLAGS = -Wall -Wextra -Werror
FLAGS_VISUAL = -Wall -Wextra -Werror -lmlx -framework OpenGL -framework AppKit
CC = clang

OBJS = filler_core.c \
        main.c \
        filler_core_0_1.c \
        filler_core_0_2.c \
        filler_core_0_3.c \
        filler_core_0_4.c \
        filler_core_2.c \
        filler_parse.c \
        filler_parse_token.c
VISUAL = main_visual.c \
              visual_core.c \
              visual_draw.c visual_end.c \
              visual_start.c
SRC_LB = libft/*.c
OBJ_LB = *.o

all: $(NAME)

$(NAME): $(NAME_LB) $(OBJ_PATH)
	$(CC) $(FLAGS) -o $(NAME) $(OBJS) $(NAME_LB)
	$(CC) $(FLAGS_VISUAL) -o $(NAME_VISUAL) $(VISUAL) $(NAME_LB)

$(NAME_LB):
	make -C libft

clean:
	@rm -f *.o
fclean: clean
	@rm -f $(NAME)
	@rm -f $(NAME_VISUAL)
	@make fclean -C libft 
re: fclean all
