NAME			= phonebook

SRCS			= Account.cpp tests.cpp
OBJS			= $(SRCS:.cpp=.o)

CXX				= c++
CXXFLAGS		= -Wall -Wextra -Werror -I. -std=c++98

all:			$(NAME)

$(NAME):		$(OBJS)
				$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

clean:
				@rm $(OBJS)

fclean:			clean
				@rm $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re