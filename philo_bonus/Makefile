SRCS = main.c check_parameters_bonus.c philo_util1_bonus.c philo_util2_bonus.c routine_bonus.c

OBJS = $(SRCS:.c=.o)

CC = cc

#CFLAGS = -Wall -Wextra -Werror -fsanitize=thread

CFLAGS = -Wall -Wextra -Werror

NAME = philo_bonus

$(NAME) :
		$(CC) $(CFLAGS) -o $(NAME) $(SRCS)

all : $(NAME)

clean :
		rm -f $(OBJS)

fclean : clean
		rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re
