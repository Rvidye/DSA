#pragma once
// Headers and Standard Library Declaration
#include<iostream>
#include<string>

using namespace std;

// Class and Member function Declaration 
//Class Node For Stoaring Word,Meaning left anf Right Pointers of BST
class Node
{
    public:
    string word,meaning;
    Node *left,*right;
    bool isThreaded;
    Node(string word,string meaning);
    Node(Node* other);
    void printWordAndMeaning();
};

//Class Dictionary for Stoaring Node class objects and all important function impletation to make a working dictionary
class Dictionary
{
    public:
    Node* root;
    Dictionary();
    Dictionary(Node* root);
    Node* CreateThreaded(Node* root);
    Node* leftMost(Node* root);
    void AddNode(string word,string meaning);
    void InOrder(Node* root);
};

// Node Class Function Defination Start

Node::Node(string word,string meaning)
{
    //cout<<"Inside Node Construct"<<endl;
    this->word =word;
    this->meaning = meaning;
    left = right = NULL;
}

Node::Node(Node*other)
{
    this->word = other->word;
    this->meaning = other->meaning;
    this->left = other->left;
    this->right = other->right;
}

void Node:: printWordAndMeaning()
{
    cout<<"\t"<<this->word<<" : "<<this->meaning<<endl;
}

// END Of Node Class Functions

// START OF Dictionary Class Function Defination
Dictionary::Dictionary()
{ this->root = NULL;}

Dictionary::Dictionary(Node* root)
{ this->root = new Node(root);}

// Function to Add New Node to Binary Tree
void Dictionary::AddNode(string word,string meaning)
{
    Node* move,*newWord;
    newWord = new Node(word,meaning);
    if(this->root == NULL)
    {
        this->root = newWord;
    }else
    {
        move = this->root;
        while (1)
        {
           if(newWord->word < move->word)
           {
               if(move->left == NULL)
               {
                    move->left = newWord;
               }
               else
               {
                 move = move->left;
               }
           }
           else if(newWord->word > move->word)
           {
               if(move->right == NULL)
               {
                   move->right = newWord;
               }
               else
                {
                    move = move->right;
                }
           }else
           {
               break;
           }
        }
    }
}

// Basically Using this function to print Dictonary in Ascending Order
void Dictionary::InOrder(Node* root)
{
    if(root == NULL)
        return;
    Node * move = leftMost(root);

    while(move != NULL)
    {
        move->printWordAndMeaning();

        if(move->isThreaded)
            move = move->right;
        else
            move = leftMost(move->right);
    }
}

Node* Dictionary::CreateThreaded(Node * root)
{
    if(root == NULL)
        return NULL;
    if(root->left == NULL && root->right == NULL)
        return root;

    if(root->left != NULL)
    {
        Node* l = CreateThreaded(root->left);
        l->left = root;
        l->isThreaded = true;
    }

    if(root->right == NULL)
        return root;

    return CreateThreaded(root->right);
}

Node* Dictionary::leftMost(Node* root)
{
    while (root != NULL && root->left != NULL)
        root = root->left;
    
    return root;
}
