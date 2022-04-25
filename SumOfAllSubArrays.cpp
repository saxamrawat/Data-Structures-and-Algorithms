#include <iostream>
using namespace std;

int main()
{
    int n; // length of array
    cin >> n;

    int curr; // holds current sum

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++)
    { // outer loop
        curr = 0;

        for (int j = i; j < n; j++)
        { // innerloop
            curr += arr[j];
            cout << curr << endl;
        }
    }
}