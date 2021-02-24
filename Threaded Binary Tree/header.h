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
		this->leftTh = this->rightTh = false;
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
	ThreadedTree(Node* root);
	Node* AddNode(int ele);
	void Inorder(Node* root);
};

ThreadedTree::ThreadedTree()
{
	root->left = root->right = root;
	root->leftTh = true;
	root->data = 9999;
}

Node* ThreadedTree::AddNode(int ele)
{
	Node* newnode, * move;
	char ch;
	newnode = new Node(ele);
	if (root == NULL)
	{
		root = newnode;
		printf("\n Root Created !!! ");
	}
	else
	{
		move = root;
		while (1)
		{
			if(move->data < ele)
			{
				if(move->rightTh)
					{break;}
				move = move->right;
			}else if(move->data > ele)
			{
				if(move->leftTh)
					{break;}
				move = move->left;
			}
		}
	}
	return root;
}


void ThreadedTree::Inorder(Node* root)
{
	if (root != NULL)
	{
		Inorder(root->left);
		printf("  %d", root->data);
		Inorder(root->right);
	}

}
