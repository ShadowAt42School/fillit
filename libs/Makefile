# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maghayev <maghayev@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/15 22:17:21 by maghayev          #+#    #+#              #
#    Updated: 2018/01/15 23:54:08 by maghayev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

_DEPS = libft.a libmath.a
CLEANT = $(patsubst %.a, ./% ,$(_DEPS))

# all: $(_DEPS)
all:
	make -C libft
	make -C libmath

clean:
	make clean -C libft
	make clean -C libmath

fclean:
	make fclean -C libft
	make fclean -C libmath

# %.a: %
# 	make -C $<

# clean: $(CLEANT)
# 	echo $(MAKEFLAGS)
#
# fclean: $(CLEANT)
#
#
# $(CLEANT):
# 	@make clean -C $@

re: fclean all

.PHONY: all clean fclean re $(CLEANT) $(FCLEAN)
