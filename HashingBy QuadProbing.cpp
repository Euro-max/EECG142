#include <iostream>
using namespace std;

static const int MAXSIZE = 21;

class HT {
private:
    int arr[MAXSIZE];
    int Empty = -1;
    int Deleted = -2;

    int hash(int key) {
        return key % MAXSIZE;
    }

public:
    HT();
    bool search(int key);
    void insert(int key);
    void deleter(int key);
    void display();  // For testing
};

// Constructor: initialize all slots as Empty
HT::HT() {
    for (int i = 0; i < MAXSIZE; i++) {
        arr[i] = Empty;
    }
}

// Search for a key
bool HT::search(int key) {
    int pos = hash(key);
    int i = 0;

    while (arr[(pos + i * i) % MAXSIZE] != Empty) {
        int idx = (pos + i * i) % MAXSIZE;
        if (arr[idx] == key)
            return true;
        i++;
        if (i == MAXSIZE)
            return false;
    }
    return false;
}

// Insert a key
void HT::insert(int key) {
    int pos = hash(key);
    int i = 0;

    while (arr[(pos + i * i) % MAXSIZE] != Empty && arr[(pos + i * i) % MAXSIZE] != Deleted) {
        i++;
        if (i == MAXSIZE) {
            cout << "Table is full, cannot insert " << key << endl;
            return;
        }
    }

    arr[(pos + i * i) % MAXSIZE] = key;
}

// Delete a key
void HT::deleter(int key) {
    int pos = hash(key);
    int i = 0;

    while (arr[(pos + i * i) % MAXSIZE] != Empty) {
        int idx = (pos + i * i) % MAXSIZE;
        if (arr[idx] == key) {
            arr[idx] = Deleted;
            return;
        }
        i++;
        if (i == MAXSIZE) {
            cout << "Key not found\n";
            return;
        }
    }
    cout << "Key not found\n";
}

// Display table for testing
void HT::display() {
    for (int i = 0; i < MAXSIZE; i++) {
        if (arr[i] == Empty)
            cout << i << ": EMPTY" << endl;
        else if (arr[i] == Deleted)
            cout << i << ": DELETED" << endl;
        else
            cout << i << ": " << arr[i] << endl;
    }
}

int main() {
    HT ht;

    ht.insert(10);
    ht.insert(21);
    ht.insert(32); // causes collision, uses quadratic probing
    ht.insert(43);
    ht.insert(5);

    ht.display();

    cout << "\nSearching for 21: " << (ht.search(21) ? "Found" : "Not Found") << endl;
    cout << "Searching for 99: " << (ht.search(99) ? "Found" : "Not Found") << endl;

    ht.deleter(21);
    cout << "\nAfter deleting 21:\n";
    ht.display();

    return 0;
}
