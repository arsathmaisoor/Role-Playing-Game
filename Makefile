all: main.c
	g++ -o project3Exe main.c 

run:
	./project3Exe $(INT)

