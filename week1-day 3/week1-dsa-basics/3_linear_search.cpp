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
        cout << "\n----------LINEAR SEARCHER----------\n";
        cout << "\nChoose an operation :\n";
        cout << "1.Search for number.\n";
        cout << "2.Exit.\n";
        
        cout << "\nEnter choice here : ";
        cin >> choice;
        
        if (choice == 1)
        {
            cout << "\nEnter size of array : ";
            cin >> n;
            
            cout << "\nEnter array elements one by one : \n";
            for (int i = 0; i < n; i++)
            {
                cin >> arr[i];
            }
            
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
    for (int i = 0; i < n; i++)
    {
        if (num == arr[i])
        {
            cout << endl << num << " is on index : " << i << " (Position : " << i + 1 << ").\n";
            return;
        }
    }
    cout << "\nNot found\n";
    return;
}