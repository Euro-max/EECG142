#include <iostream>
#include <cstring>
#include <cctype>
#include <stack>
using namespace std;

int main() {
    char c[] = "78+32+/";
    stack<int> Ch;
    
    for(int i = 0; i < strlen(c); i++) {
        if(isdigit(c[i])) {
            Ch.push(c[i] - '0');  // Convert char to int
        }
        else if(c[i] == '+' || c[i] == '-' || c[i] == '*' || c[i] == '/') {
            if(Ch.size() < 2) {
                cout << "Error: Not enough operands" << endl;
                return 1;
            }
            
            int b = Ch.top(); Ch.pop();
            int a = Ch.top(); Ch.pop();
            
            switch(c[i]) {
                case '+': Ch.push(a + b); break;
                case '-': Ch.push(a - b); break;
                case '*': Ch.push(a * b); break;
                case '/': Ch.push(a / b); break;
            }
        }
    }
    
    if(Ch.size() == 1) {
        cout << "Result: " << Ch.top() << endl;
    } else {
        cout << "Invalid expression" << endl;
    }
    
    return 0;
}
