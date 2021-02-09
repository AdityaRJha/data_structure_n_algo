#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void printArray(int arr[], int n)
{
    for(int i = 0; i < n; i ++)
    {
        cout<<arr[i]<<endl;
    }
}

void reverseArrayIterations(int arr[], int n)//n is the size of the array from Method 1
{
    //This algorithm has the O(n)
    --n;
    for(int i =0; i < n; i++)
    {
        //cout << "A\n";
        //swapping takes place
        if(i >= n - i)
        {
            //cout << "A\n";
            break;
        }

        //cout << "A\n";
        int temp = 0;
        temp = arr[i];
        arr[i] = arr[n - i];
        arr[n - i] = temp;
    }
    //cout << "A\n";
    cout<<"reverseArrayIterations(int arr[], int n): "<< endl;
    printArray(arr, ++n);
}

void reverseArrayRecursions(int arr[], int start, int end)
{
    if(start == end)
    {
        //This algorithm has time: O(n)
        //and space: O(1)
        //cout<<"reverseArrayRecursions(int arr[], int n):"<<endl;
        //printArray(arr, start + end);
        return;
    } 
    else if(start > end)
    {
        //cout<<"reverseArrayRecursions(int arr[], int n):"<<endl;
        //printArray(arr, start + end + 1);
        return;
    }
    else
    {
        int temp = 0;
        temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
    }
    reverseArrayRecursions(arr, ++start, --end);
}

int main()
{
    //cout<<"Enter the size of the array\t: ";
    //int size;
    //cin >> size;
    //int* arr = new int[size];

    int arr2[5] = {1,2,3,4,5};

    //cout<<"Start entering the elements.\n";
    //for(int i = 0; i < size; i++)
    //{
      //  cin>>arr[i];
    //} 
    cout<<"Array: \n";
    printArray(arr2, 5);
    
    reverseArrayIterations(arr2, 5);

    //printArray(arr2, 5);

    reverseArrayRecursions(arr2, 0 , 4);
    printArray(arr2, 5);

    return 0;
}

