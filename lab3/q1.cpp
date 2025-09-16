#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int val):data(val),next(nullptr) {}
};

class LinkedList
{
public:
    Node *head;
    LinkedList():head(nullptr) {}

    void pushFront(int val)
    {
        Node *n=new Node(val);
        n->next=head;
        head=n;
    }

    void pushBack(int val)
    {
        Node *n=new Node(val);
        if(!head)
        {
            head=n;
            return;
        }
        Node *cur=head;
        while(cur->next)
            cur=cur->next;
        cur->next=n;
    }

    void insertAt(int pos,int val)
    {
        if(pos<=1)
        {
            pushFront(val);
            return;
        }
        Node *cur=head;
        int idx=1;
        while(cur && idx<pos-1)
        {
            cur=cur->next;
            idx++;
        }
        if(!cur)
        {
            pushBack(val);
            return;
        }
        Node *n=new Node(val);
        n->next=cur->next;
        cur->next=n;
    }

    void deleteValue(int val)
    {
        if(!head)return;
        if(head->data==val)
        {
            Node *d=head;
            head=head->next;
            delete d;
            return;
        }
        Node *cur=head;
        while(cur->next && cur->next->data!=val)
            cur=cur->next;
        if(!cur->next)return;
        Node *t=cur->next;
        cur->next=t->next;
        delete t;
    }

    void print()
    {
        Node *cur=head;
        while(cur)
        {
            cout<<cur->data<<" ";
            cur=cur->next;
        }
        cout<<"\n";
    }
};

int main()
{
    int arr[5]={3,1,2,5,8};
    cout<<"Array: ";
    for(int i=0;i<5;i++)cout<<arr[i]<<" ";
    cout<<"\n";
    LinkedList L;
    for(int i=0;i<5;i++)L.pushBack(arr[i]);
    L.pushBack(9);
    L.insertAt(3,11);
    L.pushFront(4);
    L.deleteValue(1);
    L.deleteValue(2);
    L.deleteValue(5);
    cout<<"Final Linked List: ";
    L.print();
    return 0;
}
