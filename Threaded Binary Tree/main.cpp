/*
Testing Git
A Dictionary stores keywords and its meanings.
Provide facility for adding new keywords, deleting keywords, updating values of any entry.
Provide facility to display whole data sorted in ascending/ Descending order.
Also find how many maximum comparisons may require for finding any keyword.
Use Binary Search Tree for implementation.
*/

/*                                       BINARY SEARCH TREE
                                            INORDER
                                            MONDAY
                                            /   \
                                       FRIDAY  TUESDAY
                                                    / \
                                                   /   \
                                                  /     \
                                            THURSDAY   WEDNESDAY
                                             /   \
                                            /
                                       SATUREDAY
                                        /   \
                                             \
                                            SUNDAY 
*/          

#include"header.h"

int main()
{
    Dictionary days;
    Node* newWord;
    string word,meaning;
    
    word = "MONDAY";
    meaning = "1st Day Of Week";
    days.AddNode(word,meaning);
    
    word = "TUESDAY";
    meaning = "2nd Day Of Week";
    days.AddNode(word,meaning);

    word = "WEDNESDAY";
    meaning = "3rd Day Of Week";
    days.AddNode(word,meaning);

    word = "THURSDAY";
    meaning = "4th Day Of Week";
    days.AddNode(word,meaning);

    word = "FRIDAY";
    meaning = "5th Day Of Week";
    days.AddNode(word,meaning);

    word = "SATURDAY";
    meaning = "WeenEnd Start";
    days.AddNode(word,meaning);

    word = "SUNDAY";
    meaning = "WEEKEND OVER";
    days.AddNode(word,meaning);

    string strNewWord;
    int ch;
    do
    {   
        word = "";
        meaning = "";
        cout<<endl<<"\tDictionary of Days"<<endl<<"\t 1 : Add New Word In Dictionary"<<endl<<"\t 2 : Display Inorder Threaded"<<endl;
        cin>>ch;
        switch(ch)
        {
            case 1:
                cout<<endl<<"Enter New Word and its Meaning to add in Dictionary"<<endl;
                cin>>word;
                cout<<"Enter Meaning of Word"<<endl;
                cin.ignore();
                getline(cin,meaning);
                days.AddNode(word,meaning);
                cout<<"Word Added to Days Dictionary"<<endl;
            break;
            case 2:
                cout<<endl<<"Dictionary Words In Threaded Order"<<endl;
                cout<<endl<<endl<<"\t Word : Meaning"<<endl;
                days.CreateThreaded(days.root);
                days.InOrder(days.root);
            break;
            case 0:
                exit(0);
            break;
            default:
                cout<<endl<<"Wrong Input";
            break;
        }
    }while(ch != 0);
    return 0;
}
