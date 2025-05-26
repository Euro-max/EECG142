#include<iostream>
using namespace std;
template<typename T>
template<class T>
class Queue{
private:
struct Node{
T data;
Node*next;
}
Node*f;
Node*r;
public:
Queue();
void enqueue(const T&e);
void dequeue();
T peek();
};
template<class T>
Queue<T>::Queue(){
  f=nullptr;
  r=nullptr;
}
template<class T>
Queue<T>::Enqueue(const T&e){
  Node*newnode=new Node;
  newnode->data=e;
  if(r=f=nullptr){
    r=newnode;
    f=newnode;
  }
  else if(f!=nullptr){
    r->next=newnode;
    r=newnode;
  }
    
  
}
