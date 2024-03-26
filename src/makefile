CFLAGS=-Wall --std=c11
outName=appGame
SRC=$(wildcard *.c)
OBJ=$(SRC:.c=.o)
HDR=$(wildcard *.h)
$(outName): $(OBJ) $(HDR)
	$(CC) $(CFLAGS) -lm -lc $^ -o $@
debug: $(OBJ) $(HDR)
	$(CC) $(CFLAGS) -lm -lc -g $^ -o $@
	gdb debug
%.o:%.c
	$(CC) $(CFLAGS) -c -g $^ -o $@

.Phony:clean debug

clean:
	rm $(outName) *.o debug

