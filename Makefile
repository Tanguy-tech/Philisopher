# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tanguy <tanguy@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/10 10:07:12 by tanguy            #+#    #+#              #
#    Updated: 2021/08/16 09:24:41 by tanguy           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ERASE       =   \033[2K\r
GREY        =   \033[30m
RED         =   \033[31m
GREEN       =   \033[32m
YELLOW      =   \033[33m
BLUE        =   \033[34m
PINK        =   \033[35m
CYAN        =   \033[36m
WHITE       =   \033[37m
BOLD        =   \033[1m
UNDER       =   \033[4m
SUR         =   \033[7m
END         =   \033[0m

HEAD = philo.h

CC = gcc

RM = rm -rf

FLAGS = -Wall -Werror -Wextra

all:		$(NAME)

$(NAME):	$(OBJS)
			$(CC) $(FLAGS) -o philo $(OBJS) $(HEAD)

norme:		
			@norminette *.c

clean :
			@$(RM) *.o
			@printf "$(ERASE)$(RED)-> All files .o cleaned$(END)\n"

fclean : clean
			@$(RM) $(NAME)
			@printf "$(ERASE)$(RED)-> All files cleaned$(END)\n"

re:			fclean $(NAME)

.PHONY: 	all fclean clean re