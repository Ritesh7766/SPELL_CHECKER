// Author - Ritesh Saha

#include <string.h>
#include <stdio.h>
#include "speller.h"
#include "trie.h"

/*
	Load dictionary in memory.
*/
bool load_dictionary(const char *file_path) {
	// Initialize a trie.
	Node *trie = init();
	
	// Open the file.
	FILE *dict = fopen(file_path, "r");

	if (dict == NULL)
		return false;

	// Buffer to store characters.
	char buffer[BUFFER_SIZE];

	// Add every word in dictionary to the trie.
	while (!feof(dict) ) {
		// Read a word.
		fgets(buffer, BUFFER_SIZE, dict);

		// Replace the newline character with null character.
		buffer[strlen(buffer) - 1] = '\0';

		// Add word in the trie. If failure occurs, then return false.
		if (!add_word(buffer) ) 
			return false;
	}
	fclose(dict);
	return true;
}

/*
	Spell checker
*/
bool spell_check(const char *file_path) {
	// Open the files.
	FILE *text = fopen(file_path, "r");
	FILE *report = fopen("./dict/report.txt", "w");

	// If unable to open files, then return false.
	if (text == NULL || report == NULL)
		return false;

	// Buffer to store characters.
	char buffer[BUFFER_SIZE];

	// Spell check every word in the text file.
	while (!feof(text) ) {
		// Read a word.
		if (!fscanf(text, "%1023s", buffer) )
			return false;

		// If word is incorrect, then report it.
		if (!search(buffer) ) {
			fputs(buffer, report);
			fputs("\n", report);
		}
	}

	fclose(text);
	fclose(report);
	return true;
}

/*
	Unload dictionary.
*/
bool unload_dictionary(void) {
	destroy();
	return true;
}