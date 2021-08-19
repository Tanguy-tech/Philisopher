# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tanguy <tanguy@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/10 10:07:12 by tanguy            #+#    #+#              #
#    Updated: 2021/08/19 10:33:29 by tanguy           ###   ########.fr        #
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

SRCS = actions.c errors.c init.c main.c philosopher.c utils.c 

OBJS_SRCS = $(addprefix ./srcs/, $(SRCS:.c=.o))

CC = gcc

RM = rm -rf

FLAGS = -Wall -Werror -Wextra

$(NAME):	$(OBJS_SRCS)
			@printf "$(ERASE)$(GREEN)-> Files .o Created with success$(END)\n"
			@$(CC) $(FLAGS) $(OBJS_SRCS) -I $(OBJS_HEADERS) -o philo
			@printf "$(CYAN)-> Executable file philo created with success!$(END)\n"

all:	$(NAME)

%.o: %.c $(OBJS_HEADERS)
		 @$(CC) $(FLAGS) -c $< -o $(<:.c=.o) -I $(HEAD)
		 @printf "$(ERASE)$(YELLOW)$<....$(END)"

norme:		
			@norminette srcs/*.c

clean :
			@$(RM) *.o
			@printf "$(ERASE)$(RED)-> All files .o cleaned$(END)\n"

fclean : clean
			@$(RM) $(NAME)
			@printf "$(ERASE)$(RED)-> All files cleaned$(END)\n"

re:			fclean $(NAME)

.PHONY: 	all fclean clean re