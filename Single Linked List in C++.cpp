#include <iostream>
using namespace std;

class LinkedList {
private:
    struct Node {
        int val;
        Node* next;
    };
    
    Node* head;
    Node* tail;
    Node* current;
    
public:
    LinkedList();
    void insert(const int &e);
    void insert(int val, int e);
    //void insert(int pos,int e);
     int findMiddleElement(LinkedList &A);
    bool first(int &e);       // Should be non-const reference to modify e
    bool next(int &e);  
    int counter();
    void remove(const int&val);
    void reverse();
    ~LinkedList();// Should be non-const reference to modify e
};

LinkedList::LinkedList() {
    head = NULL;
    tail = nullptr;
    current = nullptr;
}

  int LinkedList::findMiddleElement(LinkedList &A){
      Node*slow=A.head;
      Node*fast=A.head;
      while(fast->next!=NULL){
          fast=fast->next->next;
          slow=slow->next;
      }
      return slow->val;
     
  }

    
    
void LinkedList::insert(int val, int e) {
    Node* newnode = new Node;
    newnode->val = e;
    newnode->next = nullptr;

    if (head == nullptr) {
        // List is empty, can't insert after specific value
        delete newnode;
        return;
    }

    Node* current = head;
    // Find the node with value 'val'
    while (current != nullptr && current->val != val) {
        current = current->next;
    }

    if (current == nullptr) {
        // Value 'val' not found in list
        delete newnode;
        return;
    }

    // Insert after 'current' node
    newnode->next = current->next;
    current->next = newnode;

    // Update tail if inserting after last node
    if (current == tail) {
        tail = newnode;
    }
}

void LinkedList::insert(const int &e) {
    Node* node = new Node;
    node->val = e;
    node->next = nullptr;
    
    if (head == nullptr) {
        head = node;
    } else {
        tail->next = node;
    }
    tail = node;
}

bool LinkedList::first(int &e) {
    if (head == nullptr) return false;
    e = head->val;
    current = head;
    return true;
}

bool LinkedList::next(int &e) {
    if (current == nullptr || current->next == nullptr) return false;
    current = current->next;
    e = current->val;  // Fixed: should be 'val' not 'elem'
    return true;
}
int LinkedList::counter(){
    Node* current=head;
    int count=0;
    while(current->next!=NULL){
        current=current->next;
        count++;
    }
    return count+1;
    
}
/*void LinkedList::insert(int pos,int&e){
    Node*node=new Node;
    node->next=NULL;
    node->val=e;
    Node*current=head;
    int i=0;
    while(current->next!=NULL&&i<pos-1){
        current=current->next;
        i++;
    }
    node->next = current->next; // New node points to successor
current->next = node;
}*/
void LinkedList::remove(const int &val) {  // Changed from delete (delete is a keyword)
        if (head == NULL) {
            return;
        }
        
        // Handle case where head needs to be deleted
        if (head->val == val) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }
        
        current = head;
        while (current->next!= NULL && current->next->val != val) {
            current = current->next;
        }
        
        if (current->next == NULL) {
            return;  // Value not found
        }
        
        Node* temp = current->next;
        current->next = temp->next;
        delete temp;
    }

/*void DoubleLinkedList::insert(const int &e){
    Node* node=new Node;
    node->info=e;
    if(head==NULL) {
        head=node;
        node->next=NULL;
    }
    Node*current=head;
    while(current->next!=NULL){
        current=current->next;
    }
    node->prev=current;
    current->next=node;
    node->next=NULL;}*/


LinkedList::~LinkedList(){
    if(head==NULL){
        return;
    }
    Node*current=head;
    while(current->next!=NULL){
       Node*next=current->next;
       delete current;
       current=next;
        
    }
    
    return;
}
void LinkedList:: reverse() {
        Node* prev = nullptr;
        Node* curr = head;
        while (curr) {
            Node* nextTemp = curr->next;  // Store next node
            curr->next = prev;            // Reverse link
            prev = curr;                  // Move pointers forward
            curr = nextTemp;
        }
        head = prev;  // Update head
    }

int main() {
    LinkedList list;
    
    // Insert some values
    list.insert(10);
    list.insert(20);
    list.insert(30);
    list.insert(50);
     list.insert(10,40);
    list.insert(50);
    list.insert(50);
    list.remove(10);
    list.insert(400);
    // Iterate through the list
    int value;
    if (list.first(value)) {
        do {
            cout << value << " ";
        } while (list.next(value));
    }
   cout<<list.findMiddleElement(list);
    cout << list.counter()<<endl;
    return 0;
}
