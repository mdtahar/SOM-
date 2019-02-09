CC=gcc 
CFLAGS=-g -Wall 

EXEC = som
all:$(EXEC)

som : vecteur.c traitement.c pile.c neurone.c main.c
	$(CC) $(CFLAGS) $^ -o $@
clean : 
	rm -rf *.o $(EXEC) *~ *.dSYM