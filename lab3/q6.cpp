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

    void deleteByValue(int val)
    {
        if(!head)
        {
            cout<<"List is empty.\n";
            return;
        }

        if(head->data==val)
        {
            Node *temp=head;
            head=head->next;
            delete temp;
            cout<<"Deleted "<<val<<" from the list.\n";
            return;
        }

        Node *cur=head;
        while(cur->next && cur->next->data!=val)
            cur=cur->next;

        if(!cur->next)
        {
            cout<<val<<" not found in the list.\n";
            return;
        }

        Node *temp=cur->next;
        cur->next=cur->next->next;
        delete temp;
        cout<<"Deleted "<<val<<" from the list.\n";
    }

    void print()
    {
        if(!head)
        {
            cout<<"List is empty.\n";
            return;
        }
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
    int arr[]={10,20,30,40,50};
    for(int x:arr)L.pushBack(x);

    cout<<"Original List: ";
    L.print();

    int val;
    cout<<"Enter value to delete: ";
    cin>>val;

    L.deleteByValue(val);

    cout<<"List after deletion: ";
    L.print();

    return 0;
}
