#include<iostream>
using namespace std;
#include<queue>
bool Deleter(queue<int> &N,int n, queue<int> &O){
    if(O.empty()){
      return false;}
    int count=1;
    while(!O.empty()){
      int element=O.front();
      O.pop();
      if(count==n){
       return true;
    }
    else{
        N.push(element);
    }
      count++;
  }
    return true;
    
  }
int main(){
  queue<int> S;
  S.push(2);
  S.push(3);
  S.push(23);
  S.push(25);
  S.push(576);
  S.push(34);
  queue<int> O;
  
  cout<<Deleter(O,4,S);
  
}
