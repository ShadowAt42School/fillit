# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maghayev <maghayev@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/01 21:51:41 by maghayev          #+#    #+#              #
#    Updated: 2018/01/22 14:41:11 by maghayev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = fillit
CC = gcc
CFLAGS = -Wall -Wextra -Werror
DEPS = fillit.h
SRC  = main.c tetra_parse.c tetra_parse_helper.c tetra_solver.c \
		tetra_solve_helper.c tetra_printing.c
LIBS = ./libft
LIBA = $(LIBS)/libft.a

OBJECT = $(SRC:.c=.o)

%.o: %.c $(DEPS)
	$(CC) -c -g -o $@ $< $(CFLAGS)

all: $(NAME)

$(NAME): ftlib $(OBJECT)
	$(CC) $(CFLAGS) $(OBJECT) $(LIBA) -o $@
	@echo "Finished!"

ftlib:
	@echo $(LIBS)
	@echo "Initiating Protocol: LibBuild.."
	@make -C $(LIBS)

ftlibclean:
	@echo "Initiating Protocal: LibFtClean.."
	@make clean -C $(LIBS)

ftlibfclean:
	@echo "Initiating Protocal: LibFtDestruction.."
	@make fclean -C $(LIBS)

clean: ftlibclean
	@echo "Cleanning..."
	@/bin/rm -f $(OBJECT)
	@echo "Cleaned"

fclean: clean ftlibfclean
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
