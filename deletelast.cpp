#include <iostream>
using namespace std;

class Node {
public:
    int num;
    Node* next;
    Node(int val) : num(val), next(nullptr) {}
};

class LinkedList {
    Node* head;
    
public:
    LinkedList() : head(nullptr) {}

    void insert(int num) {
        Node* new_Node = new Node(num);
        if (!head) {
            head = new_Node;
        } else {
            Node* temp = head;
            while (temp->next) temp = temp->next;
            temp->next = new_Node;
        }
    }

    void deleteLast() {
        if (!head) return;
        if (!head->next) {
            delete head;
            head = nullptr;
            return;
        }
        Node* temp = head;
        while (temp->next->next) temp = temp->next;
        delete temp->next;
        temp->next = nullptr;
    }

    void display() const {
        Node* temp = head;
        while (temp) {
            cout << temp->num << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList list;
    int n, val;

    cout << "Enter number of elements: ";
    cin >> n;
    
    for (int i = 0; i < n; ++i) {
        cout << "Enter value: ";
        cin >> val;
        list.insert(val);
    }

    cout << "Original list:\n";
    list.display();

    cout << "\nRemove the last node once:\n";
    list.deleteLast();
    list.display();

    return 0;
}
