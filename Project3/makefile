CC = gcc
CFLAGS = -Wall -lm
SRC = champion.c main.c
OBJ = $(SRC:.c=.o)

project3Exe: $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ)

%.o: %.c champion.h
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(OBJ) project3Exe
