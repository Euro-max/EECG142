#include <iostream>
using namespace std;
const int MAX = 100;

class Queue {
private:
    int arr[MAX];
    int front;
    int rear;
public:
    Queue();
    void enqueue(int val);
    void dequeue();
    int peek();
    void display();
    void sort();
    int FinSMAX();
    void Terminate();
    void Conc(Queue&A,Queue&B);
    bool isEmpty();
    bool isFull();
};

Queue::Queue() {
    front = -1;
    rear = -1;
}

void Queue::enqueue(int val) {
    if (rear == MAX - 1) {
        cout << "Queue is full";
        
    }
    if (front == -1 && rear == -1) {
        front = 0;
        rear = 0;
    }
    else {
        rear++;
    }
    arr[rear] = val;
}

void Queue::dequeue() {
    if (front == -1 && rear == -1) {
        cout << "Queue is empty";
        return;
    }
    if (front == rear) {
        front = -1;
        rear = -1;
    }
    else {
        front++;
    }
}
bool Queue::isEmpty(){
  return (front==-1);
}
bool Queue::isFull(){
  return(rear==MAX-1);
}

int Queue::peek() {
    if (front == -1 && rear == -1) {
        return -1;
    }
    else {
        return arr[front];
    }
}

void Queue::display() {
    if (front == -1 && rear == -1) {
        cout << "Queue is empty";
    }
    else {
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
}

void Queue::sort() {
    if (front == -1 || rear == -1) return;
    
    for (int i = front; i <= rear; i++) {
        for (int j = front; j <= rear - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int Queue::FinSMAX() {
    if (front == -1 || rear == -1) return -1;
    
    int max1 = arr[front];
    int max2 = -1;
    
    for (int i = front + 1; i <= rear; i++) {
        if (arr[i] > max1) {
            max2 = max1;
            max1 = arr[i];
        }
        else if (arr[i] > max2 && arr[i] != max1) {
            max2 = arr[i];
        }
    }
    return max2;
}
void Queue::Terminate(){
  front=-1;
  rear=-1;
}
void Queue::Conc(Queue&A,Queue&B){
  while(B.isEmpty()){
    A.enqueue(B.peek());
    B.dequeue();
  }
}

int main() {
    Queue A;
    A.enqueue(3);
    A.enqueue(1);
    A.enqueue(4);
    A.enqueue(2);
    A.enqueue(4);
    
    cout << "Original queue: ";
    A.display();
    
    A.sort();
    cout << "Sorted queue: ";
    A.display();
    
    int secondMax = A.FinSMAX();
    cout << "Second maximum: " << secondMax << endl;
    
    cout << "Dequeue operations:" << endl;
    while (A.peek() != -1) {
        cout << "Front: " << A.peek() << endl;
        A.dequeue();
    }
    
    return 0;
}
