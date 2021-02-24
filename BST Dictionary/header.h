#pragma once
// Headers and Standard Library Declaration
#include<iostream>
#include<string>

using namespace std;

// Class and Member function Declaration 
//Class Node For Stoaring Word,Meaning left anf Right Pointers of BST
class Node
{
    private:
    string word,meaning;
    Node *left,*right;
    public:
    friend class Dictionary;
    Node(string word,string meaning);
    Node(Node* other);
    void printWordAndMeaning();
};

//Class Dictionary for Stoaring Node class objects and all important function impletation to make a working dictionary
class Dictionary
{
    private:
    Node* root;
    int counter;
    public:
    Dictionary();
    Dictionary(Node* root);
    Node* GetRoot();
    int GetCounter();
    void SetRoot(Node* root);
    void SetCounter(int count);
    void AddNode(string word,string meaning);
    void InOrder(Node* root);
    void Dictionary::PreOrder(Node* root);
    void ReverseInOrder(Node* root);
    Node* SearchWord(Node* root,string word);
    Node* MinimumValueNode(Node* root);
    Node* DeleteNode(Node* root,string word);
    void UpdateNode(Node* root,string searchWord,string newSword,string meaning);
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
{ this->root = NULL;
    this->counter = 0;
}

Dictionary::Dictionary(Node* root)
{ this->root = new Node(root);
    this->counter = 0;
}

Node* Dictionary::GetRoot()
{return this->root;}

int Dictionary::GetCounter()
{return this->counter;}

void Dictionary::SetRoot(Node* root)
{this->root = root;}

void Dictionary::SetCounter(int count)
{this->counter = count;}

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
    if(root != NULL)
    {
        InOrder(root->left);
        root->printWordAndMeaning();
        InOrder(root->right);
    }
}

// 
void Dictionary::PreOrder(Node* root)
{
    if(root != NULL)
    {
        cout<<root->word<<endl;
        PreOrder(root->left);
        PreOrder(root->right);
    }
}

void Dictionary::ReverseInOrder(Node* root)
{
     if(root != NULL)
    {
        ReverseInOrder(root->right);
        root->printWordAndMeaning();
        ReverseInOrder(root->left);
    }
}

// Searching Word In Dictionary Simple Taversal Algorithm
Node* Dictionary::SearchWord(Node* root,string word)
{
    this->counter++;

    if(root == NULL || root->word == word)
        return root;

    if(root->word < word)
        return SearchWord(root->right,word);

    return SearchWord(root->left,word);
}

// Used inside DeletNode function to find smalled valued node from right side of tree
Node* Dictionary::MinimumValueNode(Node *root)
{
    Node* move = root;
     while(move && move->left != NULL)
        move = move->left;

    return move;
}

// Finds Smalled note on right side of tree that can be used to replace node that is suppsed to be delated
Node* Dictionary::DeleteNode(Node* root,string word)
{
    if(root == NULL)
        return root;

    if(word < root->word)
        root->left = DeleteNode(root->left,word);

    else if(word > root->word)
        root->right = DeleteNode(root->right,word);

    else
    {
        if(root->left == NULL)
        {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if(root->right == NULL)
        {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        Node* temp = MinimumValueNode(root->right);
        root->word = temp->word;
        root->meaning = temp->meaning;
        root->right = DeleteNode(root->right,temp->word);
    }
    return root;
}

// Search Node from bst and update it's data.
void Dictionary::UpdateNode(Node* root,string searchWord,string newWord,string meaning)
{
    Node* UpdateNode = SearchWord(root,searchWord);
    UpdateNode->word = newWord;
    UpdateNode->meaning = meaning;
}
// END Of Dictionary Class Member Functions
