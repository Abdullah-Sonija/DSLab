#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

class CircularLinkedList
{
    Node* head;
public:
    CircularLinkedList()
    {
        head=NULL;
    }

    void insertAtEnd(int value)
    {
        Node* newNode=new Node{value,NULL};
        if(!head)
        {
            head=newNode;
            head->next=head;
            return;
        }
        Node* temp=head;
        while(temp->next!=head)
            temp=temp->next;
        temp->next=newNode;
        newNode->next=head;
    }

    void insertAtBeginning(int value)
    {
        Node* newNode=new Node{value,NULL};
        if(!head)
        {
            head=newNode;
            head->next=head;
            return;
        }
        Node* temp=head;
        while(temp->next!=head)
            temp=temp->next;
        newNode->next=head;
        temp->next=newNode;
        head=newNode;
    }

    void insertAtPosition(int value,int pos)
    {
        if(pos<1)
        {
            cout<<"Invalid Position"<<endl;
            return;
        }
        Node* newNode=new Node{value,NULL};
        if(pos==1)
        {
            insertAtBeginning(value);
            return;
        }
        Node* temp=head;
        int count=1;
        while(count<pos-1 && temp->next!=head)
        {
            temp=temp->next;
            count++;
        }
        if(count!=pos-1)
        {
            cout<<"Position out of range"<<endl;
            delete newNode;
            return;
        }
        newNode->next=temp->next;
        temp->next=newNode;
    }

    void deleteNode(int value)
    {
        if(!head)
        {
            cout<<"List is empty"<<endl;
            return;
        }
        Node* curr=head;
        Node* prev=NULL;

        if(head->data==value)
        {
            if(head->next==head)
            {
                delete head;
                head=NULL;
                return;
            }
            Node* last=head;
            while(last->next!=head)
                last=last->next;
            last->next=head->next;
            Node* del=head;
            head=head->next;
            delete del;
            return;
        }

        do
        {
            prev=curr;
            curr=curr->next;
            if(curr->data==value)
            {
                prev->next=curr->next;
                delete curr;
                return;
            }
        }while(curr!=head);

        cout<<"Value not found in list"<<endl;
    }

    void display()
    {
        if(!head)
        {
            cout<<"List is empty"<<endl;
            return;
        }
        Node* temp=head;
        do
        {
            cout<<temp->data<<" -> ";
            temp=temp->next;
        }while(temp!=head);
        cout<<"(back to head)"<<endl;
    }
};

int main()
{
    CircularLinkedList cll;
    cll.insertAtEnd(10);
    cll.insertAtEnd(20);
    cll.insertAtEnd(30);
    cll.display();

    cout<<"Insert at beginning: 5"<<endl;
    cll.insertAtBeginning(5);
    cll.display();

    cout<<"Insert at position 3: 15"<<endl;
    cll.insertAtPosition(15,3);
    cll.display();

    cout<<"Delete value 20"<<endl;
    cll.deleteNode(20);
    cll.display();

    cout<<"Delete value 100 (not present)"<<endl;
    cll.deleteNode(100);
    cll.display();

    return 0;
}
