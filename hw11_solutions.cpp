#include <iostream>

using namespace std;

// Question 1
void printTriangle(int n) {
    if (n == 0) return; // Base case
    printTriangle(n - 1); // Recursive call
    for (int i = 0; i < n; i++) {
        cout << "*";
    }
    cout << endl;
}

void printOppositeTriangles(int n) {
    if (n == 0) return; // Base case
    for (int i = 0; i < n; i++) {
        cout << "*";
    }
    cout << endl;
    printOppositeTriangles(n - 1); // Recursive call for the first triangle
    for (int i = 0; i < n; i++) {
        cout << "*";
    }
    cout << endl;
}

void printRuler(int n) {
    if (n == 0) return; // Base case
    printRuler(n - 1); // Recursive call for the upper half
    for (int i = 0; i < n; i++) {
        cout << "-";
    }
    cout << endl;
    printRuler(n - 1); // Recursive call for the lower half
}

// Question 2
int sumOfSquares(int arr[], int arrSize) {
    if (arrSize == 0) return 0; // Base case
    return arr[arrSize - 1] * arr[arrSize - 1] + sumOfSquares(arr, arrSize - 1); // Recursive call
}

bool isSorted(int arr[], int arrSize) {
    if (arrSize <= 1) return true; // Base case
    return arr[arrSize - 2] <= arr[arrSize - 1] && isSorted(arr, arrSize - 1); // Recursive call
}

// Question 3
int minInArray1(int arr[], int arrSize) {
    if (arrSize == 1) return arr[0]; // Base case
    int minRest = minInArray1(arr, arrSize - 1); // Recursive call
    return (arr[arrSize - 1] < minRest) ? arr[arrSize - 1] : minRest;
}

int minInArray2(int arr[], int low, int high) {
    if (low == high) return arr[low]; // Base case
    int mid = (low + high) / 2;
    int minLeft = minInArray2(arr, low, mid); // Recursive call for the left half
    int minRight = minInArray2(arr, mid + 1, high); // Recursive call for the right half
    return (minLeft < minRight) ? minLeft : minRight;
}

// Question 4
int jumpIt(int board[], int n, int pos = 0) {
    if (pos >= n - 1) return 0; // Base case
    int move = board[pos + 1] + jumpIt(board, n, pos + 1); // Cost of moving to the next column
    int jump = INT_MAX;
    if (pos + 2 < n) jump = board[pos + 2] + jumpIt(board, n, pos + 2); // Cost of jumping over the next column
    return min(move, jump);
}

int main() {
	cout << "Hello World!";

    return 0;
}