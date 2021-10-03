Selection Sort –
Selection sort is a sorting algorithm, specifically an in-place comparison sort.
It has O(n^2) time complexity, making it inefficient on large lists.
The algorithm divides the input list into two parts: the sublist of items already sorted, which is built up from left to right at the front (left) of the list, and the sublist of items remaining to be sorted that occupy the rest of the list.
Initially, the sorted sublist is empty and the unsorted sublist is the entire input list. The algorithm proceeds by finding the smallest (or largest, depending on sorting order) element in the unsorted sublist, exchanging (swapping) it with the leftmost unsorted element (putting it in sorted order), and moving the sublist boundaries one element to the right.

C++ Program to Implement Selection Sort –

#include < iostream >
using namespace std;

void selectionSort(int arr[]) {
  for (int i = 0; i < 4; i++) {
    int min = i;

    for (int j = i + 1; j < 5; j++) {
      if (arr[j] < arr[min]) {
        min = j;
      }
    }
    if (min != i) {
      int temp = arr[min];
      arr[min] = arr[i];
      arr[i] = temp;
    }
  }
}

int main() {

  int myarr[5];
  cout << "Enter 5 integers in random order: " << endl;
  for (int i = 0; i < 5; i++) {
    cin >> myarr[i];
  }

  cout << "UNSORTED ARRAY: " << endl;
  for (int i = 0; i < 5; i++) {
    cout << myarr[i] << "  ";
  }
  cout << endl;

  selectionSort(myarr); // sorting actually happening

  cout << "SORTED ARRAY: " << endl;
  for (int i = 0; i < 5; i++) {
    cout << myarr[i] << "  ";
  }
  return 0;
}