/*
    Minimum Spaning Tree Using Prim's Algorithm
              200     300
           0 ---- 1 ----- 2
    600    |     / \      | 700   
           3 -------------4
                 900
*/
#include"header.h"
int main(void)
{
    SpaningTree st = SpaningTree(5,7);
    st.printAdjMatrix();
    st.addEdge(0,1,200);
    st.addEdge(0,3,600);
    st.addEdge(1,2,300);
    st.addEdge(1,4,500);
    st.addEdge(2,4,700);
    st.addEdge(3,4,900);
    cout<<endl<<endl;
    st.printAdjMatrix();
    st.minimumTree();
}

