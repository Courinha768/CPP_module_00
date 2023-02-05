NAME			= megaphone

SRCS			= megaphone.cpp
OBJS			= $(SRCS:.cpp=.o)

CC				= c++
CFLAGS			= -Wall -Wextra -Werror -I. -std=c++98

all:			$(NAME)

$(NAME):		$(OBJS)
				@$(CC) $(FLAGS) -o $(NAME) $(OBJS)

clean:
				@rm $(OBJS)

fclean:			clean
				@rm $(NAME)

re:				@fclean $(NAME)

.PHONY:			all clean fclean re