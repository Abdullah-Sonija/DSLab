#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
    Node* prev;
};

struct DoublyLinkedList
{
    Node* head;
    Node* tail;
    DoublyLinkedList() { head=tail=NULL; }

    void insertAtEnd(int value)
    {
        Node* newNode=new Node{value,NULL,NULL};
        if(!head)
        {
            head=tail=newNode;
            return;
        }
        tail->next=newNode;
        newNode->prev=tail;
        tail=newNode;
    }

    void display()
    {
        Node* temp=head;
        while(temp)
        {
            cout<<temp->data<<" <-> ";
            temp=temp->next;
        }
        cout<<"NULL"<<endl;
    }
};

DoublyLinkedList concatenate(DoublyLinkedList &L, DoublyLinkedList &M)
{
    if(!L.head) return M; 
    if(!M.head) return L; 

    L.tail->next=M.head;
    M.head->prev=L.tail;

    L.tail=M.tail; 
    return L;
}

int main()
{
    DoublyLinkedList L, M;
    L.insertAtEnd(1);
    L.insertAtEnd(2);
    L.insertAtEnd(3);

    M.insertAtEnd(4);
    M.insertAtEnd(5);
    M.insertAtEnd(6);

    cout<<"List L: "; L.display();
    cout<<"List M: "; M.display();

    cout<<"After concatenation:"<<endl;
    DoublyLinkedList combined=concatenate(L,M);
    combined.display();

    return 0;
}
