NAME = convert

CPPFLAGS = -Wall -Wextra -Werror -std=c++98

CPP = c++

SRC = ScalarConverter.cpp main.cpp

HEADERS = ScalarConverter.hpp

OBJ = $(SRC:.cpp=.o)

all :  $(NAME)

$(NAME) : $(OBJ)
	$(CPP) $(CPPFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp $(HEADERS)
	$(CPP) $(CPPFLAGS) $(SRC) -c 

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.Phony : clean 