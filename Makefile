# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rayperei <rayaryray14@gmail.com>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/06/28 21:05:01 by rayperei          #+#    #+#              #
#    Updated: 2026/06/28 21:05:02 by rayperei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= push_swap

CC 			= gcc
CFLAGS 		= -Wall -Wextra -Werror

SRCS 		=  src/main.c \
			   src/utils.c \
			   src/validate.c \
			   src/print.c \
			   src/algo_simple.c \
			   src/algo_medium.c \
			   src/algo_complex.c \
			   src/algo_adaptive.c \
			   src/disorder.c \
			   src/index_array.c \
			   src/free_memory.c \
			   src/operations_push.c \
			   src/operations_swap.c \
			   src/operations_rotate.c \
			   src/operations_rev_rotate.c \
			   src/parser.c \
			   src/push_swap_init.c \

OBJS 		= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re