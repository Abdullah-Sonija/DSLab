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

class ASCIIDictionary
{
    static const int SIZE = 100;
    Node* table[SIZE];

    int hashFunc(string key)
    {
        int sum = 0;
        for(char c : key) sum += c;
        return sum % SIZE;
    }

public:
    ASCIIDictionary()
    {
        for(int i=0; i<SIZE; i++)
            table[i] = NULL;
    }

    void Add_Record(string key, string meaning)
    {
        int index = hashFunc(key);
        Node* n = new Node(key, meaning);
        n->next = table[index];
        table[index] = n;
    }

    void Word_Search(string key)
    {
        int index = hashFunc(key);
        Node* curr = table[index];
        while(curr)
        {
            if(curr->key == key)
            {
                cout<<"search key "<<key<<": "<<curr->value<<endl;
                return;
            }
            curr = curr->next;
        }
        cout<<"Error: Word not found"<<endl;
    }

    void Delete_Record(string key)
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
                cout<<"key "<<key<<" deleted successfully "<<endl;
                return;
            }
            prev = curr;
            curr = curr->next;
        }
        cout<<"Error: Word not found"<<endl;
    }

    void Print_Dictionary()
    {
        for(int i=0; i<SIZE; i++)
        {
            Node* curr = table[i];
            if(curr)
            {
                cout<<"index "<<i<<": ";
                while(curr)
                {
                    cout<<"("<<curr->key<<", "<<curr->value<<") ";
                    curr = curr->next;
                }
                cout<<endl;
            }
        }
    }
};

int main()
{
    ASCIIDictionary dict;
    dict.Add_Record("AB", "FASTNU");
    dict.Add_Record("CD", "CS");
    dict.Add_Record("EF", "EE");
    dict.Print_Dictionary();
    dict.Word_Search("AB");
    dict.Delete_Record("EF");
    dict.Print_Dictionary();
    dict.Word_Search("EF");
    return 0;
}
