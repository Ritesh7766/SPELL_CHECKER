// Author - Ritesh Saha

#ifndef _TRIE_H_
#define _TRIE_H_
#define MAX 26
#define HASH(ch) ((int)ch - 97)
#include <stdbool.h>

// Custom struct representing the node of a trie.
typedef struct Node {
	struct Node *map[MAX];
	bool EOW;
} Node;

// Function prototypes.
Node* init(void);
Node* create_node(void);
void destroy(void);
void __destroy(Node*);
bool add_word(const char *word, const int length);
bool remove_word(const char *word, const int length);
bool search(const char *word, const int length);

#endif // _TRIE_H_