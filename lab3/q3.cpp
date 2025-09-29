#include <iostream>
#include <string>
using namespace std;

struct Node
{
    string name;
    Node *next;
    Node(string n):name(n),next(nullptr) {}
};

class PassengerList
{
    Node *head;
public:
    PassengerList():head(nullptr) {}

    void reserveTicket(const string &name)
    {
        Node *n=new Node(name);
        if(!head || name<head->name)
        {
            n->next=head;
            head=n;
            cout<<"Ticket reserved for "<<name<<"\n";
            return;
        }
        Node *cur=head;
        while(cur->next && cur->next->name<name)
            cur=cur->next;
        if(cur->name==name || (cur->next && cur->next->name==name))
        {
            cout<<"Passenger "<<name<<" already has a reservation.\n";
            delete n;
            return;
        }
        n->next=cur->next;
        cur->next=n;
        cout<<"Ticket reserved for "<<name<<"\n";
    }

    void cancelTicket(const string &name)
    {
        if(!head)
        {
            cout<<"No reservations found.\n";
            return;
        }
        if(head->name==name)
        {
            Node *temp=head;
            head=head->next;
            delete temp;
            cout<<"Reservation for "<<name<<" cancelled.\n";
            return;
        }
        Node *cur=head;
        while(cur->next && cur->next->name!=name)
            cur=cur->next;
        if(!cur->next)
        {
            cout<<"No reservation found for "<<name<<"\n";
            return;
        }
        Node *temp=cur->next;
        cur->next=cur->next->next;
        delete temp;
        cout<<"Reservation for "<<name<<" cancelled.\n";
    }

    void checkPassenger(const string &name)
    {
        Node *cur=head;
        while(cur)
        {
            if(cur->name==name)
            {
                cout<<name<<" has a reservation.\n";
                return;
            }
            cur=cur->next;
        }
        cout<<name<<" does not have a reservation.\n";
    }

    void displayPassengers()
    {
        if(!head)
        {
            cout<<"No passengers.\n";
            return;
        }
        cout<<"Passenger List:\n";
        Node *cur=head;
        while(cur)
        {
            cout<<"- "<<cur->name<<"\n";
            cur=cur->next;
        }
    }
};

int main()
{
    PassengerList flight;
    int choice;
    string name;
    do
    {
        cout<<"\nAirline Reservation Menu\n";
        cout<<"1. Reserve Ticket\n";
        cout<<"2. Cancel Reservation\n";
        cout<<"3. Check Reservation\n";
        cout<<"4. Display Passengers\n";
        cout<<"5. Exit\n";
        cout<<"Enter choice: ";
        cin>>choice;
        cin.ignore();
        switch(choice)
        {
            case 1:
                cout<<"Enter passenger name: ";
                getline(cin,name);
                flight.reserveTicket(name);
                break;
            case 2:
                cout<<"Enter passenger name: ";
                getline(cin,name);
                flight.cancelTicket(name);
                break;
            case 3:
                cout<<"Enter passenger name: ";
                getline(cin,name);
                flight.checkPassenger(name);
                break;
            case 4:
                flight.displayPassengers();
                break;
            case 5:
                cout<<"Exiting...\n";
                break;
            default:
                cout<<"Invalid choice.\n";
        }
    } while(choice!=5);
    return 0;
}
