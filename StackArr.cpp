#include<iostream>
using namespace std;
template <class T>;
const int MAX=100;
class Stack{
private:
T Arr[MAX];
int topIndex;
public:
Stack();
void push(T &e);
void pop();
void top();
bool isEmpty();
bool isFull();
};
Stack<T>::Stack(){
int topIndex=-1;
}
Stack<T>::push(int&e){
  Arr[topIndex]=e;
  topIndex++;
}
Stack<T>::pop(){
  assert(topIndex>=0);
  return Arr[topIndex--];
}
Stack<T>::top(){
  assert(topIndex>=0);
  return Arr[topIndex];
}
bool Stack<T>::isEmpty(){
  return topIndex==-1;
}
bool Stack<T>::isFull(){
  return topIndex==MAX-1;
}
