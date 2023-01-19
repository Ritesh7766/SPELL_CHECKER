#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "trie.h"


int main(void) {
	Node temp;
	Node *trie = init();
	char *buffer = "RiTesh";
	bool a = search(buffer, 6);
	bool b = add_word(buffer, 6);
	bool c = search(buffer, 6);
	bool d = remove_word(buffer, 6);
	bool e = search(buffer, 6);
	printf("%d %d %d %d %d\n", a, b, c, d, e);
	destroy();
	return 0;
}