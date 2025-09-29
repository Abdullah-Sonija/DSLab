#include <iostream>
#include <string>
using namespace std;

struct Node
{
    char data;
    Node *next;
    Node(char val):data(val),next(nullptr) {}
};

class LinkedList
{
public:
    Node *head;
    LinkedList():head(nullptr) {}

    void pushBack(char val)
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

    Node* reverseList(Node* start)
    {
        Node *prev=nullptr,*cur=start,*next=nullptr;
        while(cur)
        {
            next=cur->next;
            cur->next=prev;
            prev=cur;
            cur=next;
        }
        return prev;
    }

    bool isPalindrome()
    {
        if(!head || !head->next)
            return true;

        Node *slow=head,*fast=head;
        while(fast->next && fast->next->next)
        {
            slow=slow->next;
            fast=fast->next->next;
        }

        Node *secondHalf=reverseList(slow->next);
        Node *firstHalf=head;
        Node *copySecond=secondHalf;

        bool palindrome=true;
        while(secondHalf)
        {
            if(firstHalf->data!=secondHalf->data)
            {
                palindrome=false;
                break;
            }
            firstHalf=firstHalf->next;
            secondHalf=secondHalf->next;
        }

        slow->next=reverseList(copySecond);
        return palindrome;
    }

    void print()
    {
        Node *cur=head;
        while(cur)
        {
            cout<<cur->data;
            if(cur->next)cout<<"->";
            cur=cur->next;
        }
        cout<<"->NULL\n";
    }
};

int main()
{
    LinkedList L;
    string input="ABBA";
    for(char c:input)L.pushBack(c);

    cout<<"Input List: ";
    L.print();

    if(L.isPalindrome())
        cout<<"Linked List is a Palindrome\n";
    else
        cout<<"Linked List is NOT a Palindrome\n";

    return 0;
}
