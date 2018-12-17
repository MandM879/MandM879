#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//recording
typedef struct _Rec
{
	char *name;
	char *number;
} Rec;

// book
typedef struct _List
{
	Rec value;
	struct _List *next;
} List;

//gets command
int get_command()
{
	char com[7]; //FIND - 4 symbols, INSERT - 6 symbols
	scanf("%s ", com);
	if (strcmp (com, "INSERT") == 0) // if insert
	{
		return 1;
	}
	else
	{
		if (strcmp (com, "FIND") == 0) //if find
		{
			return 2;
		}
		else
		{
			return 0;
		}
	}
}

//gets name
char * get_name()
{
	char *name;
	name = (char *)malloc(2);
	int memname = 2;
	int i = 0;
	char b = 0;
	while (1)
	{
		b = getchar();
		if (!(((b >= 'A') && (b <= 'Z')) || ((b >= 'a') && (b <= 'z')))) //only Latin letters
		{
			break;
		}
		
		name[i] = b;
		name = (char *)realloc(name, (memname + 1));
		memname++;
		i++;
	}
	name[i] = '\0';
	return name;
}

//gets number
char * get_number()
{
	char * number;
	number = (char *)malloc(2);
	int memnum = 2;
	int i = 0;
	char b = 0;
	while (1)
	{
		b = getchar();
		if ((b < '0') || (b > '9')) //only numbers
		{
			break;
		}
		number[i] = b;
		number = (char *)realloc(number, (memnum + 1));
		memnum++;
		i++;
	}
	number[i] = '\0';
	return number;
}

//list_new()
List * list_new()
{
	List *l = (List *)malloc(sizeof(List)); //allocates memory
	//ERROR CHECK
	if (l == NULL)
	{
		return NULL; //can't allocate
	}
	//ERROR CHECK
	(*l).next = NULL; //points to null
	return l; //returns pointer
}

//list_delete(l)
int list_delete(List *l)
{
	//ERROR CHECK
	if (l == NULL)
	{
		return 1; //nothing to delete
	}
	//ERROR CHECK
	List *p = NULL;
	while ((*l).next != NULL)
	{
		p = l; //now p points to tail
		l = (*l).next; //move a list
		free((*p).value.name); //delete name
		free((*p).value.number); //delete number
		free(p); //delete tail
	}
	free((*l).value.name);
	free((*l).value.number);
	free(l); //delete alone element
	return 0;
}

//insert (l,name, num)
List * insert (List *l, char *name, char *number)
{
	//ERROR CHECK
	if (l == NULL)
	{
		return NULL; //no book to insert to
	}
	//ERROR CHECK
	List *tmp = (List *)malloc(sizeof(List));
	(*tmp).next = (*l).next;
	(*l).next = tmp;
	(*tmp).value.name = name; //insert name
	(*tmp).value.number = number; //insert number
	return l;
}

//search by name
List * search (List *l, char *name)
{
	//ERROR CHECK
	if (l == NULL)
	{
		return NULL; //no book to search in
	}
	//ERROR CHECK
	l = (*l).next;
	while (l != NULL)
	{
		if (strcmp (name, (*l).value.name) == 0)
		{
			return l; //return address
		}
		else
		{
			l = (*l).next;
		}
	}
	return NULL;
}

int main ()
{
	int command = 0;
	char * name = NULL;
	char * number = NULL;
	List * searchres = NULL;
	List * book = list_new();
	while ((command = get_command()) != 0) //insert or find
	{
		if (command == 1) //insert
		{
			name = get_name();
			number = get_number();
			searchres = search (book, name);
			if (searchres == NULL) //if name doesn't exist
			{
				insert (book, name, number);
				printf("OK\n");
			}
			else //if name exists
			{
				printf("Changed. Old value = %s\n", (*searchres).value.number);
				free((*searchres).value.number);
				free(name);
				(*searchres).value.number = number;
			}
		}
		else
		{
			if (command == 2) //find
			{
				name = get_name();
				searchres = search (book, name);
				if (searchres == NULL) //if name doesn't exist
				{
					printf("NO\n");
				}
				else //if name exists
				{
					printf ("%s\n", (*searchres).value.number);
				}
				free(name);
			}
		}
	}
	list_delete(book);
	return 0;
}
