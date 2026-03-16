#include <iostream>

using namespace std;

void menu();
void array_reverse(int n,int arr[]);

int main()
{
	menu();
	return 0;
}

void menu()
{
    int choice;
    int n;
    int arr[1000];
    while (true)
    {
        cout << "\n----------ARRAY REVERSER----------\n";
        cout << "\nChoose operation : \n";
        cout << "1.Revese array.\n";
        cout << "2.Exit.";
        
        cout << "\nEnter choice : ";
        cin >> choice;
        
        if (choice == 1)
        {
            cout << "\nEnter number of elements in array : ";
            cin >> n ;
            cout << "\nEnter array :\n";
            for(int i = 0; i < n; i++)
            {
                cin >> arr[i];
            }
            array_reverse(n, arr);
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

void array_reverse(int n, int arr[])
{
    int temp, start = 0, end = n - 1;
    while (start < end)
    {
        temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
    
    cout << "\nReversed array : ";
    
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return;
}