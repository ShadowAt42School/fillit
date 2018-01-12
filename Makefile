# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maghayev <maghayev@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/01 21:51:41 by maghayev          #+#    #+#              #
#    Updated: 2018/01/11 18:09:10 by maghayev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = fillit
CC = gcc
CFLAGS = -Wall -Wextra -Werror
DEPS = fillit.h
SRC  = test.c
MAKES = ./libft/
LIBFT = ./libft/libft.a

OBJECT = $(SRC:.c=.o)

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

all: $(NAME)

$(NAME): ftlib $(OBJECT)
	$(CC) $(CFLAGS) -o $@ $(LIBFT) $(OBJECT)
	@echo "Finished!"

ftlib:
	@echo "Initiating Protocal: LibFtBuild.."
	@make -C $(MAKES)

ftlibclean:
	@echo "Initiating Protocal: LibFtClean.."
	@make clean -C $(MAKES)

ftlibfclean:
	@echo "Initiating Protocal: LibFtDestruction.."
	@make fclean -C $(MAKES)

clean: ftlibclean
	@echo "Cleanning..."
	@/bin/rm -f $(OBJECT)
	@echo "Cleaned"

fclean: clean ftlibfclean
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
