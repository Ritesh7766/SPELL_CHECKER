CC = gcc
INC = ./inc
LIB = ./lib
OBJ = ./obj
BIN = ./bin
SRC = ./src

OBJECTS = $(OBJ)/trie.o
LIBRARIES = $(LIB)/libdsa_s.a $(LIB)/libdsa_d.so
HEADERS = $(INC)/trie.h
BINARIES = $(BIN)/test_static $(BIN)/test_dynamic

all: init $(OBJECTS) $(LIBRARIES) $(BINARIES)

$(OBJ)/trie.o: $(SRC)/trie.c $(INC)/trie.h
	$(CC) -fpic -c $< -o $@ -I $(INC)
	
$(LIB)/libdsa_s.a: $(OBJECTS)
	ar cr $@ $^

$(LIB)/libdsa_d.so: $(OBJECTS)
	gcc -o $@ $^ -shared
	
$(BIN)/test_static: test.c $(LIB)/libdsa_s.a $(INC)/trie.h
	$(CC) test.c -ldsa_s -lc -I $(INC) -L $(LIB) -o $@

$(BIN)/test_dynamic: test.c $(LIB)/libdsa_d.so $(INC)/trie.h
	$(CC) test.c -ldsa_d -lc -I $(INC) -L $(LIB) -o $@

.PHONY: clean init

init:
	mkdir lib obj bin
	
clean:
	rm -r $(LIB) $(OBJ) $(BIN)
