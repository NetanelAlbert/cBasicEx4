FLAGS = -Wall -Werror -g

all: frequency

frequency: main.o trie.o stringFunctions.o
	gcc $(FLAGS) main.o trie.o stringFunctions.o -o frequency

main.o: main.c trie.h stringFunctions.h
	gcc $(FLAGS) -c main.c

trie.o: trie.c trie.h
	gcc $(FLAGS) -c trie.c

stringFunctions.o: stringFunctions.c
	gcc $(FLAGS) -c stringFunctions.c


.PHONY: all clean

clean:
	rm -f *.o frequency
