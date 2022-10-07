##
## EPITECH PROJECT, 2022
## TODO_Plazza
## File description:
## Makefile
##

SRC				=	$(wildcard src/core/*.cpp)				\
					$(wildcard src/kitchen/*.cpp)			\
					$(wildcard src/pizza/*.cpp)				\
					$(wildcard src/reception/*.cpp)			\
					$(wildcard src/IPC/*.cpp)

OBJ				=	$(SRC:.cpp=.o)

NAME 			= 	plazza

CXX				=	g++

CXX 			+= 	-I ./include -I src/kitchen -I src/pizza -I src/reception -I src/IPC

PLAZZA_FLAGS	=	-lrt -lpthread -lssl -lcrypto

all:				$(NAME)

$(NAME):  			$(OBJ)
					$(CXX) -o $(NAME) $(OBJ) $(PLAZZA_FLAGS)
					rm -f $(OBJ)
clean:
					rm -f $(OBJ)

fclean:				clean
					rm -f $(NAME)
					rm -f $(OBJ)

re:					fclean all

.PHONY:				all clean fclean re