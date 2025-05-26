#include<iostream>
using namespace std;
template <class T>
class Stack{
private:
struct Node{
T data;
Node*next;
};
Node*head;
public:
Stack();
void push(const T&e);
void pop();
T top();
bool isEmpty(); //in linked list elements are non continguous so isFull() is not required unless there are memory restrictions
};
Stack<T>::Stack(){
  head=nullptr;
}
void Stack<T>::push(const T&e){
  Node*newnode=new Node;
  newnode->data=e;
  newnode->next=head;
  head=newnode;
}
void Stack<T>::pop(){
 Node*temp=head;
head=temp->next;
  delete temp;
}
bool Stack<T>::isEmpty(){
  return head==nullptr;
}
T Stack<T>::top(){
  return head->data;
}
