#include <iostream>
using namespace std;

// Node structure for linked list
struct Node {
    int data;
    Node* next;
    
    Node(int val) : data(val), next(nullptr) {}
};

class LinkedListQueue {
private:
    Node* front; // Points to the front of the queue
    Node* rear;  // Points to the rear of the queue
    int size;    // Tracks number of elements

public:
    // Constructor
    LinkedListQueue() : front(nullptr), rear(nullptr), size(0) {}

    // Destructor to free memory
    ~LinkedListQueue() {
        while (!isEmpty()) {
            dequeue();
        }
    }

    // Check if queue is empty
    bool isEmpty() {
        return front == nullptr;
    }

    // Get current size of the queue
    int getSize() {
        return size;
    }

    // Add element to the rear of the queue (enqueue)
    void enqueue(int value) {
        Node* newNode = new Node(value);
        
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        size++;
        cout << "Enqueued " << value << endl;
    }

    // Remove element from the front of the queue (dequeue)
    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return -1;
        }
        
        Node* temp = front;
        int value = temp->data;
        front = front->next;
        
        if (front == nullptr) {
            rear = nullptr; // Queue is now empty
        }
        
        delete temp;
        size--;
        cout << "Dequeued " << value << endl;
        return value;
    }

    // Get front element without removing it
    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return -1;
        }
        return front->data;
    }

    // Display the queue
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }
        
        cout << "Queue (front to rear): ";
        Node* current = front;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedListQueue queue;

    // Example operations
    cout << "=== Enqueue Operations ===" << endl;
    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    queue.display();

    cout << "\n=== Dequeue Operations ===" << endl;
    queue.dequeue();
    queue.display();

    cout << "\n=== More Operations ===" << endl;
    cout << "Front element: " << queue.peek() << endl;
    cout << "Current size: " << queue.getSize() << endl;

    queue.enqueue(40);
    queue.enqueue(50);
    queue.display();

    cout << "\n=== Emptying Queue ===" << endl;
    while (!queue.isEmpty()) {
        queue.dequeue();
    }
    queue.display();

    return 0;
}
