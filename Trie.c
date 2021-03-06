#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ALPHABET_SIZE (26)
#define ARRAY_SIZE(a) sizeof(a)/sizeof(a[0])
#define CHAR_TO_INDEX(c) ((int)c - (int)'a')

typedef struct trie_node trie_node_t;
struct trie_node{
	int value;
	trie_node_t *children[ALPHABET_SIZE];
};

typedef struct trie trie_t;
struct trie{
    trie_node_t *root;
    int count;
};

trie_node_t *makeNode(){
	int i = 0;
	trie_node_t *pNode = NULL;
	pNode = (trie_node_t*)malloc(sizeof(trie_node_t));
	pNode->value = 0;
	for(i = 0; i < ALPHABET_SIZE; i++){
		pNode->children[i] = NULL;
	}
	return pNode;
}

void initialize(trie_t *pTrie){
	pTrie->root = makeNode();
	pTrie->count = 0;
}

void insert(trie_t *pTrie, char key[]){
	int level;
	int length = strlen(key);
	int index;
	trie_node_t *pCrawl;

	pTrie->count++;
	pCrawl = pTrie->root;

	for(level = 0; level < length; level++){
		index = CHAR_TO_INDEX(key[level]);
		if(!pCrawl->children[index])
			pCrawl->children[index] = makeNode();
		pCrawl = pCrawl->children[index];
	}
	pCrawl->value = pTrie->count;
}

int search(trie_t *pTrie, char key[]){
	int level;
	int length = strlen(key);
	int index;
	trie_node_t *pCrawl;

	pCrawl = pTrie->root;

	for(level = 0; level < length; level++){
		index = CHAR_TO_INDEX(key[level]);

		if(!pCrawl->children[index])
			return 0;
		pCrawl = pCrawl->children[index];
	}

	return (pCrawl != 0 && pCrawl->value);
}

int main()
{
    // Input keys (use only 'a' through 'z' and lower case)
    char keys[][8] = {"the", "a", "there", "answer", "any", "by", "bye", "their"};
    trie_t trie;
 
    char output[][32] = {"Not present in trie", "Present in trie"};
 
    initialize(&trie);
 	int i =0;
    // Construct trie
    for(i = 0; i < ARRAY_SIZE(keys); i++)
    {
        insert(&trie, keys[i]);
    }
 
    // Search for different keys
    printf("%s --- %s\n", "the", output[search(&trie, "the")] );
    printf("%s --- %s\n", "these", output[search(&trie, "these")] );
    printf("%s --- %s\n", "their", output[search(&trie, "their")] );
    printf("%s --- %s\n", "thaw", output[search(&trie, "thaw")] );
 
    return 0;
}
