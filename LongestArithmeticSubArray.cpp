/*

Algo: Loop over the array and maintain the following variables:
1. Previous Difference(pd)
2. Current Arithmetic SubArray Length(curr)
3. Max Arithmetic Subarray Length(ans)

*/

// Code:

#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++) // array input
    {
        cin >> arr[i];
    }

    int ans = 2;
    int pd = arr[1] - arr[0];
    int curr = 2;
    int j = 2;

    while (j < n)
    {
        if (pd == arr[j] - arr[j - 1])
        {
            curr++;
        }
        else
        {
            pd = arr[j] - arr[j - 1];
            curr = 2;
        }
        ans = max(ans, curr);
        j++;
    }

    cout << ans << endl;
    return 0;
}