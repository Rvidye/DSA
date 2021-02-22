#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<queue>
#include<stack>
using namespace std;

class Node
{
private:
	int data;
	Node* left, * right;
public:
	Node(int ele)
	{
		this->data = ele;
		this->left = this->right = NULL;
	}

	Node(Node* other)
	{
		this->data = other->data;
		this->left = other->left;
		this->right = other->right;
	}
	friend class BST;
};

class BST
{
private:
	Node* root;
public:
	BST();
	BST(Node* root);
	Node* GetRoot();
	Node* AddNode(int ele);
	int GetNonLeafCount(Node* root);
	unsigned int GetNonLeafCountIterative();
	unsigned int GetLeafCount(Node* node);
	unsigned int GetLeafCountIterative();
	void SwapTreeNodes(Node* node);
	void SwapTreeNodesIterative();
	int TreeHeight(Node* node);
	int TreeHeightIterative();
	Node* CopyTree(Node* root);
	void DeleteTree(Node* node);
	void DeleteTreeIterative();
	void Inorder(Node* root);
	void Preorder(Node* root);
	void Postorder(Node* root);
	void InorderIterative();
	void PreorderIterative();
	void PostorderIterative();
	BST& operator = (const BST& other);
};

BST::BST()
{
	root = NULL;
}

Node* BST::GetRoot()
{return this->root;}

Node* BST::AddNode(int ele)
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
			printf("\n L or R %d", move->data);
			ch = _getche();
			if (ch == 'l' || ch == 'L')
			{
				if (move->left == NULL)
				{
					move->left = newnode;
					printf("\n\n\t Added At Left OF %d", move->data);
					break;
				}
				else
					move = move->left;
			}
			else if (ch == 'R' || ch == 'r')
			{
				if (move->right == NULL)
				{
					move->right = newnode;
					printf("\n\n\t Added At right OF %d", move->data);
					break;
				}
				else
					move = move->right;
			}
			else
			{
				printf("\n\n\t Invalid Input!!! ");
				break;
			}
		}
	}
	return root;
}

int BST::GetNonLeafCount(Node* root)
{
		if (root == NULL || (root->left == NULL &&
			root->right == NULL))
			return 0;

		return 1 + GetNonLeafCount(root->left) + GetNonLeafCount(root->right);
}

unsigned int BST::GetNonLeafCountIterative()
{
	if (root == NULL || (root->left == NULL &&
		root->right == NULL))
		return 0;

	queue<Node*> q;
	int count = 0; // Initialize count of leaves
	q.push(root);
	while (!q.empty())
	{
		Node* temp = q.front();
		q.pop();

		if (temp->left != NULL)
			q.push(temp->left);
		if (temp->right != NULL)
			q.push(temp->right);
		if (temp->left != NULL || temp->right != NULL)
			count++;
	}
	return count;
}

unsigned int BST::GetLeafCount(Node* node)
{
	if (node == NULL)
		return 0;
	if (node->left == NULL && node->right == NULL)
		return 1;
	else
		return GetLeafCount(node->left) + GetLeafCount(node->right);
}

unsigned int BST::GetLeafCountIterative()
{
	if (!node)
		return 0;

	queue<Node*> q;
	int count = 0; // Initialize count of leaves
	q.push(node);
	while (!q.empty())
	{
		Node* temp = q.front();
		q.pop();

		if (temp->left != NULL)
			q.push(temp->left);
		if (temp->right != NULL)
			q.push(temp->right);
		if (temp->left == NULL && temp->right == NULL)
			count++;
	}
	return count;
}

void BST::SwapTreeNodes(Node* node)
{
	if (node == NULL)
		return;
	else
	{
		Node* temp;

		SwapTreeNodes(node->left);
		SwapTreeNodes(node->right);

		temp = node->left;
		node->left = node->right;
		node->right = temp;
	}
}

void BST::SwapTreeNodesIterative()
{
	if (root == NULL)
		return;

	queue<Node*> q;
	q.push(root);

	while (!q.empty())
	{
		Node* curr = q.front();
		q.pop();

		swap(curr->left, curr->right);

		if (curr->left)
			q.push(curr->left);
		if (curr->right)
			q.push(curr->right);
	}
}

