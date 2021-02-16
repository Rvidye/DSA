/*
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
        cout<<endl<<"\tDictionary of Days"<<endl<<"\t 1 : Display All words"<<endl<<"\t 2 : Add New Word do Dictionary"<<endl<<"\t 3 : Remove A Word From Dictionary"<<endl<<"\t 4 : Update a Existing Word and It's Meaning"<<endl<<"\t 5 : Display Words in Ascending Order"<<endl<<"\t 6 : Display Words in Descending Order"<<endl<<"\t 7 : Search Word In Dictionary"<<endl<<"\t 0 : Exit"<<endl;
        cin>>ch;
        switch(ch)
        {
            case 1:
                cout<<endl<<" WORDS IN DICTIONARY "<<endl;
                days.PreOrder(days.root);
            break;
            case 2:
                cout<<endl<<"Enter New Word and its Meaning to add in Dictionary"<<endl;
                cin>>word;
                cout<<"Enter Meaning of Word"<<endl;
                cin.ignore();
                getline(cin,meaning);
                days.AddNode(word,meaning);
                cout<<"Word Added to Days Dictionary"<<endl;
            break;
            case 3:
                cout<<endl<<"Enter Word To Delete From Dictionary"<<endl;
                cin>>word;
                days.DeleteNode(days.root,word);
                cout<<word<<" Deleted From Days Dictionary"<<endl;
            break;
            case 4:
                cout<<endl<<"Enter Enter Word You want To Update"<<endl;
                cin>>word;
                cout<<endl<<"Enter Enter New WORD AND It's Meaning to Update"<<endl;
                cin>>strNewWord; 
                cout<<"Enter Meaning of Word"<<endl;
                cin.ignore();
                getline(cin,meaning);
                cin >> meaning;
                days.UpdateNode(days.root,word,strNewWord,meaning);
                cout<<"Word Updated to Days Dictionary"<<endl;                
            break;
            case 5:
                cout<<endl<<"Dictionary Words In Ascending order With Their Meaning"<<endl;
                cout<<endl<<endl<<"\t Word : Meaning"<<endl;
                days.InOrder(days.root);
            break;
            case 6:
                cout<<endl<<"Dictionary Words In Descending order With Their Meaning"<<endl;
                cout<<endl<<endl<<"\t Word : Meaning"<<endl;
                days.ReverseInOrder(days.root);
            break;
            case 7:
                cout<<endl<<"Enter a word to search from dictionary."<<endl;
                cin>>word;
                newWord = days.SearchWord(days.root,word);
                cout<<endl<<endl<<"\t Word : Meaning"<<endl;
                newWord->printWordAndMeaning();
                cout<<"Counter : "<<days.counter<<endl;
                days.counter = 0;
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
