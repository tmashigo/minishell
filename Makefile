# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmashigo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/17 09:02:52 by tmashigo          #+#    #+#              #
#    Updated: 2018/09/17 09:03:18 by tmashigo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = minishell

FLAGS = gcc -Wall -Wextra -Werror

SRC = main.c exec_command.c my_environ.c echo_builtin.c setenv_builtin.c cd_builtin.c 

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	@make -C libft/
	@$(FLAGS) -c $(SRC)
	@$(FLAGS) -o $(NAME) $(SRC) -L libft/ -lft

clean:
	@make clean -C libft/
	@rm -rf $(OBJ)

fclean: clean
	@make fclean -C libft/
	@rm -rf $(NAME)

re: fclean all

norm:
	@echo "\033[32m  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\033[0m"
	@echo "\033[32m%##############| 0.00% |#################%\033[0m"
	@norminette $(SRC) minishell.h
	@echo "\033[32m%##############| 100%  |#################%\033[0m"
	@echo "\033[32m  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\033[0m"
