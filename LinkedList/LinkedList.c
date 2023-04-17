#include <stdio.h>
#include <stdlib.h>

typedef struct linked_list {
	int data;
	struct linked_list_* next;
}l_list;

l_list* new_l_list();

void add(int data, l_list* root);

void insert(int index, int data, l_list* root);

void print(int index, l_list* root);

void print_all(l_list* root);

void reverse_print_all(l_list* root);

void free_l_list(l_list* root);

int main() {

}

l_list* new_l_list() {
	l_list* tmp = (l_list*)malloc(sizeof(l_list));
	tmp->data = 0;
	tmp->next = NULL;
	return tmp;
}

void add(int data, l_list* root) {
	l_list* tmp = root;
	while (tmp->next) {
		tmp = tmp->next;
	}
	tmp->next = new_l_list();
	tmp = tmp->next;
	tmp->data = data;
}

void insert(int index, int data, l_list* root) {
	l_list* cur = root;

	if (index == 0) {
		cur = new_l_list();
		cur->next = root;
		root = cur;
		return;
	}

	while (index-- > 1){
		if (cur->next) {
			cur = cur->next;
		}
		else {
			printf("insert: Index Overflow Occur\n");
			return;
		}
	}

	l_list* tmp = cur->next;
	cur->next = new_l_list();
	cur = cur->next;
	cur->next = tmp;
}

void print(int index, l_list* root) {
	l_list* cur = root;

	while (index--) {
		if (cur->next) {
			cur = cur->next;
		}
		else {
			printf("insert: Index Overflow Occur\n");
			return;
		}
	}

	printf("%d\n", cur->data);
}

void print_all(l_list* root) {
	l_list* cur = root;
	printf("%d\n", cur->data);

	while (cur->next) {
		cur = cur->next;
		printf("%d\n", cur->data);
	}
}

void reverse_print_all(l_list* root) {
	l_list* cur = root;

	if (cur->next) {
		reverse_print_all(cur->next);
	}
	
	printf("%d\n", cur->data);
}

void free_l_list(l_list* root) {
	l_list* cur = root;
	while (cur) {
		l_list* tmp = cur;
		cur = cur->next;
		free(tmp);
	}
}