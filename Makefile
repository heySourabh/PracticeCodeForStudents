LIBS  = -lm
CFLAGS = -Wall

SRC=$(wildcard ./src/*.c)
INC=./include

program.exe: $(SRC)
	gcc -o $@ $^ $(CFLAGS) -I$(INC) $(LIBS)
