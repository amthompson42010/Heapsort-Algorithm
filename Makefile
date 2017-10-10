CFILES = heapsort.c queue.c binaryTree.c

heapsort: $(CFILES)
	gcc -Wall -o heapsort $(CFILES)

clean:
	rm -f *.o

run: heapsort
	./heapsort integers
