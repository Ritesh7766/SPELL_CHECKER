// Author - Ritesh Saha

#ifndef _TRIE_H_
#define _TRIE_H_
#include <stdbool.h>
#include <ctype.h>
#define MAX 26
#define HASH(ch) ((int)tolower(ch) - 97)
#define CHECK_KEY(key) ((0 <= key && key <= 26) ? true : false)


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
bool add_word(const char *word);
bool remove_word(const char *word);
bool search(const char *word);

#endif // _TRIE_H_