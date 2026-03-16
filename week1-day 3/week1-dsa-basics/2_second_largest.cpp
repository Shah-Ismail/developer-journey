#include <iostream>
#include <climits>

using namespace std;

void menu();
void sec_largest(int n,int arr[]);

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
        cout << "\n----------SECOND LARGEST CHECKER----------\n";
        cout << "\nChoose operation :\n";
        cout << "1.Check second largest.\n";
        cout << "2.Exit.\n";
        
        cout << "\nEnter your choice : ";
        cin >> choice;
        
        if (choice == 1)
        {
            cout << "\nEnter the size of array : ";
            cin >> n;
            if(n < 2)
            {
                cout << "\nSize must be greater than 1!\n";
                continue;
            }
            cout << "\nEnter elements : \n";
            for (int i = 0; i < n; i++)
            {
                cin >> arr[i];
            }
            
            sec_largest(n,arr);
        }
        else if (choice == 2)
        {
            cout << "\nExiting...";
            return;
        }
        else
        {
            cout << "\nInvalid Input!\n";
        }
    }
}

void sec_largest(int n,int arr[])
{
    int sec_largest = INT_MIN, largest = INT_MIN;
    
    for (int i = 0; i < n; i++)
    {
        if(arr[i] > largest)
        {
            sec_largest = largest;
            largest = arr[i];
        }
        else if (arr[i] < largest && arr[i] > sec_largest)
        {
            sec_largest = arr[i];
        }
    }
    if (sec_largest == INT_MIN)
    {
        cout << "\nThere is no second largest(all elements might b same).\n";
    }
    else
    {
        cout << "\nSecond largest is : " << sec_largest << endl;
    }
    return;
}