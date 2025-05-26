#include<iostream>
using namespace std;
template <typename T>
template<class T>
const int Max=200;
class Queue{
private:
T arr[Max];
int f;
int r;
int nextPos(int p){
  if(p==Max-1){
    return 0;
  }
  else{
    return p+1;
  }
}
public:
Queue();
void enqueue(T&res);
T dequeue();
T peek();
bool isEmpty();
bool isFull();
};
Queue<T>::Queue(){
  f=r=0;
}
void Queue<T>::enqueue(T&res){
  assert(nextPos(r)!=f);
  r=nextPos(r);
  arr[r]=res;
}
T Queue<T>::dequeue(){
  assert(f!=r);
  f=nextPos(f);
  return arr[f];
}
bool Queue<T>::isEmpty(){
  return f==r;
}
bool Queue<T>::isFull(){
  return rear==Max-1;
}
T Queue<T>::peek(){
  assert(f!=r);
  return arr[nextPos(f)];
}
