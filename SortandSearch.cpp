#include<iostream>
using namespace std;
void SortArray(int arr[]) {
    int length = sizeof(arr);
    int minpos = 0;
    for (int i = 0;i < length - 1;i++) {
       int minpos = i; 
        for (int j = i + 1;j < length;j++) {
            if (arr[j] < arr[minpos]) {
                minpos = j;
            }
            if (minpos != i) {
                int temp = arr[i];
                arr[i] = arr[j]; //O(n^2) Why? It makes the first element in the array the minimum one and traverses the array(n operations), if any element while traversing is less than the first element it swaps the two and then makes the second element the minimum and traverses from i+1 to the end(n operations) so O(n*n)=O(n^2)
                arr[j] = temp;
            }
        }
    }
}

    int Binarysearch(int arra[], int item) { //O(logn)
        int low; int high;int mid;int guess;
        for (int i = 0;i < sizeof(arra);i++) {
            if (arra[i] > arra[i + 1]) SortArray(arra);
            else {
                low = 0;
                high = sizeof(arra) - 1;
                while (low <= high) {
                    mid = (low + high) / 2;
                    guess = arra[mid];
                    if (guess == item) {
                        return mid + 1;
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
    int arrt[] = { 1, 2, 3, 4,6, 7, 80, 59 };
    cout << "Your value is" <<" "<< Binarysearch(arrt, 80) << " th item";
    return 0;
}
