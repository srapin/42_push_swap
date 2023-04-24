# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: srapin <srapin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/21 17:47:23 by srapin            #+#    #+#              #
#    Updated: 2023/02/14 18:41:39 by srapin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap 
NAME_BONUS = checker 

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3
AR = ar rcs

FILES= 	check\
		tools_struct\
		cost\
		is_sorted\
		min_max\
		improve_move_utils\
		move\
		sort\
		push_swap

FILES_BONUS = check\
		tools_struct\
		cost\
		is_sorted\
		min_max\
		improve_move_utils\
		move\
		sort\
		is_valid_cmd\
		push_swap_bonus

SRCS_DIR = ./
SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES)))

OBJS_DIR = ./
OBJS = $(addprefix $(SRCS_DIR), $(addsuffix .o, $(FILES)))

OBJS_BONUS = $(addprefix $(SRCS_DIR), $(addsuffix .o, $(FILES_BONUS)))

LIB_DIR = instruction_set/
LIB_NAME = instruction_set.a
LIB = $(LIB_DIR)$(LIB_NAME)

$(NAME): $(LIB) $(OBJS) 
	cp ${LIB_DIR}${LIB_NAME} $@
	${CC} ${CFLAGS} $(OBJS) ${LIB} -o $@

$(NAME_BONUS): $(OBJS_BONUS) $(LIB)
	cp ${LIB_DIR}${LIB_NAME} $(NAME_BONUS)
	${CC} ${CFLAGS} $(OBJS_BONUS) ${LIB} -o $(NAME_BONUS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIB) :
		make -C $(LIB_DIR)

all: $(NAME) $(NAME_BONUS)

clean:
	make -C $(LIB_DIR) clean
	rm -f $(OBJS)
	rm -f $(OBJS_BONUS)

fclean: clean
	make -C $(LIB_DIR) fclean
	rm -f $(NAME) 
	rm -f $(NAME_BONUS) 

re: fclean all

bonus: $(NAME_BONUS)

.PHONY: all clean fclean re