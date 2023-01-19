#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include "speller.h"


int main(void) {
	clock_t ld = clock();
	load_dictionary("./dict/dictionary.txt");
	ld = clock() - ld;
	
	clock_t sd = clock();
	spell_check("./dict/HP1.txt");
	sd = clock() - sd;

	clock_t ud = clock();
	unload_dictionary();
	ud = clock() - ud;

	printf("Load Dictionary: %f\nSpell Check: %f\nUnload: %f\n", ((double)ld) / CLOCKS_PER_SEC, ((double)sd) / CLOCKS_PER_SEC, ((double)ud) / CLOCKS_PER_SEC); 

	return 0;
}