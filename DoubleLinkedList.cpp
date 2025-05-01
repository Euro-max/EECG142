// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
class DoubleLinkedList{
    private:
    struct Node{
        int val;
        Node*next;
        Node*prev;
    };
    Node*head;
    Node*current;
    Node*tail;
    public:
    DoubleLinkedList();
    void insertatEnd(const int&e);
    void insertatIndex(int val,int index);
    void insertAfter(int val, int index);
    void deleteNode(const int &e);
    void deleteatIndex(int index);
    bool isEmpty(DoubleLinkedList &A);
    void display();
    bool search(int &e);
    void reverse();
    void deleteAll();
   
};
DoubleLinkedList::DoubleLinkedList(){
    tail=NULL;
    head=NULL;
    current=NULL;
}
void DoubleLinkedList::insertatEnd(const int &e){
    Node*node=new Node;
    node->val=e;
        node->next = nullptr;  // Crucial initialization
    if(head==NULL) {
    head=node;
    node->prev=NULL;
    node->next=NULL;
    }
    else{
        Node*current=head;
        while(current->next!=NULL){
            current=current->next;
        }
        node->prev=current;
        node->prev=current;
        current->next=node;
        
       

    }
}

void DoubleLinkedList:: insertAfter(int val,int index){
    Node*node=new Node;
    node->val=val;
    Node*current=head;
    int i=0;
    while(current->next!=NULL&&i<index-1){
        current=current->next;
        i++;
    }
    node->prev=current;
    node->next=current->next;
    current->next->prev=node;
    current->next = node;
}
void DoubleLinkedList::reverse() {
    Node* current = head;
    Node* temp = nullptr;
    
    // First pass: swap next/prev pointers
    while (current != nullptr) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;  // Move to next node using prev (since we swapped)
    }
    
    // Update head and tail
    if (temp != nullptr) {
        tail = head;
        head = temp->prev;
    }
}
 void DoubleLinkedList:: deleteNode(const int &e){
     Node*current=head;
     while(current!=NULL&&current->val!=e){
         current=current->next;
     }
     if(current==NULL){
         cout<<"The value is not found";
     }
     else{
         Node*temp=current;
         current->prev->next=current->next;
         delete temp;
     }
 }
void DoubleLinkedList::display(){
    if(head==NULL){
        cout<<"lIST IS EMPTY";
    }
    else{
        Node*current=head;
        while(current!=nullptr){
            cout<<current->val;
            current=current->next;
        }
    }
}
bool DoubleLinkedList::isEmpty(DoubleLinkedList &A){
    return(head==NULL);
    
}
void DoubleLinkedList::insertatIndex(int val, int index){
    Node*node=new Node;
    node->val=val;
    Node*current=head;
    int i=0;
    while(current->next!=NULL&&i<index){
        current=current->next;
        i++;
    }
    node->next = current->next;  // First point new node to next node
if (current->next != nullptr) {
    current->next->prev = node;  // Update next node's prev
}
current->next = node;  // Then update current's next
node->prev = current;
}
void DoubleLinkedList::deleteAll(){
    Node*current=head;
    while(current!=NULL){
        Node*temp=current;
        current=current->next;
        delete temp;
    }
    head=NULL;
}
int main() {
    DoubleLinkedList A;
    A.insertatEnd(2);
    A.insertatEnd(416);
    A.insertatEnd(345);
    A.deleteNode(345);
    A.display();
    A.reverse();
    A.display();
    A.deleteAll();
    A.display();

    return 0;
}
