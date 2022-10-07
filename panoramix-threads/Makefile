SRC	=	$(wildcard ./src/*.c)

NAME = panoramix

CC	=	gcc

CFLAGS += -I./include/

THREAD_FLAGS = -lpthread -D_REETRANT -lrt -g3

OBJ	=	$(SRC:.c=.o)

all:	$(NAME)

$(NAME):  $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(THREAD_FLAGS)
	rm -f $(OBJ)
clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)
	rm -f $(OBJ)

re:	fclean all

.PHONY:	all clean fclean re
