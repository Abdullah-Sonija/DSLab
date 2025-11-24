#include <iostream>
using namespace std;

void findPairs(int arr[], int n)
{
    int stored[100][3];
    int count = 0;
    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            int sum = arr[i] + arr[j];

            for(int k=0; k<count; k++)
            {
                if(stored[k][0] == sum)
                {
                    int a = stored[k][1];
                    int b = stored[k][2];
                    if(a != arr[i] && a != arr[j] && b != arr[i] && b != arr[j])
                    {
                        cout<<"("<<a<<","<<b<<") and ("<<arr[i]<<","<<arr[j]<<")"<<endl;
                        return;
                    }
                }
            }

            stored[count][0] = sum;
            stored[count][1] = arr[i];
            stored[count][2] = arr[j];
            count++;
        }
    }

    cout<<"No pairs found"<<endl;
}

int main()
{
    int arr1[] = {3,4,7,1,2,9,8};
    int n1 = sizeof(arr1)/sizeof(arr1[0]);
    findPairs(arr1,n1);
    int arr2[] = {3,4,7,1,12,9};
    int n2 = sizeof(arr2)/sizeof(arr2[0]);
    findPairs(arr2,n2);
    int arr3[] = {65,30,7,90,1,9,8};
    int n3 = sizeof(arr3)/sizeof(arr3[0]);
    findPairs(arr3,n3);
    return 0;
}
