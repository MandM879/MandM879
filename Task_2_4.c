// Null element of a stack is empty
#include <stdio.h>
#include <stdlib.h>
// struct
typedef struct _Stack //we create single-linked list as a stack
{
	char value;
	struct _Stack *next;
} Stack;

//new()
Stack * stack_new ()
{
	Stack *s = (Stack *)malloc(sizeof(Stack)); //allocates memory
	//ERROR CHECK
	if (s == NULL)
	{
		return NULL; //can't allocate
	}
	(*s).next = NULL; //points to null
	return s; //returns pointer
}

//stack_delete(s)
int stack_delete (Stack *s)
{
	//ERROR CHECK
	if (s == NULL)
	{
		return 1; //no stack
	}
	//ERROR CHECK
	Stack *p = NULL;
	while ((*s).next != NULL)
	{
		p = s; //now p points to tail
		s = (*s).next; //move a Stack
		free(p); //delete tail
	}
	free(s); //delete alone element
	return 0;
}

//push (s,a)
Stack * push (Stack *s, char a) //adds an element to the stack
{
	//ERROR CHECK
	if (s == NULL)
	{
		return NULL; //no stack to insert to
 	}
	//ERROR CHECK
	Stack *tmp = (Stack *)malloc(sizeof(Stack));
	(*tmp).next = (*s).next;
	(*s).next = tmp;
	(*tmp).value = a;
	return s;
}

char pop (Stack *s) //pops an element from the stack
{
	//ERROR CHECK
	if (s == NULL)
	{
		return 0; //no stack
	}
	//ERROR CHECK
	if ((*s).next == NULL)
	{
		return 0; //no elements in the stack
	}
	else
	{
		Stack *tmp = (*s).next;
		char tma = (*tmp).value;
		(*s).next = (*tmp).next;
		free(tmp);
		return tma;
	}
}

int main ()
{
	Stack * stack = stack_new(); //creates a stack
	char bracket;
	int flag = 0;
	while (1)
	{
		bracket = getchar(); //gets a bracket
		switch (bracket)
		{
			case '(':
			{
				push (stack, bracket);
				break;
			}
			case '{':
			{
				push (stack, bracket);
				break;
			}
			case ')':
			{
				if (pop (stack) != '(')
				{
					flag = 1;
				}
				break;
			}
			case '}':
			{
				if (pop (stack) != '{')
				{
					flag = 1;
				}
				break;
			}
			default:
			{
				if (flag == 1)
				{
					printf("WRONG");
				}
				else
				{
					printf("RIGHT");
				}
				stack_delete(stack);
				return 0;
			}
		}
	}		
}
