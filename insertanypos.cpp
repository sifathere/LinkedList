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
        if (!head) head = newNode;
        else {
            Node* temp = head;
            while (temp->next) temp = temp->next;
            temp->next = newNode;
        }
        size++;
    }

    void insertAt(int pos, int data) {
        if (pos < 1 || pos > size + 1) {
            cout << "Invalid position!\n";
            return;
        }
        Node* newNode = new Node(data);
        if (pos == 1) {
            newNode->next = head;
            head = newNode;
        } else {
            Node* temp = head;
            for (int i = 1; i < pos - 1; ++i)
                temp = temp->next;
            newNode->next = temp->next;
            temp->next = newNode;
        }
        size++;
    }

    void display() const {
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

    cout << "\nEnter position and value to insert: ";
    cin >> pos >> value;
    list.insertAt(pos, value);
    
    cout << "Updated list: ";
    list.display();

    return 0;
}
