##
## EPITECH PROJECT, 2022
## makefile
## File description:
## coreware
##

SRC =  src/vm1test.c 

OBJ =	$(SRC:.c=.o)

NAME	=	vmcw

CFLAGS = -g3 -Wall -Wextra

CPPFLAGS = -I include

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(CFLAGS) $(CPPFLAGS)

coverage:
		gcovr --exclude tests/

clean:
	rm -f $(OBJ)
	rm -f *~

fclean: 	clean
	rm -f $(NAME)

re: fclean all
