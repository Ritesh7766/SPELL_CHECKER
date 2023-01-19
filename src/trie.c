// Author - Ritesh Saha

#include <stdlib.h>
#include "trie.h"

// The root node of the trie
Node *ROOT;

/*
	Create a trie and return the root node.
*/
Node* init(void) {
	ROOT = create_node();
	return ROOT;
}

/*
	Free memory allocated for trie.
*/
void destroy(void) {
	__destroy(ROOT);
	return;
}

/*
	Deallocate all the memory by performing a DFS.
	Following is the recursive implementation.
	// TODO: Create an iterative implementation.
*/
void __destroy(Node *const node) {
	if (node == NULL)
		return;
	for (int i = 0; i < MAX; i++)
		__destroy(node->map[i]);
	free(node);
	return;
}

/*
	Initialize a node.
*/
Node* create_node(void) {
	Node *node = (Node*)malloc(sizeof(Node) );
	// If memory allocation fails, then return NULL. [Failure may occur due to insufficient memory]
	if (node == NULL)
		return NULL;
	// Otherwise initialize the node and return its address.
	node->EOW = false;
	for (int i = 0; i < MAX; i++)
		node->map[i] = NULL;
	return node;
}

/*
	Add a word in the trie.
*/
bool add_word(const char *word, const int length) {
	Node *trev = ROOT;
	for (int i = 0; i < length; i++) {
		// Generate a key.
		int key = HASH(word[i]);
		// If the path dosen't exists, then create one.
		if (trev->map[key] == NULL) {
			Node *new_node = create_node();
			// If memory allocation fails, then return false. [Failure may occur due to insufficient memory]
			if (new_node == NULL)
				return false;
			trev->map[key] = create_node();
		}
		// Follow the path.
		trev = trev->map[key];
	}
	// Mark the end of word.
	trev->EOW = true;
	return true;
}

/*
	Remove a word from the trie. Note that we not deallocating any memory.
*/
bool remove_word(const char *word, const int length) {
	Node *trev = ROOT;
	for (int i = 0; i < length; i++) {
		// Generate a key.
		int key = HASH(word[i]);
		// If path doesn't exists, then return false.
		if (trev->map[key] == NULL)
			return false;
		// Otherwise, follow the path.
		trev = trev->map[key];
	}
	trev->EOW = false;
	return true;
}

/*
	Search a word in the trie.
*/
bool search(const char *word, const int length) {
	Node *trev = ROOT;
	for (int i = 0; i < length; i++) {
		// Generate a key.
		int key = HASH(word[i]);
		// If path dosen't exists, then return false.
		if (trev->map[key] == NULL)
			return false;
		// Otherwise, follow the path.
		trev = trev->map[key];
	}
	return trev->EOW;
}