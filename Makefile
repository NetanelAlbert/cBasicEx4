all: frequency

frequency: main.o trie.o stringFunctions.o
	gcc main.o trie.o stringFunctions.o -o frequency

main.o: main.c trie.h stringFunctions.h
	gcc -c main.c

trie.o: trie.c trie.h
	gcc -c trie.c

stringFunctions.o: stringFunctions.c
	gcc -c stringFunctions.c


.PHONY: all clean

clean:
	*.o frequency
