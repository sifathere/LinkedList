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

    void insertMiddle(int data) {
        Node* newNode = new Node(data);
        if (!head) {
            head = newNode;
        } else {
            int mid = size / 2;
            Node* temp = head;
            while (--mid) temp = temp->next;
            newNode->next = temp->next;
            temp->next = newNode;
        }
        size++;
    }

    void display() const {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList list;
    int n, value;

    cout << "Enter the number of initial nodes: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter value for node " << i + 1 << ": ";
        cin >> value;
        list.insert(value);
    }

    cout << "Original list:\n";
    list.display();

    cout << "Enter value to insert in the middle: ";
    cin >> value;
    list.insertMiddle(value);

    cout << "Updated list:\n";
    list.display();

    return 0;
}
