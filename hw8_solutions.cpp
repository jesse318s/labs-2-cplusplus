#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>

using namespace std;

// Question 1
int minInArray(int arr[], int arrSize) {
    int min = arr[0];
    for (int i = 1; i < arrSize; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

void question1() {
    int arr[20];
    cout << "Please enter 20 integers separated by a space:\n";
    for (int i = 0; i < 20; i++) {
        cin >> arr[i];
    }
    int min = minInArray(arr, 20);
    cout << "The minimum value is " << min << ", and it is located in the following indices: ";
    for (int i = 0; i < 20; i++) {
        if (arr[i] == min) {
            cout << i << " ";
        }
    }
    cout << "\n";
}

// Question 2
bool isPalindrome(string str) {
    int len = str.length();
    for (int i = 0; i < len / 2; i++) {
        if (str[i] != str[len - 1 - i]) {
            return false;
        }
    }
    return true;
}

void question2() {
    string word;
    cout << "Please enter a word: ";
    cin >> word;
    if (isPalindrome(word)) {
        cout << word << " is a palindrome\n";
    }
    else {
        cout << word << " is not a palindrome\n";
    }
}

// Question 3
void reverseArray(int arr[], int arrSize) {
    for (int i = 0; i < arrSize / 2; i++) {
        int temp = arr[i];
        arr[i] = arr[arrSize - 1 - i];
        arr[arrSize - 1 - i] = temp;
    }
}

void removeOdd(int arr[], int& arrSize) {
    int writeIndex = 0;
    for (int readIndex = 0; readIndex < arrSize; readIndex++) {
        if (arr[readIndex] % 2 == 0) {
            arr[writeIndex] = arr[readIndex];
            writeIndex++;
        }
    }
    arrSize = writeIndex;
}

void splitParity(int arr[], int arrSize) {
    int writeIndex = 0;
    for (int readIndex = 0; readIndex < arrSize; readIndex++) {
        if (arr[readIndex] % 2 != 0) {
            int temp = arr[writeIndex];
            arr[writeIndex] = arr[readIndex];
            arr[readIndex] = temp;
            writeIndex++;
        }
    }
}

// Question 4
void question4() {
    const int PIN = 12345;
    int map[10];
    srand(time(0));
    for (int i = 0; i < 10; i++) {
        map[i] = rand() % 3 + 1;
    }
    cout << "Please enter your PIN according to the following mapping:\nPIN: ";
    for (int i = 0; i < 10; i++) {
        cout << i << " ";
    }
    cout << "\nNUM: ";
    for (int i = 0; i < 10; i++) {
        cout << map[i] << " ";
    }
    cout << "\n";
    int enteredPIN;
    cin >> enteredPIN;
    int actualPIN = 0;
    for (int i = 0; i < 5; i++) {
        actualPIN = actualPIN * 10 + map[PIN / (int)pow(10, 4 - i) % 10];
    }
    if (enteredPIN == actualPIN) {
        cout << "Your PIN is correct\n";
    }
    else {
        cout << "Your PIN is not correct\n";
    }
}

// Question 5
void question5() {
    string firstName, middleName, lastName;
    cout << "Please enter your name (first middle last): ";
    cin >> firstName >> middleName >> lastName;
    cout << lastName << ", " << firstName << " " << middleName[0] << ".\n";
}

// Question 6
vector<string> split(const string& s, char delimiter) {
    istringstream tokenStream(s);
    string token;
    vector<string> tokens;

    while (getline(tokenStream, token, delimiter)) {
        tokens.push_back(token);
    }

    return tokens;
}

void question6() {
	string sentenceData = "";

	cout << "Please enter a sentence: ";
	getline(cin, sentenceData);

	vector<string> sentenceInfo = split(sentenceData, ' ');

	for (int i = 0; i < sentenceInfo.size(); i++) {
		if (all_of(sentenceInfo[i].begin(), sentenceInfo[i].end(), ::isdigit)) {
			for (int j = 0; j < sentenceInfo[i].length(); j++) {
				sentenceInfo[i][j] = 'x';
			}
		}
	}

	for (int i = 0; i < sentenceInfo.size(); i++) {
		cout << sentenceInfo[i] << " ";
	}
}

int main() {
    cout << "Hello World!";

    return 0;
}
