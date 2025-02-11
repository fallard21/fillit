# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fallard <fallard@student.21-school.ru>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/07 15:43:25 by fallard           #+#    #+#              #
#    Updated: 2020/11/24 19:32:42 by fallard          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

HEAD_NAME = libft.h ft_printf.h ft_printf_private.h

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC_DIR = sources/
LIB_DIR = $(SRC_DIR)ft_libc/
PF_DIR = $(SRC_DIR)ft_printf/
INC_DIR = includes/

SRC_LIB = ft_atoi.c \
ft_bzero.c \
ft_isalnum.c \
ft_isalpha.c \
ft_isascii.c \
ft_isdigit.c \
ft_isprint.c \
ft_itoa.c \
ft_memalloc.c \
ft_calloc.c \
ft_memccpy.c \
ft_memchr.c \
ft_memcmp.c \
ft_memcpy.c \
ft_memdel.c \
ft_memmove.c \
ft_memset.c \
ft_putchar.c \
ft_putchar_fd.c \
ft_putendl.c \
ft_putendl_fd.c \
ft_putnbr.c \
ft_putnbr_fd.c \
ft_putstr.c \
ft_putstr_fd.c \
ft_strcat.c \
ft_strchr.c \
ft_strclr.c \
ft_strcmp.c \
ft_strcpy.c \
ft_strdel.c \
ft_strdup.c \
ft_strequ.c \
ft_striter.c \
ft_striteri.c \
ft_strjoin.c \
ft_strjoin_free.c \
ft_strlcat.c \
ft_strlen.c \
ft_strmap.c \
ft_strmapi.c \
ft_strncat.c \
ft_strncmp.c \
ft_strncpy.c \
ft_strnequ.c \
ft_strnew.c \
ft_strnstr.c \
ft_strrchr.c \
ft_split.c \
ft_strstr.c \
ft_strsub.c \
ft_strtrim.c \
ft_tolower.c \
ft_toupper.c \
ft_swap.c \
ft_factorial.c \
ft_abs.c \
ft_lstnew.c \
ft_lstdelone.c \
ft_lstdel.c \
ft_lstadd.c \
ft_lstiter.c \
ft_lstmap.c \
get_next_line.c \
ft_itoa_base.c \
ft_ulltoa.c \
ft_sort.c

SRC_PF = ft_printf.c \
parse.c \
print_result.c \
print_flags.c \
pf_itoa.c \
dec_numbers.c \
dec_treatment.c \
specifier.c \
macros.c \
floats.c \
float_valide.c \
float_round_up.c \
long_arithmetic_int.c \
long_arithmetic_frac.c \
long_float_treatment.c \
print_bin.c \
print_iso_time.c \
print_iso_func.c \
helpers.c \
pf_color.c

HEADER = $(addprefix $(INC_DIR), $(HEAD_NAME))

TMP_LIB = $(addprefix $(LIB_DIR), $(SRC_LIB:.c=.o))
TMP_PF = $(addprefix $(PF_DIR), $(SRC_PF:.c=.o))

INCLUDES = -I $(INC_DIR)

RD = \033[031m
GR = \033[032m
YW = \033[033m
BL = \033[034m
PK = \033[035m
CN = \033[036m
EOC = \033[0m

all: $(NAME)
	
$(NAME): $(TMP_LIB) $(TMP_PF) $(HEADER)
	@ar rc $(NAME) $(TMP_LIB) $(TMP_PF)
	@printf "\n$(GR)>> Libft created <<$(EOC)\n"

%.o:%.c $(HEADER)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	@printf "$(CN).$(EOC)"

clean:
	@rm -f $(TMP_LIB)
	@rm -f $(TMP_PF)
	@printf "$(YW)Libft: $(RD)Object files deleted.$(EOC)\n"

fclean: clean
	@rm -f $(NAME)
	@printf "$(YW)Libft: $(RD)$(NAME) deleted.$(EOC)\n"

re: fclean all
