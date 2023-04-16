#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct trie_ {
	struct trie_* alphabet[26];
	int end;
	int freq;
}trie;



trie* new_trie();

void insert(char str[], int limit, trie* root);

void search(char str[], int index, trie* root);

void free_trie(trie* root);



int main() {
	return 0;
}

trie* new_trie() {
	trie* tmp = (trie*)malloc(sizeof(trie));
	for (int i = 0; i < 26; i++) {
		tmp->alphabet[i] = NULL;
	}
	tmp->end = 0;
	tmp->freq = 0;
	return tmp;
}



void insert(char str[], int limit, trie* root) {
	if (str[limit - 1] == 0) return;

	trie* curr = root;

	for (int i = 0; str[i] != '\0'; i++) {
		int index = str[i] - 'a';

		if (curr->alphabet[index] == NULL) {
			curr->alphabet[index] = new_trie();
		}
		curr = curr->alphabet[index];
	}

	curr->end = 1;
	curr->freq++;
}

void all_trie(char str[], int index, trie* root) {
	trie* curr = root;

	for (int i = 0; i < 26; i++) {
		if (curr->alphabet[i] != NULL) {
			str[index] = i + 'a';
			search(str, index + 1, curr->alphabet[i]);
		}
	}

	if (curr->end) {
		str[index] = 0;
		printf("%s\n", str);
	}
}

void free_trie(trie* root) {
	trie* curr = root;

	for (int i = 0; i < 26; i++) {
		if (curr->alphabet[i] != NULL) {
			free_trie(curr->alphabet[i]);
		}
	}

	free(root);
}
