#include <stdio.h>
#include <stdlib.h>

typedef struct linked_list_ {
	int data;
	struct linked_list_* next;
}linked_list;

linked_list* new_linked_list();

int main() {

}

linked_list* new_linked_list() {
	linked_list* tmp = (linked_list*)malloc(sizeof(linked_list));
	tmp->data = 0;
	tmp->next = NULL;
	return tmp;
}