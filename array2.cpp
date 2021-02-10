#include<iostream>

using namespace std;

struct Pair
{
    int min;
    int max;
};

Pair minmax(int arr[], int n)
{
    Pair send;
    send.max = send.min = arr[0];
    while(n)
    {
        if(arr[n -1] > send.max)
            send.max = arr[n -1];
        if(arr[n-1] < send.min)
            send.min = arr[n-1];
        --n;
    }
    return send;
}

Pair minmaxRecursion(int arr[], int high, int low)
{
    Pair send, above, below;
    int mid;
    if(high == low)
    {
        send.max = send.min = arr[0];
        return send;
    }
    if(high == low + 1)
    {
        if (arr[high] > arr[low])
        {
            send.max = arr[high];
            send.min = arr[low];
        }
        else
        {
            send.max = arr[low];
            send.min = arr[high];
        }
        return send;        
    }

    mid = (int)((low+high)/2);
    above = minmaxRecursion(arr, high, mid + 1);
    below = minmaxRecursion(arr, mid, low);
    if(above.max > below.max)
        send.max = above.max;
    else
        send.max = below.max;

    if(above.min < below.min)
        send.min = above.min;
    else
        send.min = below.min;

    return send;

}

Pair minmaxPairing(int arr[], int n)
{
    Pair send;
    int i;
    if(n % 2 == 0)
    {
        if (arr[0] > arr[1])
        {
            send.min = arr[1];
            send.max = arr[0];
        }
        else
        {
            send.max = arr[1];
            send.min = arr[0];
        }
        i = 2;
        
    }
    else
    {
        send.min = send.max = arr[0];
        i = 1;
    }

    while (i < n -1)
    {
        if (arr[i] < arr[i + 1])
        {
            if(arr[i] < send.min)
                send.min = arr[i];
            if(arr[i + 1] > send.max)
                send.max = arr[i + 1];
        }
        else
        {
            if(arr[i + 1] < send.min)
                send.min = arr[i + 1];
            if(arr[i] > send.max)
                send.max = arr[i];
        }
        i += 2;
    }
    return send;
}

void print(Pair p)
{
    cout<<"\nMax: "<<p.max;
    cout<<"\nMin: "<<p.min;
}


int main()
{
    int arr[] = {1321, 632, 56, 25, 36, 56, 751, 23, 1};

    Pair p1, p2, p3;
    p1 = minmaxPairing(arr, 9);
    p2 = minmaxRecursion(arr, 8, 0);
    p3 = minmax(arr, 9);
    print(p1);
    print(p2);
    print(p3);

}
