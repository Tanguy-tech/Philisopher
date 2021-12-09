# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Tanguy <Tanguy@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/29 14:13:58 by Tanguy            #+#    #+#              #
#    Updated: 2021/12/09 08:39:10 by Tanguy           ###   ########.fr        #
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

NAME = philo

CC =	gcc

FLAGS =	-Wall -Werror -Wextra

RM = rm -rf

SRCS = errors.c init.c utils.c main.c run.c

HEADER = philo.h

OBJS_SRCS = $(SRCS:.c=.o)

$(NAME):	$(OBJS_SRCS)
				@printf "$(ERASE)$(GREEN)->*.o created with success$(END)\n"
				@$(CC) $(FLAGS) $(OBJS_SRCS) -I $(HEADER) -o $(NAME)

all:	$(NAME)

%.o: %.c $(HEADER)
		 	@$(CC) $(FLAGS) -c $< -o $(<:.c=.o) -I philo.h
		 	@printf "$(ERASE)$(YELLOW)$<....$(END)"

norme:	
		norminette *.c
		norminette *.h
clean:
		@$(RM) $(OBJS_SRCS)
		@printf "$(ERASE)$(RED)-> All files *.o cleaned$(END)\n"

fclean:	clean
		@$(RM) philo
		@printf "$(ERASE)$(RED)-> Executable philo cleaned$(END)\n"
		

re:		fclean all

.PHONY:	all clean fclean re
