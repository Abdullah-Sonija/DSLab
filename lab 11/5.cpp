#include <iostream>
using namespace std;

struct Student
{
    int roll;
    string name;
    bool used;
    Student() { used = false; }
};

class StudentHashTable
{
    Student table[15];
    int hashFunc(int roll)  {return roll % 15;}
public:
    void InsertRecord(int roll, string name)
    {
        int index = hashFunc(roll);
        int attempt = 0;
        while(table[(index + attempt*attempt) % 15].used)
            attempt++;
        int pos = (index + attempt*attempt) % 15;
        table[pos].roll = roll;
        table[pos].name = name;
        table[pos].used = true;
    }

    void SearchRecord(int roll)
    {
        int index = hashFunc(roll);
        int attempt = 0;
        while(attempt < 15)
        {
            int pos = (index + attempt*attempt) % 15;
            if(table[pos].used && table[pos].roll == roll)
            {
                cout<<"Student found: "<<table[pos].name<<endl;
                return;
            }
            attempt++;
        }
        cout<<"Record not found"<<endl;
    }
};

int main()
{
    StudentHashTable ht;
    ht.InsertRecord(101, "Ali");
    ht.InsertRecord(116, "Sara");
    ht.InsertRecord(131, "Hamza");
    ht.InsertRecord(146, "Ayesha");
    ht.SearchRecord(101);
    ht.SearchRecord(146);
    ht.SearchRecord(200);
    return 0;
}
