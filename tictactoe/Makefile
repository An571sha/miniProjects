CC=gcc
CFLAGS=-Wextra -Werror -Wall -pedantic -std=c99

.PHONY: clean

run: game
	astyle --style=stroustrup *.c *.h
	cppcheck *.c *.h
	valgrind ./game

run-pi: game-pi
	astyle --style=stroustrup *.c *.h
	cppcheck *.c *.h
	./game-pi

game: main.c grid.c
	$(CC) $(CFLAGS) -g $^ -o@

game-pi: main.c grid.c
	$(CC) $(CFLAGS) -g -fsanitize=address -fno-omit-frame-pointer $^ -o $@ -static-libasan
	

clean:
	rm -rf game game-pi *.orig
