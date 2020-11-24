# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fallard <fallard@student.21-school.ru>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/28 14:11:10 by fallard           #+#    #+#              #
#    Updated: 2020/11/24 20:05:23 by fallard          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
LIB_NAME = libft.a
INC_NAME = fillit.h

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC_DIR = sources/
INC_DIR = includes/
LIB_DIR = libft/

RD = \033[031m
GR = \033[032m
YW = \033[033m
BL = \033[034m
PK = \033[035m
CN = \033[036m
EOC = \033[0m

SRC = main.c \
create_alg_struct.c \
validation_p1.c \
validation_p2.c \
create_tetmap.c \
map.c \
tetramino.c \
free_mem.c \
algorithm.c

TMP = $(addprefix $(SRC_DIR), $(SRC:.c=.o))
HEADER = $(addprefix $(INC_DIR), $(INC_NAME))
LIB = $(addprefix $(LIB_DIR), $(LIB_NAME))

INCLUDES = -I $(INC_DIR) -I $(LIB_DIR)$(INC_DIR)

all: $(LIB) $(NAME) $(HEADER)
	@printf "$(CN)>> $(NAME) created <<$(EOC)\n"

$(NAME): $(TMP)
	@$(CC) $(FLAGS) -o $(NAME) $(TMP) $(INCLUDES) $(LIB)
	
%.o:%.c $(HEADER)
	@$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@

$(LIB):
	@make -C libft/

clean:
	@make clean -C libft/
	@rm -f $(TMP)
	@printf "$(YW)Fillit: $(RD)Object files deleted\n$(EOC)"

fclean: clean
	@make fclean -C libft/
	@rm -f $(NAME)
	@printf "$(YW)Fillit: $(RD)$(NAME) and object files deleted\n$(EOC)"

re: fclean all

.PHONY: all clean fclean re
