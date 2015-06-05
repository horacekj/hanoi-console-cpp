all: main.cpp TextGraf.cpp TextGraf.h Const.h GrHanoi.h GRMove.cpp
	mingw32-g++ -Wall -o Hanoi.exe main.cpp TextGraf.cpp GrHanoi.h GrMove.cpp
clean:
	rm -f Hanoi.exe
