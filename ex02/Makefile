#Executable name
NAME = array

#Compiler and flags 
CC = c++
IFLAGS = -I include
FLAGS = -g -Wall -Wextra -Werror -std=c++98 ${IFLAGS}

#Header files
HDRS = include/Array.hpp

#Source files
SRCS = src/main.cpp 

#Object file

OBJS = $(SRCS:src/%.cpp=obj/%.o)

all: $(NAME)

obj:
	mkdir -p obj 

$(NAME): obj $(OBJS) 
	$(CC) $(FLAGS) $(OBJS) -o $(NAME) 

#Compile individual object files
obj/%.o: src/%.cpp $(HDRS)
	$(CC) $(FLAGS) -c $< -o $@


# Clean object files
clean:
	rm -f $(OBJS)

# Clean everything
fclean: clean
	rm -f $(NAME)
	
# Rebuild everything
re: fclean all


# Valgrind check
valgrind: $(NAME)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME)

.PHONY: all clean fclean re