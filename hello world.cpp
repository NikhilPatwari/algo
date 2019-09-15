// hello world.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include<stdio.h>
#include <iostream>
#include<stdio.h>
using namespace std;

struct node {
	node* parent;
	node* leftChild;
	node* rightChild;
	bool color;//1 for red 0 for black
	int data;
};
struct tree{
	struct node* nil;
	struct node* root;
};
tree* t = (tree*)malloc(sizeof(node));
node* nil = (node*)malloc(sizeof(node));

void rotateLeft(tree* t, node* x)
{
	node* y = x->rightChild;
	x->rightChild = y->leftChild;
	if (y->leftChild != t->nil)
	{
		y->leftChild->parent = x;
	}
	y->parent = x->parent;
	if (x->parent == t->nil)
		t->root = y;
	else if (x == x->parent->leftChild)
		x->parent->leftChild = y;
	else
		x->parent->rightChild = y;
	y->leftChild = x;
	x->parent = y;
}
void rotateRight(tree* t, node* x)
{
	node* y = x->rightChild;
	x->leftChild = y->rightChild;
	if (y->rightChild != t->nil)
		y->rightChild->parent = x;
	y->parent = x->parent;
	if (x->parent == t->nil)
		t->root = y;
	else if (x == x->parent->leftChild)
		x->parent->leftChild = y;
	else
		x->parent->rightChild = y;
	y->rightChild = x;
	x->parent = y;
}
node* tree_minimum(node* z)
{
	node* x = z;
	node* y = z;
	while (x != t->nil)
	{
		y = x;
		x = x->leftChild;
	}
	return y;
}
void delete_fixup(tree* t, node* x)
{
	node* w;
	while (x != t->root && x->color == 0)
	{
		if (x == x->parent->leftChild)
		{
			w = x->parent->leftChild;
			if (w->color == 1)
			{
				w->color = 0;
				x->parent->color = 1;
				rotateLeft(t, x->parent);
				w = x->parent->rightChild;
			}
			if (w->leftChild->color == 0 && w->rightChild->color == 0)
			{
				w->color = 1;
				x = x->parent;
			}
			else if (w->rightChild->color == 1)
			{
				w->leftChild->color = 0;
				w->color = 1;
				rotateRight(t, w);
				w = x->parent->rightChild;
			}
			w->color = x->parent->color;
			x->parent->color = 0;
			w->rightChild->color = 0;
			rotateLeft(t, x->parent);
			x = t->root;
		}
		else
		{
			w = x->parent->leftChild;
			if (w->color == 1)
			{
				w->color = 0;
				x->parent->color = 1;
				rotateRight(t, x->parent);
				w = x->parent->leftChild;
			}
			if (w->rightChild->color == 0 && w->leftChild->color == 0)
			{
				w->color = 1;
				x = x->parent;
			}
			else if (w->leftChild->color == 1)
			{
				w->rightChild->color = 0;
				w->color = 1;
				rotateLeft(t, w);
				w = x->parent->leftChild;
			}
			w->color = x->parent->color;
			x->parent->color = 0;
			w->leftChild->color = 0;
			rotateRight(t, x->parent);
			x = t->root;

		}

	}
}
void transplant(tree* t, node* u, node* v)
{
	if (u->parent == t->nil)
		t->root = v;
	else if (u = u->parent->leftChild)
		u->parent->leftChild = v;
	else
		u->parent->rightChild = v;
	v->parent = u->parent;
}
void nodeDelete(tree* t, node* z)
{
	node* y = z;
	node* x;
	bool orignal_color = y->color;
	if (z->leftChild == t->nil)
	{
		x = z->rightChild;
		transplant(t, z, z->rightChild);
	}
	else if (z->rightChild == t->nil)
	{
		x = z->leftChild;
		transplant(t, z, z->leftChild);
	}
	else
	{
		y = tree_minimum(z->rightChild);
		orignal_color = y->color;
		x = y->rightChild;
		if (y->parent == z)
			x->parent = y;
		else
		{
			transplant(t, y, y->rightChild);
			y->rightChild = z->rightChild;
			y->rightChild->parent = y;
		}
		transplant(t, z, y);
		y->leftChild = z->leftChild;
		y->leftChild->parent = y;
		y->color = z->color;
	}
	if (orignal_color == 0)
		delete_fixup(t, x);
}
void insertFixup(tree* t, node* z)
{
	node* y;
	while (z->parent->color == 1)
	{
		if (z->parent == z->parent->parent->leftChild)
		{
			y = z->parent->parent->rightChild;
			if (y->color == 1)
			{
				z->parent->color = 0;
				y->color = 0;
				z->parent->parent->color = 1;
				z = z->parent->parent;
			}
			else if (z == z->parent->rightChild)
			{
				z = z->parent;
				rotateLeft(t, z);
			}
			z->parent->color = 0;
			z->parent->parent->color = 1;
			rotateRight(t, z->parent->parent);
		}else
		{
			y = z->parent->parent->leftChild;
			if (y->color == 1)
			{
				z->parent->color = 0;
				y->color = 0;
				z->parent->parent->color = 1;
				z = z->parent->parent;
			}
			else if (z == z->parent->leftChild)
			{
				z = z->parent;
				rotateRight(t, z);
			}
			z->parent->color = 0;
			z->parent->parent->color = 1;
			rotateLeft(t, z->parent->parent);
		}
	}
	t->root->color = 0;	
	//return z;
}
void insert(struct node* z,tree* t)
{
	z->color = 1;
	node* y = t->nil;
	node* x = t->root;
	while (x!=t->nil)
	{
		y = x;
		if (z->data < x->data)
		{
			x = x->leftChild;					
		}else
		{
			x = x->rightChild;
		}
		z->parent = y;
	}
	if (y==t->nil)
	{
		t->root = z;
	}
	else if(z->data<y->data)
	{
		y->leftChild = z;
	}
	else
		y->rightChild = z;
	z->leftChild = t->nil;
	z->rightChild = t->nil;
	z->color = 1;
	insertFixup(t, z);
}
node* remove(int data, node* root)
{
	return root;
}
int search(int data, node* root)
{
	node* temp = root;
	if (temp->data == data)
	{
		return data;
	}else if (temp != NULL && temp->data < data)
	{
		search(data, temp->rightChild);
	}
	else if (temp != NULL && temp->data > data)
	{
		search(data, temp->leftChild);
	}
	else if (temp == NULL)
	{
		cout << "data-"<<data<< "not found" << endl;
		return NULL;
	}


}
int main()
{
	nil->color = 0;//0 for black
	t->nil = nil;
	int x, y,z;
	t->root = NULL;
	while (true)
	{
		cout << "please enter 1-for insert , 2-for delete , 3-for search , 4 to exit" << endl;
		cin >> x;
		if (x == 1)
		{
			cout << "enter value to insert" << endl;
			cin >> y;
			node* temp = new node();
			temp->data = y;
			temp->parent = t->nil;
			temp->color = 1;//1 for red
			temp->leftChild = t->nil;
			temp->rightChild = t->nil;
			if (!t->root)
			{
				t->root = temp;
				t->root->color = 0;
			}
			else
			insert(temp,t);
			cout << "data --  " << y << "   inserted" << endl;
		}
		else if (x == 2)
		{
			cout << "enter data to delete" << endl;
			cin >> y;
			t->root = remove(y, t->root);
		}
		else if (x == 3)
		{
			cout << "enter data to search" << endl;
			cin >> y;
			z= search(y, t->root);
			if (z == y)
			{
				cout << "success data found" << endl;
			}
			else
				cout << "data not found" << endl;
		}
		else if (x == 4)
			break;
	}
	return 0;
}