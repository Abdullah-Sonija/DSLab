#include <iostream>
#include <string>
using namespace std;

struct Node
{
    string key;
    string value;
    Node* next;
    Node(string k, string v)
    {
        key = k;
        value = v;
        next = NULL;
    }
};

class Hash
{
    static const int SIZE = 10;
    Node* table[SIZE];

    int hashFunc(string key)
    {
        int sum = 0;
        for(char c : key) sum += c;
        return sum % SIZE;
    }

public:
    Hash()
    {
        for(int i=0; i<SIZE; i++)
            table[i] = NULL;
    }

    void insert(string key, string value)
    {
        int index = hashFunc(key);
        Node* n = new Node(key, value);
        n->next = table[index];
        table[index] = n;
    }

    void removeKey(string key)
    {
        int index = hashFunc(key);
        Node* curr = table[index];
        Node* prev = NULL;

        while(curr)
        {
            if(curr->key == key)
            {
                if(prev == NULL) table[index] = curr->next;
                else prev->next = curr->next;
                delete curr;
                return;
            }
            prev = curr;
            curr = curr->next;
        }
    }

    void search(string key)
    {
        int index = hashFunc(key);
        Node* curr = table[index];
        while(curr)
        {
            if(curr->key == key)
            {
                cout<<curr->key<<" -> "<<curr->value<<endl;
                return;
            }
            curr = curr->next;
        }
        cout<<"Key not found"<<endl;
    }

    void display()
    {
        for(int i=0; i<SIZE; i++)
        {
            cout<<i<<": ";
            Node* curr = table[i];
            while(curr)
            {
                cout<<"("<<curr->key<<","<<curr->value<<") ";
                curr = curr->next;
            }
            cout<<endl;
        }
    }
};

int main()
{
    Hash h;
    h.insert("A","aaaaa");
    h.insert("B","bbbbb");
    h.insert("C","ccccc");
    h.insert("A","zzzzz");
    h.display();
    h.search("A");
    h.removeKey("B");
    h.display();
    return 0;
}
