
#include <iostream>
using namespace std;

struct Node
{
    int code;
    Node *next;
};

Node *table[10] = {NULL};

void insertBook(int code)
{
    int index = code % 10;

    Node *newNode = new Node;
    newNode->code = code;
    newNode->next = table[index];
    table[index] = newNode;
}

int main()
{
    int n, code;

    cout << "Enter number of books: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << "Enter book code: ";
        cin >> code;
        insertBook(code);
    }

    cout << "\nShelf Contents:\n";

    for (int i = 0; i < 10; i++)
    {
        cout << i << " : ";
        Node *temp = table[i];

        while (temp != NULL)
        {
            cout << temp->code << " -> ";
            temp = temp->next;
        }

        cout << "NULL\n";
    }

    return 0;
}
