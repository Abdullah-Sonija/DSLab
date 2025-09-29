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

    void segregateEvenOdd()
    {
        if(!head)return;

        Node *evenStart=nullptr,*evenEnd=nullptr;
        Node *oddStart=nullptr,*oddEnd=nullptr;
        Node *cur=head;

        while(cur)
        {
            if(cur->data%2==0)
            {
                if(!evenStart)
                    evenStart=evenEnd=cur;
                else
                {
                    evenEnd->next=cur;
                    evenEnd=evenEnd->next;
                }
            }
            else
            {
                if(!oddStart)
                    oddStart=oddEnd=cur;
                else
                {
                    oddEnd->next=cur;
                    oddEnd=oddEnd->next;
                }
            }
            cur=cur->next;
        }

        if(!evenStart || !oddStart)
            return;

        evenEnd->next=oddStart;
        oddEnd->next=nullptr;
        head=evenStart;
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
    int arr[]={17,15,8,12,10,5,4,1,7,6};
    for(int x:arr)L.pushBack(x);
    cout<<"Original List: ";
    L.print();
    L.segregateEvenOdd();
    cout<<"Modified List: ";
    L.print();
    return 0;
}
