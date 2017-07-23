all: createBash parallel serial

createBash: createBash.cpp
	g++ -o createBash createBash.cpp

parallel: parallel.c
	gcc -o parallel parallel.c

serial: serial.c
	gcc -o serial serial.c
