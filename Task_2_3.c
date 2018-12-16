#include <stdlib.h>
#include <stdio.h>

//struct of list
typedef struct _List
{
    int * value;
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
void push (Double_List *l, void* a) {
	List *tmp = (List*) malloc(sizeof(List));
	if (tmp == NULL) {
    	exit(1);
	}
	tmp->value = a;
	tmp->next = NULL;
	tmp->prev = l->tail;

	if(l->tail != NULL) {
		l->tail->next = tmp;
	}
	l->tail = tmp;
	if(l->head == NULL) {
		l->head = tmp;
	}
	l->size ++;
	//return 0;
}

//pop without argument
int* pop_no_arg(Double_List *l) {
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
	tmp = next->value;
	free(next);

	l->size--;
	return tmp;
}

//true pop
void pop(Double_List *l, int *a) {
	*a = *(l->tail->value);
	pop_no_arg(l);
}

//unshift
void unshift (Double_List *l, void * a) {
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
//shift without taking arg
void* shift_no_arg (Double_List *l) {
	List *prev;
	void *tmp;
	//*a = *(l->head->value);
	if (l->head == NULL) {
		exit(1);
	}

	prev = l->head;
	l->head = l->head->next;
	if(l->head) {
		l->head->prev = NULL;
	}
	if(prev == l->tail) {
		l->tail = NULL;
	}
	tmp = prev->value;
	free(prev);
	l->size --;
	
	return tmp;
}

//true shift
void shift(Double_List *l, int* a) {
	*a = *(l->head->value);
	shift_no_arg(l);
}

//reverse
void reverse(Double_List *l) { 
	List *tmp1 = l->head->next;
	List *tmp2 = l->head->value;
	l->head->next = NULL;
	l->head->prev = tmp1;
	tmp1 = l->head->prev;
	while (tmp1->next) {
		tmp2 = tmp1->next;
		tmp1->next = tmp1->prev;
		tmp1->prev = tmp2;
		tmp1 = tmp1->prev;
	}
	tmp1 = l->tail->prev;
	l->tail->prev = NULL;
	l->tail->next = tmp1;
	tmp1 = l->head;
	l->head = l->tail;
	l->tail = tmp1;
}

//print
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
    int a, b, c, d, e, f, g, h,j;
    int *i;
    a = 1;
    b = 2;
    c = 3;
    d = 4;
    e = 5;
    f = 6;
    g = 7;
    h = 8;
    j = 0;
    i = &j;
    unshift(list, &a);
    unshift(list, &b);
    unshift(list, &c);
    push(list, &d);
    push(list, &e);
    push(list, &f);
    print(list, printInt);

    pop(list, i);
	printf("%d\n", *i);
	print(list, printInt);
	shift(list, i);
	printf("%d\n", *i);
	print(list, printInt);
	reverse(list);
	print(list, printInt);


    return 0;
}
