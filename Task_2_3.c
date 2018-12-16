#include <stdlib.h>
#include <stdio.h>

//struct of list
typedef struct _List
{
    void* value;
    struct _List *next;
    struct _List *prev;
} List;

//struct of list's head, tail, size
typedef struct Double_Linked_List {
	size_t size;
	List *head;
	List *tail;
} Double_List;

// list_new
Double_List* list_new() {
	Double_List *tmp = (Double_List*) malloc(sizeof(Double_List));
	tmp->size = 0;
	tmp->head = tmp->tail = NULL;

	return tmp;
}

//list_delete
int list_delete(Double_List **l) {
	List *tmp = (*l)->head;
	List *next = NULL;
	while (tmp) {
		next = tmp->next;
		free(tmp);
		tmp = next;
	}
	free(*l);
	(*l) = NULL;
	return 0;
}

//push
void push (Double_List *l, void* a){
	List *tmp = (List*) malloc(sizeof(List));
	if (tmp == NULL) {
    	exit(1);
	}
	tmp->value = a;
	tmp->next = NULL;
	tmp->prev = l->tail;

	if(l->tail != NULL){
		l->tail->next = tmp;
	}
	l->tail = tmp;
	if(l->head == NULL){
		l->head = tmp;
	}
	l->size ++;
	//return 0;
}
//pop
void* pop(Double_List *l) {
    List *next;
    void *tmp;
    if (l->tail == NULL) {
        exit(1);
    }
 
    next = l->tail;
    l->tail = l->tail->prev;
    if (l->tail) {
        l->tail->next = NULL;
    }
    if (next == l->head) {
        l->head = NULL;
    }
    tmp = next ->value;
    free(next);
 
    l->size --;
    return tmp;
}
//unshift
void unshift (Double_List *l, void * a){
	List *tmp = (List*) malloc(sizeof(List));
	if (tmp == NULL) {
    	exit(1);
	}
	tmp->value = a;
	tmp->next = l->head;
	tmp->prev = NULL;

	if (l->head) {
    	l->head->prev = tmp;
	}
	l->head = tmp;
	if (l->tail == NULL) {
    	l->tail = tmp;
	}
	l->size ++;
}
//shift
void *shift (Double_List *l){
	List *prev;
	void *tmp;
	if (l->head == NULL) {
		exit(1);
	}

	prev = l->head;
	l->head = l->head->next;
	if(l->head){
		l->head->prev = NULL;
	}
	if(prev == l->tail){
		l->tail = NULL;
	}
	tmp =prev-> value;
	free(prev);
	l->size --;
	return tmp;
}

//reverse

// void reverse


void print(Double_List *l, void (*fun)(void*)) {
    List *tmp = l->head;
    while (tmp) {
        fun(tmp->value);
        tmp = tmp->next;
    }
    printf("\n");
}

void printInt(void *value) {
    printf("%d ", *((int*) value));
}


int main() {
    Double_List *list = list_new();
    int a, b, c, d, e, f, g, h;
     
    a = 10;
    b = 20;
    c = 30;
    d = 40;
    e = 50;
    f = 60;
    g = 70;
    h = 80;
    unshift(list, &a);
    unshift(list, &b);
    unshift(list, &c);
    push(list, &d);
    push(list, &e);
    push(list, &f);
    print(list, printInt);
    printf("length %d\n", list->size);
    printf("shift %d\n", *((int*)shift(list)));
    printf("shift %d\n", *((int*)shift(list)));
    printf("head %d\n", *((int*)(list->head->value)));
    printf("tail %d\n", *((int*)(list->tail->value)));
    printf("pop %d\n", *((int*)pop(list)));
    printf("pop %d\n", *((int*)pop(list)));
    printf("length %d\n", list->size);
     
    //getch();
    return 0;
}








