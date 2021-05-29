#pragma once
#include<iostream>
#include<stdio.h>
#include<conio.h>
using namespace std;

class Node
{
	public:
	int data;
	Node* left, * right;
	bool leftTh, rightTh;
	friend class ThreadedTree;
	Node(int ele)
	{
		this->data = ele;
		this->left = this->right = NULL;
		this->leftTh = this->rightTh = true;
	}
	~Node()
	{
	}
};

class ThreadedTree
{
public:
	Node* root;
	ThreadedTree();
	Node* AddNode(int ele);
	Node* inorderSuccessor(Node* ptr);
	void Inorder(Node* root);
	void PreOrder(Node* root);
};

ThreadedTree::ThreadedTree()
{
}

Node* ThreadedTree::AddNode(int ele)
{
	Node* newnode, *move,*par;
	newnode = new Node(ele);
	move = root;
	par = NULL;
	while(move!=NULL)
	{
		if(ele == move->data)
		{
			printf("Duplicate");
			return root;
		}
		par = move;
		if(ele < move->data)
		{
			if (move -> leftTh == false)
    	            move = move-> left;
       	 	else
                break;
		}
		else
		{
			if (move->rightTh == false)
                move = move-> right;
            else
                break;
		}
	}

	if(move == NULL)
	{
		root = newnode;
		newnode->left = newnode->right = NULL;
	}
	else if(ele < move->data)
	{
		newnode->left = move->left;
		newnode->right = move;
		move->leftTh = false;
		move->left = newnode;
	}else
	{
		newnode->left = move;
		newnode->right = move->right;
		move->rightTh = false;
		move->right = newnode;
	}
	return root;
}

Node* ThreadedTree::inorderSuccessor(Node* ptr)
{
	if(ptr->rightTh)
		return ptr->right;

	ptr = ptr->right;
	while(!ptr->leftTh)
		ptr = ptr->left;

	return ptr;
}

void ThreadedTree::Inorder(Node* root)
{
	Node *move = root;

	while(!move->leftTh)
		move = move->left;
	
	while (move != NULL)
	{
		printf(" %d\n",move->data);
		move = inorderSuccessor(move);
	}
}

void ThreadedTree::PreOrder(Node* root)
{
	Node *move = root;
	printf("%d\t",move->data);
	if(!move->leftTh)
		PreOrder(move->left);
	if(!move->rightTh)
		PreOrder(move->right);
}

