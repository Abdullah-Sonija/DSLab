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

class HashTable
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
    HashTable()
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

    void display()
    {
        for(int i=0; i<SIZE; i++)
        {
            Node* curr = table[i];
            if(curr)
            {
                cout<<"Index "<<i<<": ";
                while(curr)
                {
                    cout<<"("<<curr->key<<","<<curr->value<<") ";
                    curr = curr->next;
                }
                cout<<endl;
            }
        }
    }
};

int main()
{
    HashTable myhash;
    myhash.insert("A","aaaaa");
    myhash.insert("B","bbbbb");
    myhash.insert("C","ccccc");
    myhash.insert("A","zzzzz");
    myhash.display();
    return 0;
}
