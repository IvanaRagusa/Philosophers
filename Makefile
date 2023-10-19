# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iragusa <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/28 20:43:31 by iragusa           #+#    #+#              #
#    Updated: 2023/06/28 20:43:34 by iragusa          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philosophers

CC = cc -Wall -Werror -Wextra -pthread

SRC = philosophers.c utils.c actions.c

OBJ = $(SRC:.c=.o)

R = \033[0;31m
G = \033[0;32m
Y = \033[0;33m
LB = \033[1;34m
MAG = \033[1;35m
B = \033[0;34m
NC = \033[0m

all: $(NAME)

$(NAME): $(OBJ)
		$(CC) $(OBJ) -o $(NAME)
		@echo "🎉${G}philosophers compiled!${NC}🎉"

clean:
		@echo "🧽 ${LB}cleaning... ${NC}🧽"
		rm -rf $(OBJ)

fclean: 	clean
		@echo "🚮♻️ spring cleaning, rm $(NAME)... ♻️ 🚮" 
		rm -rf $(NAME)
		
re: 		fclean all 

.SILENT:
