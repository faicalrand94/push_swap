# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fbouibao <fbouibao@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/09 09:29:29 by fbouibao          #+#    #+#              #
#    Updated: 2021/06/09 20:04:16 by fbouibao         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

FLAGS =  -Wall -Wextra -Werror

SRC = push_swap.c src/check_error_management.c src/ft_split.c src/less_150.c\
src/less_20.c src/less_5.c src/more_150.c src/ps_instraction_tools.c\
src/ps_tools1.c src/ps_tools2.c src/sort_table.c src/libft_fts.c\

SRC_B = checker_bonus.c src_bonus/check_error_management_bonus.c\
src_bonus/ft_split_bonus.c src_bonus/libft_fts_bonus.c\
src_bonus/ps_instraction_tools_bonus.c src_bonus/ps_tools1_bonus.c\
src_bonus/ps_tools2_bonus.c src_bonus/sort_table_bonus.c\

CC = gcc

all: $(NAME)

NAME_B = checker

$(NAME):
	$(CC) $(FLAGS) $(SRC) -o $(NAME)

bonus: $(NAME_B)

$(NAME_B):
	$(CC) $(FLAGS) $(SRC_B) -o $(NAME_B)

clean:
	@echo "no .o available"

fclean: clean 
	@rm -rf $(NAME) $(NAME_B)
	
re: fclean all