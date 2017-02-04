LIBS  = -lm
CFLAGS = -Wall

SRC=$(wildcard *.c)
INC=./include

program.exe: $(SRC)
	gcc -o $@ $^ $(CFLAGS) -I$(INC) $(LIBS)
