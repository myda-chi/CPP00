NAME= phoneBook
CC:=c++
CPPFLAGS:= -Wall -Wextra -Werror -std=c++98
SRC = Main.cpp Contact.cpp PhoneBook.cpp

OBJ:= $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CPPFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -rf  $(OBJ)

fclean:	clean
	rm -rf  $(NAME)

re:		fclean all
.PHONY: all clean fclean re 