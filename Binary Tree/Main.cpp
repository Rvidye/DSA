#include"header.h"

int main(void) 
{
	BST* Tree = new BST(), *copiedTree = new BST();
	Node* root = NULL,*copyRoot = NULL;
	int ch, ele;
	do
	{
		printf("\n\n\t\t1. Add\n\t\t2. Dipslay\n\t\t3. Display Iterative\n\t\t4. Swap Each Tree Node\n\t\t5. Swap Each Tree Node Iterative\n\t\t6. Height Of Tree\n\t\t7. Print Number Of Leaf and Non Leaf Nodes Recursive and Iterative\n\t\t8. Delete All Nodes\n\t\t9. Delete All Nodes Iterative\n\t\t10.Copy Tree Recursive Function\n\t\t11.Copy Tree using = operator\n\n\t0. Exit\n\n\t Enter Your Choice \n\n\t ");
		scanf("%d", &ch);
		switch (ch)
		{
		case 1:
			printf("\n\t Enter Element");
			scanf("%d", &ele);
			Tree->AddNode(ele);
			break;
		case 2:
			printf("\n\t ******* Inorder *******\n");
			Tree->Inorder(Tree->GetRoot());
			printf("\n\t ******* Preorder ***********\n");
			Tree->Preorder(Tree->GetRoot());
			printf("\n\t ******* Postorder ***********\n");
			Tree->Postorder(Tree->GetRoot());
			break;
		case 3:
			printf("\n\t ******* Inorder Iterative*******\n");
			Tree->InorderIterative();
			printf("\n\t ******* Preorder Iterative***********\n");
			Tree->PreorderIterative();
			printf("\n\t ******* Postorder Iterative***********\n");
			Tree->PostorderIterative();
			break;
		case 4:
			printf("\n\t Swapped Tree Nodes: \n");
			Tree->SwapTreeNodes(Tree->GetRoot());
			Tree->Inorder(Tree->GetRoot());
			break;
		case 5:
			printf("\n\t Swapped Tree Nodes Iterative: \n");
			Tree->SwapTreeNodesIterative();
			Tree->Inorder(Tree->GetRoot());
			break;
		case 6:
			printf("\n\t Height Of Tree : %d ", Tree->TreeHeight(Tree->GetRoot()));
			printf("\n\t Height Of Tree Non Recursive : %d ", Tree->TreeHeightIterative());
			break;
		case 7:
			printf("\n\n\t Recursive");
			printf("\n\t Number Of Leaf Nodes Of Tree : %d ", Tree->GetLeafCount(Tree->GetRoot()));
			printf("\n\t Number Of Non-Leaf Nodes Of Tree : %d ", Tree->GetNonLeafCount(Tree->GetRoot()));
			printf("\n\n\t Iterative:");
			printf("\n\t Number Of Leaf Nodes Of Tree : %d ", Tree->GetLeafCountIterative());
			printf("\n\t Number Of Non-Leaf Nodes Of Tree : %d ", Tree->GetNonLeafCountIterative());
			break;
		case 8:
			Tree->DeleteTree(Tree->GetRoot());
			Tree->SetRoot(NULL);
			break;
		case 9:
			Tree->DeleteTreeIterative();
			Tree->SetRoot(NULL);
			break;
		case 10:
			printf("\n\n\t Copy Tree Using Recursion");
			copyRoot = Tree->CopyTree(Tree->GetRoot());
			copiedTree->SetRoot(copyRoot) ;
			copiedTree->Inorder(copiedTree->GetRoot());
			copiedTree = NULL;
			break;
		case 11:
			printf("\n\n\t Copy Tree Using = Operator");
			copiedTree = Tree;
			copiedTree->Inorder(copiedTree->GetRoot());
			copiedTree = NULL;
			break;
		}
	} while (ch != 0);
}