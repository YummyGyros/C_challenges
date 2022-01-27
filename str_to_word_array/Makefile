##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Vm makefile
##

## USEFUL DEF ########################

CC			=	gcc
BIN			=	str_to_word_arr
TEST_BIN	=	unit_tests

#######################################

## FILES ##############################

SRC_FILES	=	str_to_word_array.c

TEST_FILES		=	test_str_to_word_array.c

#######################################


## SOURCES ############################

MAIN		=	main.c

SRC			=	$(addprefix , $(SRC_FILES))		\

TESTS		=	$(addprefix , $(TEST_FILES))		\

#######################################

## OBJ ################################

MAIN_OBJ	=	$(MAIN:.c=.o)

SRC_OBJ		=	$(SRC:.c=.o)

TESTS_OBJ	=	$(TESTS:.c=.o)

#######################################

## FLAGS ##############################

CFLAGS		=	-W -Wall -Wextra

DBGFLAGS	=	-k8 -g3 -ggdb -Werror

LDFLAGS		=

INCLUDE		=	-iquote ./include

#######################################

## RULES ##############################

%.o:    %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c -o $@ $<

all : $(BIN)

$(BIN): $(MAIN_OBJ) $(SRC_OBJ)
	$(CC) -o $(BIN) $(MAIN_OBJ) $(SRC_OBJ) $(CFLAGS) $(LDFLAGS)


clean:
	@$(RM) $(MAIN_OBJ)
	@$(RM) $(SRC_OBJ)
	@$(RM) $(TESTS_OBJ)
	@$(RM) Makefile~
	@$(RM) src/**/*.gc*
	@$(RM) src/*.gc*
	@$(RM) tests/*.gc*

fclean: clean
	@$(RM) $(BIN)
	@$(RM) $(TEST_BIN)

re: fclean all

tests_run:  CFLAGS += --coverage
tests_run:  LDFLAGS += -lcriterion
tests_run:	$(TESTS_OBJ) $(SRC_OBJ)
	$(CC) -o $(TEST_BIN) $(TESTS_OBJ) $(SRC_OBJ) $(CFLAGS) $(LDFLAGS)
	-./$(TEST_BIN)
	gcovr -b --exclude-directories tests
	gcovr -r . --exclude-directories tests
	@$(RM) $(TEST_BIN)

.PHONY: all $(BIN) clean fclean re tests_run

#######################################
