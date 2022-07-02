SRCS = main.c check_parameters.c philo_util1.c philo_util2.c routine.c

OBJS = $(SRCS:.c=.o)

CC = cc

#CFLAGS = -Wall -Wextra -Werror -fsanitize=thread

CFLAGS = -Wall -Wextra -Werror

NAME = philo

$(NAME) :
		$(CC) $(CFLAGS) -o $(NAME) $(SRCS)

all : $(NAME)

clean :
		rm -f $(OBJS)

fclean : clean
		rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re
