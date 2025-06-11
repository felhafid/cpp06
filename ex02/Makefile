NAME = serialization

CPP = c++

CPPFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = Serializer.cpp main.cpp

OBJ = Serializer.o main.o

all : $(NAME)

$(NAME) : $(OBJ) 
	$(CPP) $(CPPFLAGS) $(OBJ) -o $(NAME)

%.o : %.cpp Serializer.hpp
	$(CPP) $(CPPFLAGS) $(SRC) -c 

clean : 
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.Phony : clean