//pair
typedef struct _Pair
{
	int key;
	float data;
} pair;

//node
typedef struct _Node
{
	pair keydata;
	struct _Node *left;
	struct _Node *right;
	struct _Node *parent;
} Node;

typedef struct _Tree
{
	Node *root;
} Tree;

//create
Tree * new_tree() //returns a link to the root
{
	Tree *t = (Tree *)malloc(sizeof(Tree));
	//ERROR CHECK
	if (t == NULL)
	{
		return NULL; //can't allocate
	}
	//ERROR CHECK
	(*t).root = NULL;
	return t;
}

//add
Tree * add_pair(int k, float v, Tree* t)
{
	//ERROR CHECK
	if (t == NULL)
	{
		return NULL; //no tree to insert in
	}
	//ERROR CHECK
	Node **field = *((*t).root); //double pointer
	Node *tmp = (*t).root;
	while ((*tmp) != NULL) //while data is in the node
	{
		if (k < (*tmp).keydata.key)
		{
			field = &((*tmp).left);
			tmp = (*tmp).left; //go to the left child
		}
		else
		{
			field = &((*tmp).right);
			tmp = (*tmp).right; //do to the right child
		}
	}
	*field = (Node *)malloc(sizeof(Node)); //allocate memory
	//ERROR CHECK
	if (field == NULL)
	{
		return NULL; //can't allocate
	}
	//ERROR CHECK
	**field.keydata.key = k; //insert key
	**field.keydata.value = v; //insert data
	return t;
}

//delete
int delete_tree(Tree* t)
{
	//ERROR CHECK
	if (t == NULL)
	{
		return 1; //no tree
	}
	//ERROR CHECK
	Node *tmp = (*t).root
	Node *p = NULL
	while (*tmp != NULL) //while exists a tree
	{
		if ((*tmp).left != NULL) //if exists left child
		{
			tmp = (*tmp).left; //go to the left
		}
		else
		{
			if ((*tmp).right != NULL) //if exists right child
			{
				tmp = (*tmp).right; //go to the right
			}
			else
			{
				p = tmp;
				tmp = (*tmp).parent; //go back
				free(p); //delete node
			}
		}
	}
	free(t); //delete tree
	return 0;
}

// struct
typedef struct _Stack
{
	int key;
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

//insert (s,k)
Stack * push (Stack *s, int k)
{
	Stack *tmp = (Stack *)malloc(sizeof(Stack));
	//ERROR CHECK
	if (s == NULL)
	{
		return NULL; //no stack to push to
 	}
	//ERROR CHECK
	(*tmp).next = (*s).next;
	(*s).next = tmp;
	(*tmp).value = k;
	return s;
}

//search by key
int search (Stack *s, int k)
{
	//ERROR CHECK
	if (s == NULL)
	{
		return 2; //no stack to search in
 	}
	//ERROR CHECK
	while ((*s).next != NULL)
	{
		if (k = (*s).key)
		{
			return 1;
		}
		else
		{
			(*s) = (*s).next;
		}
	}
	if (k = (*s).key)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

//deep
int dfs(Node* t)
{
	//ERROR CHECK
	if (t == NULL)
	{
		return 1; //no tree to go
 	}
	//ERROR CHECK
	Node *tmp;
	tmp = (*t).root;
	Stack * stack = stack_new(); //create a stack
	if ((*tmp) == NULL)
	{
		return 0;
	}
	push (stack, (*tmp).keydata.key); //push a key from the root to the stack
	while (1)
	{
		if (((*tmp).left != NULL) and 
			(search(stack, (*((*tmp).left)).keydata.key) == 0)) //left child exists and we hadn't been there before
		{
			tmp = (*tmp).left; //go to the left
			push (stack, (*tmp).keydata.key); //push left's key to the stack
		}
		else
		{
			(((*tmp).right != NULL) and 
			 (search(stack, (*((*tmp).right)).keydata.key) == 0)) //right child exists and we hadn't been there before
			{
				tmp = (*tmp).right; //go to the right
				push (stack, (*tmp).keydata.key); //push right's key to the stack
			}
			else
			{
				if ((*tmp).parent != NULL)
				{
					tmp = (*tmp).parent; //go back
				}
			}
		}
		if (tmp == (*t).root) //we are in the root 
		{
			stack_delete (stack); //delete stack
			return 0; //end
		}
	}
}
