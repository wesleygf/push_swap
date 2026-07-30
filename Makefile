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

SRCS 		=  main.c \
			   utils.c \
			   validate.c \
			   print.c \
			   algo_simple.c \
			   algo_medium.c \
			   algo_complex.c \
			   algo_adaptive.c \
			   disorder.c \
			   index_array.c \
			   free_momory.c \
			   operations_push.c \
			   operations_swap.c \
			   operations_rotate.c \
			   operations_rev_rotate.c \
			   parser.c \
			   push_swap_init.c \

OBJS = $(SRCS:.c=.o)

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