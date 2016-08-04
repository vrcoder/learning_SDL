INCPATH=-I /usr/local/Cellar/sdl2/2.0.4/include
LIBPATH=-L /usr/local/Cellar/sdl2/2.0.4/lib
FLAG=-lSDL2main -lSDL2

all:
	gcc -o main main.cpp $(FLAG) $(INCPATH) $(LIBPATH)
clean:
	rm -rf main
