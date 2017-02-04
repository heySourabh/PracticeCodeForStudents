LIBS  = -lm
CFLAGS = -Wall

SRC=$(wildcard ./src/*.c)
INC=./include
HDR=$(wildcard ./include/*h)

program.exe: $(SRC) $(HDR)
	gcc -o $@ $(SRC) $(CFLAGS) -I$(INC) $(LIBS)
