#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "trie.h"


int main(void) {
	Node temp;
	Node *trie = init();
	
	FILE *dict = fopen("./dict/test.txt", "r");
	char buffer[50];


	while (!feof(dict) ) {
		fgets(buffer, 50, dict);
		// Get rid of the next line character.
		buffer[strlen(buffer) - 1] = '\0';
		add_word(buffer);
	}
	

	fclose(dict);
	destroy();
	return 0;
}