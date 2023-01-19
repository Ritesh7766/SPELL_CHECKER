#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "speller.h"


int main(void) {
	char *dict = "./dict/dictionary.txt";
	load_dictionary(dict);
	char *text = "./dict/test.txt";
	spell_check(text);
	unload_dictionary();
	return 0;
}