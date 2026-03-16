#include <iostream>

using namespace std;

void menu();
void search(int num,int n,int arr[]);

int main()
{
    menu();
    return 0;
}

void menu()
{
    int choice;
    int num;
    int n;
    int arr[1000];
    
    while (true)
    {
        cout << "\n----------BINARY SEARCHER----------\n";
        cout << "\nChoose operation : \n";
        cout << "1.Search number.\n";
        cout << "2.Exit.\n";
        
        cout << "\nEnter choice here : ";
        cin >> choice;
        
        if (choice == 1)
        {
            cout << "\nEnter size of array : ";
            cin >> n;
            cout << "\nEnter " << n << " array elements :\n";
            cout << "\nNOTE: ENTER SORTED ARRAY IF UNSORTED\nIT WILL SORT AND TELL THE SORTED\nINDEX!\n\n";
            for (int i = 0; i < n; i++)
                cin >> arr[i];
            cout << "\nEnter number to search : ";
            cin >> num;
            
            search(num, n, arr);
        }
        else if (choice == 2)
        {
            cout << "\nExiting...\n";
            return;
        }
        else 
        {
            cout << "\nInvalid Input!\n";
        }
    }
}

void search(int num, int n, int arr[])
{
    int temp;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    
    int low = 0, high = n - 1;
    int mid;    
    
    while (low <= high)
    {
        mid = low + (high - low) / 2;
        if (arr[mid] == num)
        {
            cout << endl << num << " is on index : " << mid << " (Position : " << mid + 1 << " ). In array : ";
            for (int i = 0; i < n; i++)
                cout << arr[i] << " ";
            cout << endl;
            return;
        }
        else if (arr[mid] > num && num >= arr[low])
        {
            high = mid - 1;  
        }
        else if (arr[mid] < num && num <= arr[high])
        {
            low = mid + 1;
        }
        else 
        {
            cout << "\n\"" << num << "\" does not exist in the array : ";
            for (int i = 0; i < n; i++)
                cout << arr[i] << " ";
            cout << endl;
            return;
        }
    }
}