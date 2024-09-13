
#include <iostream>
using namespace std;

class LinkedList {
    struct Node {  // Node structure within the class
        int data;
        Node* next;
        Node(int val) : data(val), next(nullptr) {}  // Constructor for node
    };

    Node* head;  // Pointer to the head of the list

public:
    LinkedList() : head(nullptr) {}  // Constructor initializing head to null

    // Method to insert a node at the end of the list
    void insert(int data) {
        Node* newNode = new Node(data);
        if (!head) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next) temp = temp->next;  // Traverse to the end
            temp->next = newNode;
        }
    }

    // Method to delete the first node of the list
    void deleteFirst() {
        if (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    // Method to display all nodes
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

    cout << "Enter the number of nodes: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter value for node " << i + 1 << ": ";
        cin >> value;
        list.insert(value);
    }

    cout << "Original Linked List:\n";
    list.display();

    cout << "\nDeleting the first node:\n";
    list.deleteFirst();
    list.display();

    return 0;
}
