
#include <iostream>
using namespace std;

int main()
{
    int table[10], n, id;

    for (int i = 0; i < 10; i++)
        table[i] = -1;

    cout << "Enter number of students: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << "Enter student ID: ";
        cin >> id;

        int h1 = id % 10;
        int h2 = 7 - (id % 7);
        int index = h1;
        int count = 0;

        while (table[index] != -1 && count < 10)
        {
            count++;
            index = (h1 + count * h2) % 10;
        }

        if (count == 10)
            cout << "Hash table is full or no slot found\n";
        else
            table[index] = id;
    }

    cout << "\nHash Table:\n";

    for (int i = 0; i < 10; i++)
        cout << i << " : " << table[i] << endl;

    return 0;
}
