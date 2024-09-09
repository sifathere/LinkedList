#include <iostream>
using namespace std;

class LinkedList {
private:
    struct Node {
        int num;
        Node* next;
        Node(int n, Node* nxt = nullptr) : num(n), next(nxt) {}
    };

    Node* head;

public:
    LinkedList() : head(nullptr) {}

    void insertNode(int n) {
        head = new Node(n, head);
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
    int n, value;

    cout << "Enter the number of nodes to insert: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter value for node " << i + 1 << ": ";
        cin >> value;
        list.insertNode(value);
    }

    cout << "\nLinked List after insertion:\n";
    list.display();

    cout << "\nInsert a new node at the beginning:\n";
    cout << "Enter value for the new node: ";
    cin >> value;
    list.insertNode(value);

    cout << "\nLinked List after inserting new node:\n";
    list.display();

    return 0;
}
