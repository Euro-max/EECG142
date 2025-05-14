#include <iostream>
using namespace std;
#include <stack>
int main() {
 stack<int> Bin;
 int i;
 cout<<"Enter the number you wish";
 cin>>i;
 while(i!=0){
     Bin.push(i%2);
     i=i/2;
 }
 while(!Bin.empty()){
     cout<<Bin.top();
     Bin.pop();
 }

}
