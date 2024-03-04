CC=gcc
CFLAGS=-O3 -g
 
TARGET=test
 
all: $(TARGET)
 
libppm.so : ppm.c
    $(CC) $(CFLAGS)  -fpic -shared $^ -o $@
 
test: main.c libppm.so
    $(CC) $(CFLAGS) $(LDFLAGS) -lppm -L. main.c -o $@
 
clean:
    rm -fr $(TARGET) *.so
CC = gcc
CFLAGS = -Wall -Wextra -std=c99
LDFLAGS = -lm

# Liste des fichiers source
SRC_FILES = mandel.c main.c ppm.c
# Liste des fichiers objets correspondants
#OBJ_FILES = $(SRC_FILES:.c=.o)
# Noms des exécutables
EXEC_TEST = test
EXEC_MANDEL = mandel
# Nom de la bibliothèque partagée
LIB_NAME = libppm.so

# Règle par défaut
all: $(EXEC_TEST) $(EXEC_MANDEL) $(LIB_NAME)

# Règle pour créer l'exécutable 'test'
$(EXEC_TEST): main.o ppm.o
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

# Règle pour créer l'exécutable 'mandel'
$(EXEC_MANDEL): mandel.o ppm.o
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

# Règle pour créer la bibliothèque partagée 'libppm.so'
$(LIB_NAME): ppm.o
	$(CC) -shared -o $@ $^

# Règle générale pour la création des fichiers objets
%.o: %.c
	$(CC) $(CFLAGS) -fPIC -c $< -o $@

# Nettoyer les fichiers temporaires et les exécutables
clean:
	rm -f $(OBJ_FILES) $(EXEC_TEST) $(EXEC_MANDEL) $(LIB_NAME)

