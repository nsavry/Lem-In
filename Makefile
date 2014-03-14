# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nsavry <nsavry@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/14 05:48:46 by nsavry            #+#    #+#              #
#    Updated: 2014/02/23 23:12:10 by nsavry           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

FTC = ft_current_main.c\
	  ft_current_init.c\
	  ft_current_error.c\
	  ft_current_read.c\
	  ft_current_check.c\
	  ft_current_display.c\
	  ft_current_link.c\
	  ft_current_solve.c\
	  ft_current_cross.c

FTO = $(subst .c,.o,$(FTC))

.PHONY: all re clean fclean

all: $(NAME)

$(NAME): $(FTO)
	@Make -C ./libft
	@echo "[libft][ok]"
	@gcc -o $(NAME) -L./libft -lft $(FTO)
	@echo "[$(NAME)][ok]"

%.o: %.c
	@clear
	@gcc -Wall -Werror -Wextra -I./ -I./libft/includes -c $<
	@echo "[c files][ok]"

clean:
	@make -C ./libft clean
	@rm -rf $(FTO)

fclean: clean
	@make -C ./libft fclean
	@rm -rf $(NAME)

re: fclean all
