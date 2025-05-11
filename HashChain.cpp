struct Node {
    int key;        
    Node* next;     

    Node(int k) : key(k), next(nullptr) {}  
};
class HashTable {
private:
    Node* table[TABLE_SIZE];

    int hash(int key) {
        return key % TABLE_SIZE;
    }

public:
    HashTable() {
        for (int i = 0; i < TABLE_SIZE; i++)
            table[i] = nullptr;
    }

    // Insert key into the hash table
    void insert(int key) {
        int index = hash(key);
        Node* newNode = new Node(key);
        newNode->next = table[index]; // insert at beginning (fast)
        table[index] = newNode;
    }

    // Search for a key in the hash table
    bool search(int key) {
        int index = hash(key);
        Node* curr = table[index];
        while (curr != nullptr) {
            if (curr->key == key)
                return true;
            curr = curr->next;
        }
        return false;
    }

    // Delete a key from the hash table
    void deleteKey(int key) {
        int index = hash(key);
        Node* curr = table[index];
        Node* prev = nullptr;

        while (curr != nullptr) {
            if (curr->key == key) {
                if (prev == nullptr) {
                    table[index] = curr->next;
                } else {
                    prev->next = curr->next;
                }
                delete curr;
                return;
            }
            prev = curr;
            curr = curr->next;
        }
    }

    // Display table content
    void display() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            cout << i << ": ";
            Node* curr = table[i];
            while (curr != nullptr) {
                cout << curr->key << " -> ";
                curr = curr->next;
            }
            cout << "NULL\n";
        }
    }

    // Destructor to free memory
    ~HashTable() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            Node* curr = table[i];
            while (curr != nullptr) {
                Node* temp = curr;
                curr = curr->next;
                delete temp;
            }
        }
    }
};
