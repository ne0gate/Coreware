##
## EPITECH PROJECT, 2023
## corewar
## File description:
## Makefile
##

CC ?= gcc

SRC = op.c

SRC_ASM = asm/add_ptr_to_array.c\
		asm/asm.c\
		asm/ernno.c\
		asm/fclose.c\
		asm/fill_line.c\
		asm/format.c\
		asm/malloc.c\
		asm/my_strlen_until.c\
		asm/my_strlen.c\
		asm/my_strnbr_base.c\
		asm/random.c\
		asm/write_command.c\
		asm/my_array_len.c\
		asm/my_strcpy.c\
		asm/my_strncmp.c\
		asm/rm_2d_array.c\
		asm/my_getnbr.c

SRC_VM =

OBJ = $(SRC:.c=.o)

OBJ_ASM = OBJ
OBJ_ASM += $(SRC_ASM:.c=.o)

OBJ_VM = OBJ
OBJ_VM += $(SRC_VM:.c=.o)

CFLAGS += -Wall -Wextra

INCLUDE_DIR += includes

CPPFLAGS += $(foreach inc, $(INCLUDE_DIR), -iquote$(inc))

LIB +=

LIB_DIR +=

LIB_TO_MAKE +=

LDFLAGS += $(foreach lib, $(LIB_DIR), -L$(lib))
LDLIBS += $(foreach lib, $(LIB), -l$(lib))

TEST_DIR = ./tests

TESTFLAGS += --coverage -lcriterion

TESTFILES =

TESTS += $(foreach test, $(TESTFILES), $(TEST_DIR)/$(test))

NAME_ASM = asm/asm

NAME_VM = vm/corewar

TEST_NAME = $(NAME)-unit-test

all: $(NAME)

make_lib:
	$(foreach lib, $(LIB_TO_MAKE), make -i -C $(lib);)

$(NAME): make_lib $(OBJ_ASM) $(OBJ_VM)
	$(CC) $(OBJ_ASM) -o $(NAME_ASM) $(CFLAGS) $(LDFLAGS) $(LDLIBS)
	$(CC) $(OBJ_VM) -o $(NAME_VM) $(CFLAGS) $(LDFLAGS) $(LDLIBS)

clean:
	$(foreach lib, $(LIB_TO_MAKE), make clean -i -C $(lib);)
	rm -f $(OBJ)
	rm -f $(OBJ_ASM)
	rm -f $(OBJ_VM)

fclean: clean
	$(foreach lib, $(LIB_TO_MAKE), make fclean -i -C $(lib);)
	rm -f $(NAME_ASM)
	rm -f $(NAME_VM)

$(TEST_NAME): re
	$(CC) -o $(TEST_NAME) $(TESTS) $(OBJ) $(OBJ_ASM) $(OBJ_VM) $(CFLAGS) \
	$(LDFLAGS) $(LDLIBS) $(TESTFLAGS)

tests_run: $(TEST_NAME)
	./$(TEST_NAME)
	gcovr $(foreach test, $(TESTS), --exclude $(test))
	gcovr $(foreach test, $(TESTS), --exclude $(test)) -b

re: fclean all

.PHONY	: clean fclean re all make_lib
