#include <iostream>
using namespace std;

class LinkedList {
    struct Node {
        int data;
        Node* next;
        Node(int val) : data(val), next(nullptr) {}
    };

    Node* head;
    int size;

public:
    LinkedList() : head(nullptr), size(0) {}

    void insert(int data) {
        Node* newNode = new Node(data);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) temp = temp->next;
            temp->next = newNode;
        }
        size++;
    }

    int getNthNode(int pos) {
        if (pos < 1 || pos > size) return -1;
        Node* current = head;
        for (int i = 1; i < pos; ++i) current = current->next;
        return current->data;
    }

    void display() {
        for (Node* temp = head; temp != nullptr; temp = temp->next)
            cout << temp->data << " ";
        cout << endl;
    }
};

int main() {
    LinkedList list;
    int n, value, pos;

    cout << "How many nodes to insert? ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter value: ";
        cin >> value;
        list.insert(value);
    }

    cout << "Linked list: ";
    list.display();

    cout << "\nEnter position to retrieve value: ";
    cin >> pos;
    int result = list.getNthNode(pos);
    if (result != -1)
        cout << "Value at position " << pos << ": " << result << endl;
    else
        cout << "Invalid position!" << endl;

    return 0;
}
