CC = gcc
CFLAGS = -g -Wall 
DEPS = functions.h playerInfo.h
OBJ = main.o locations.o mainmenu.o questions.o

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $<
main: $(OBJ)
	gcc $(CFLAGS) -o $@ $^

.PHONY: clean
clean:
	rm -f main
	rm -f locations.o
	rm -f main.o
	rm -f mainmenu.o
	rm -f questions.o