all: parallel serial

parallel: parallel.c
	gcc -o parallel parallel.c

serial: serial.c
	gcc -o serial serial.c
