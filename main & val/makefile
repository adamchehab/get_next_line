SOURCES = ../gnl_files/get_next_line.c ../gnl_files/get_next_line_utils.c
FLAGS =  -Wall -Wextra -Werror -D BUFFER_SIZE=3

all: clean
	@gcc $(FLAGS) main.c $(SOURCES) -o main

mem: clean
	@gcc $(FLAGS) -g -Og -std=gnu99 main.c $(SOURCES) -o main

clean:
	@rm -f main