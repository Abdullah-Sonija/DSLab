#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int val):data(val),next(nullptr){}
};

class LinkedList
{
public:
    Node *head;
    LinkedList():head(nullptr){}

    void pushBack(int val)
    {
        Node *n=new Node(val);
        if(!head)
        {
            head=n;
            return;
        }
        Node *cur=head;
        while(cur->next) cur=cur->next;
        cur->next=n;
    }

    void rearrangeAlternateReverse()
    {
        if(!head || !head->next) return;

        Node *odd=head;
        Node *even=head->next;
        Node *evenHead=even;

        while(even && even->next)
        {
            odd->next=even->next;
            odd=odd->next;
            even->next=odd->next;
            even=even->next;
        }
        odd->next=nullptr;

        Node *prev=nullptr,*cur=evenHead,*next=nullptr;
        while(cur)
        {
            next=cur->next;
            cur->next=prev;
            prev=cur;
            cur=next;
        }
        Node *reversed=prev;

        Node *tail=head;
        while(tail->next) tail=tail->next;
        tail->next=reversed;
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
    int arr[]={190,4,9,1,3,5,9,4};
    for(int x:arr) L.pushBack(x);

    cout<<"Original List: ";
    L.print();

    L.rearrangeAlternateReverse();

    cout<<"After rearrangement: ";
    L.print();

    return 0;
}
