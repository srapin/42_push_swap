# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: srapin <srapin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/21 17:47:59 by srapin            #+#    #+#              #
#    Updated: 2023/02/09 18:13:04 by srapin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = instruction_set.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3
AR = ar rcs

FILES=  push\
		revrotate\
		rotate\
		swap

SRCS_DIR = ./
SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES)))

OBJS_DIR = ./
OBJS = $(addprefix $(SRCS_DIR), $(addsuffix .o, $(FILES)))

LIBFTPRINTF_DIR = ../libft/
LIBFTPRINTF_NAME = libft.a
LIBFTPRINTF = $(LIBFTPRINTF_DIR)$(LIBFTPRINTF_NAME)

$(NAME): $(OBJS) $(LIBFTPRINTF)
	cp ${LIBFTPRINTF_DIR}${LIBFTPRINTF_NAME} $@
	${AR} $@ $(OBJS)

$(LIBFTPRINTF) : 
	make -C $(LIBFTPRINTF_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

clean:
	make -C $(LIBFTPRINTF_DIR) clean
	rm -f $(OBJS)

fclean: clean
	make -C $(LIBFTPRINTF_DIR) fclean
	rm -f $(NAME)

re: fclean all


.PHONY: all clean fclean re