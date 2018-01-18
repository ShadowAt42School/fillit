# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maghayev <maghayev@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/01 21:51:41 by maghayev          #+#    #+#              #
#    Updated: 2018/01/18 02:28:34 by maghayev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = libmath.a
PURPLE = "\033[35m\c"
RED = "\033[31m\c"
NC="\033[0m\c"
CC = gcc
CFLAGS = -Wall -Wextra -Werror
DEPS = libmath.h
SRC  = ft_floorsqrt.c ft_min.c

OBJECT = $(SRC:.c=.o)

%.o: %.c $(DEPS)
	@echo $(RED)
	$(CC) $(CFLAGS) -g -c -o $@ $<
	@echo $(NC)

all: $(NAME)

$(NAME): $(OBJECT)
	@ar rc $@ $^
	@ranlib $@
	@echo "Finished Building LibMath!"

clean:
	@echo $(RED)
	@echo "*sadly* Cleanning LibMath... Wait... *sniffs*"
	@/bin/rm -f $(OBJECT)
	@echo "Cleaned LibMath! Bye Bye! *without intusiasm*"
	@echo $(NC)

fclean: clean
	@/bin/rm -f $(NAME)
	@echo "LibMath .a has been deleted! *sign*"

re: fclean all

.PHONY: all clean fclean re
