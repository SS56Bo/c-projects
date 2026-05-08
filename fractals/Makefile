CC = gcc
CFLAGS = -Wall -Wextra -std=c11
RAYFLAGS = -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

game: main.c
	$(CC) $(CFLAGS) -o game main.c $(RAYFLAGS)

clean:
	rm -f game