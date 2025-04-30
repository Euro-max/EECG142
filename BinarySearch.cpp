#include<iostream>
using namespace std;
int Binarysearch(int arra[], int item) {
    int low; int high;int mid;int guess;
    for (int i = 0;i < sizeof(arra);i++) {
        if (arra[i] > arra[i + 1]) return -1;
        else {
            low = 0;
            high = sizeof(arra) - 1;
            while (low <= high) {
                mid = (low + high) / 2;
                guess = arra[mid];
                if (guess == item) {
                    return mid+1;
                }
                if (guess > item) {
                    high = mid - 1;
                }
                if (guess < item) {
                    low = mid + 1;
                }
            }
        }
        return NULL;
    }

}
int main() {
    int arrt[] = { 1, 2, 3, 4,6, 7, 8, 59 };
    cout << "Your value is" <<" "<< Binarysearch(arrt, 3) << " th item";
    return 0;
}
