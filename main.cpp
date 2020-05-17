#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int arraySortedOrNot(int arr[], int n)
{
    if (n == 1 || n == 0)
        return 1;

    if (arr[n - 1] < arr[n - 2])
        return 0;

    return arraySortedOrNot(arr, n - 1);
}

int main()
{
    int T;
    cin >> T;

    for(int i = 0; i < T; i++){
        int bribe = 0;
        int ct = 0;
        int t;
        cin >> t;
        cin.ignore();

        int arr[t];
        for(int i = 0; i < t; i++){
            cin >> arr[i];
        }

        int rep[t];
        for(int i =0; i < t; i++){
            rep[i] = 0;
        }

        for(int i = 0; i < t; i++){
            for(int z= t-1; z > 0; z--){
                if(arr[z-1] > arr[z]){
                    int temp = arr[z-1];
                    arr[z-1] = arr[z];
                    arr[z] = temp;
                    rep[arr[z]-1]++;
                    bribe ++;
                }
            }
            if (arraySortedOrNot(arr, t))
                break;
        }

        for(int i= 0; i < t; i++){
            if(rep[i] > 2){
                ct++;
                break;
            }
        }

        if(ct > 0){
            cout << "Too chaotic" << endl;
        }else{
            cout << bribe << endl;
        }

    }

    return 0;
}
