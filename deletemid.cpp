#include <iostream>
using namespace std;

class Node {
    int num;
    Node* next;
    
    Node(int val) : num(val), next(nullptr) {}

    friend class LinkedList;
};

class LinkedList {
    Node* head;
    Node* tail;
    int sizen;

public:
    LinkedList() : head(nullptr), tail(nullptr), sizen(0) {}

    void insert(int num) {
        Node* new_Node = new Node(num);
        if (!head) {
            head = tail = new_Node;
        } else {
            tail->next = new_Node;
            tail = new_Node;
        }
        sizen++;
    }

    void removeMiddle() {
        if (!head || !head->next) {
            delete head;
            head = nullptr;
            return;
        }

        Node *slow = head, *fast = head, *prev = nullptr;
        while (fast && fast->next) {
            fast = fast->next->next;
            prev = slow;
            slow = slow->next;
        }
        prev->next = slow->next;
        if (slow == tail) tail = prev;
        delete slow;
        sizen--;
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
    
    cout << "Enter the number of elements: ";
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        cout << "Enter value: ";
        cin >> val;
        list.insert(val);
    }

    cout << "Original list:\n";
    list.display();
    
    cout << "\nAfter removing the middle element:\n";
    list.removeMiddle();
    list.display();

    return 0;
}
