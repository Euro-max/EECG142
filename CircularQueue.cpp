#include <iostream>
using namespace std;

const int MAX_SIZE = 5; 

class CircularQueue {
private:
    int arr[MAX_SIZE];
    int front;
    int rear;
    int count; 

public:
    CircularQueue() {
        front = -1;
        rear = -1;
        count = 0;
    }

    bool isEmpty() {
        return count == 0;
    }

    bool isFull() {
        return count == MAX_SIZE;
    }

    void enqueue(int item) {
        if (isFull()) {
            cout << "Queue is full. Cannot enqueue " << item << endl;
            return;
        }
        
        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % MAX_SIZE; 
        }
        
        arr[rear] = item;
        count++;
        cout << "Enqueued " << item << endl;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return -1;
        }
        
        int item = arr[front];
        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % MAX_SIZE; 
        }
        count--;
        cout << "Dequeued " << item << endl;
        return item;
    }

    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return -1;
        }
        return arr[front];
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }
        
        cout << "Queue: [";
        int i = front;
        do {
            cout << arr[i];
            if (i != rear) cout << ", ";
            i = (i + 1) % MAX_SIZE;
        } while (i != (rear + 1) % MAX_SIZE);
        cout << "]" << endl;
    }
};

int main() {
    CircularQueue cq;

   
    cout << "=== Enqueue Operations ===" << endl;
    cq.enqueue(10);
    cq.enqueue(20);
    cq.enqueue(30);
    cq.enqueue(40);
    cq.enqueue(50);
    cq.display(); 

    cq.enqueue(60);

    cout << "\n=== Dequeue Operations ===" << endl;
    cq.dequeue();
    cq.dequeue(); 
    cq.display(); 

    cout << "\n=== Wrapping Test ===" << endl;
    cq.enqueue(60); 
    cq.enqueue(70); 
    cq.display(); 

    cout << "\n=== Final Operations ===" << endl;
    cout << "Front element: " << cq.peek() << endl;
    
    while (!cq.isEmpty()) {
        cq.dequeue();
    }
    cq.display();

    return 0;
}