int BST::TreeHeight(Node* node)
{
	if (node == NULL)
		return 0;
	else
	{
		int lDepth = TreeHeight(node->left);
		int rDepth = TreeHeight(node->right);

		if (lDepth > rDepth)
			return(lDepth + 1);
		else 
			return(rDepth + 1);
	}
}

int BST::TreeHeightIterative()
{
	if (root == NULL)
		return 0;

	queue<Node*> q;

	q.push(root);
	int height = 0;

	while (1)
	{
		int nodeCount = q.size();
		if (nodeCount == 0)
			return height;

		height++;
		while (nodeCount > 0)
		{
			Node* node = q.front();
			q.pop();
			if (node->left != NULL)
				q.push(node->left);
			if (node->right != NULL)
				q.push(node->right);
			nodeCount--;
		}
	}
}

Node* BST::CopyTree(Node* root)
{
	Node* copyRoot = NULL;
	if (root != NULL)
	{
		copyRoot = new Node(root->data);
		copyRoot->left = CopyTree(root->left);
		copyRoot->right = CopyTree(root->right);
	}
	return copyRoot;
}

void BST::DeleteTree(Node* node)
{

	if (node == NULL)
		return;

	DeleteTree(node->left);
	DeleteTree(node->right);

	printf("\n Deleting node: %d", node->data);
	delete node;
}

void BST::DeleteTreeIterative()
{
	// empty tree
	if (root == NULL) {
		return;
	}

	// create an empty queue and enqueue the root node
	queue<Node*> queue;
	queue.push(root);

	Node* front = NULL;

	while (!queue.empty())
	{
		front = queue.front();
		queue.pop();

		if (front->left) {
			queue.push(front->left);
		}

		if (front->right) {
			queue.push(front->right);
		}
		printf("\n Deleting node: %d", front->data);
		delete front;
	}
	root = NULL;
}

void BST::Inorder(Node* root)
{
	if (root != NULL)
	{
		Inorder(root->left);
		printf("  %d", root->data);
		Inorder(root->right);
	}

}

void BST::Preorder(Node* root)
{

	if (root != NULL)
	{
		printf("  %d", root->data);
		Preorder(root->left);
		Preorder(root->right);
	}

}

void BST::Postorder(Node* root)
{
	if (root != NULL)
	{
		Postorder(root->left);
		Postorder(root->right);
		printf("  %d", root->data);
	}
}

void BST::InorderIterative()
{
	stack<Node*> s;
	Node* curr = root;

	while (curr != NULL || s.empty() == false)
	{
		/* Reach the left most Node of the
		   curr Node */
		while (curr != NULL)
		{
			/* place pointer to a tree node on
			   the stack before traversing
			  the node's left subtree */
			s.push(curr);
			curr = curr->left;
		}

		/* Current must be NULL at this point */
		curr = s.top();
		s.pop();
		printf("  %d", curr->data);
		curr = curr->right;
	}
}

void BST::PreorderIterative()
{
	if (root == NULL)
		return;

	stack<Node*> nodeStack;
	nodeStack.push(root);

	while (nodeStack.empty() == false) {
		Node* node = nodeStack.top();
		printf("%d ", node->data);
		nodeStack.pop();

		if (node->right)
			nodeStack.push(node->right);
		if (node->left)
			nodeStack.push(node->left);
	}
}

void BST::PostorderIterative()
{
	if (root == NULL)
		return;

	stack<Node*> s1, s2;

	s1.push(root);
	Node* node;

	while (!s1.empty()) {
		node = s1.top();
		s1.pop();
		s2.push(node);

		if (node->left)
			s1.push(node->left);
		if (node->right)
			s1.push(node->right);
	}

	while (!s2.empty()) {
		node = s2.top();
		s2.pop();
		printf(" %d", node->data);
	}
}

BST& BST::operator=(const BST& other)
{
	Node* newleft = NULL;
	Node* newright = NULL;

	try {
		newleft = new Node(other.root->left);
		newright = new Node(other.root->right);
	}
	catch (...) {
		delete newleft;
		delete newright;
		throw;
	}

	root->data = other.root->data;
	swap(root->left, newleft);
	swap(root->right, newright);
	delete newleft;
	delete newright;

	return *this;
}
