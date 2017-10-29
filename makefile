prod: main.c
	gcc -o program main.c
clean: program
	rm -f program
