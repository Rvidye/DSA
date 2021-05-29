#include"header.h"

int main(void) 
{
	ThreadedTree tree;
	tree.root = tree.AddNode(6);
	tree.root = tree.AddNode(3);
	tree.root = tree.AddNode(8);
	tree.root = tree.AddNode(1);
	tree.root = tree.AddNode(5);
	tree.root = tree.AddNode(7);
	tree.root = tree.AddNode(11);
	tree.root = tree.AddNode(9);
	tree.root = tree.AddNode(13);
	printf("Ioder Traversal\n");
	tree.Inorder(tree.root);
	printf("preorder traversal\n");
	tree.PreOrder(tree.root);
}