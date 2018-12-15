// TASK 1
// Нулевой элемент пуст
#include <stdio.h>
#include <stdlib.h>
// struct
typedef struct _List
{
    int value;
    struct _List *next;
} List;

//list_new()
List * list_new()
{
	List *l = (List *)malloc(sizeof(List)); //allocates memory
	(*l).next = NULL; //points to null
	return l; //returns pointer
}

//list_delete(l)
int list_delete(List *l)
{
	List *p = NULL;
	while ((*l).next != NULL)
	{
		p = l; //now p points to tail
		l = (*l).next; //move a list
		free(p); //delete tail
	}
	free(l); //delete alone element
	return 0;
}

//insert (l,a)
List * insert (List *l, int a)
{
	List *tmp = (List *)malloc(sizeof(List));
	(*tmp).next = (*l).next;
	(*l).next = tmp;
	(*tmp).value = a;
	return l; //returns pointer to inserted element
}

//remove (l,a) назовем ее rremove(l, a)
int rremove (List *l, int a)
{
	List *tmp = NULL;
	while ((*l).next != NULL)
	{
		if ((*((*l).next)).value == a)
		{
			tmp = (*l).next;
			(*l).next = (*((*l).next)).next;
			free (tmp);
		}
		l = (*l).next;
	}
	return 0;
}
//print(l)
int print(List *l)
{
	if ((*l).next == NULL)
	{
		return 0;
	}
	else
	{
		List *p = NULL;
		l = (*l).next;
		while ((*l).next != NULL)
		{
			p = l; //now p points to tail
			l = (*l).next; //move a list
			printf("%d ", (*p).value); //print tail
		}
		printf("%d\n", (*l).value); //print alone element
	}
	return 0;
}

int main ()
{
	List *test;
	test = list_new();
	insert(test, 1);
	insert(test, 2);
	insert(test, 3);
	print(test);
	rremove(test, 2);
	print(test);
	list_delete(test);
	return 0;
}
