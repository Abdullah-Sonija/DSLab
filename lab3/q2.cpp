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

    void moveFrontToEnd(int count)
    {
        if(!head || count<=0)return;
        int length=0;
        Node *cur=head;
        while(cur)
        {
            length++;
            cur=cur->next;
        }
        if(count>=length)return; 
        Node *prev=nullptr;
        cur=head;
        for(int i=0;i<count;i++)
        {
            prev=cur;
            cur=cur->next;
        }
        Node *newHead=cur; 
        Node *last=newHead;
        while(last->next)
        {
            last=last->next;
        }
        last->next=head;
        prev->next=nullptr; 
        head=newHead;
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
    LinkedList L;
    int arr[]={5,3,1,8,6,4,2};
    for(int x:arr)L.pushBack(x);
    cout<<"Original List: ";
    L.print();
    int k;
    cout<<"Enter number of elements to move from front to end: ";
    cin>>k;
    L.moveFrontToEnd(k);
    cout<<"After rotation: ";
    L.print();
    return 0;
}
