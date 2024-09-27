#include <string>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

// Function to create and return a new array of words from a sentence
string* createWordsArray(string sentence, int& outWordsArrSize) {
	// Initial count of words is 1 assuming sentence is not empty and has no leading/trailing spaces
	outWordsArrSize = 1;

	for (char c : sentence) {
		if (c == ' ') outWordsArrSize++;
	}

	// Allocate memory for the array of strings
	string* words = new string[outWordsArrSize];
	istringstream iss(sentence);
	string word;
	int wordIndex = 0;

	while (iss >> word) {
		words[wordIndex++] = word;
	}

	return words;
}

// Function to find missing numbers in the array
int* findMissing(int arr[], int n, int& resArrSize) {
	// Step 1: Dynamically allocate a boolean array to track presence of numbers
	bool* present = new bool[n + 1]();

	// Step 2: Mark the numbers present in arr[]
	for (int i = 0; i < n; i++) {
		if (arr[i] <= n) {
			present[arr[i]] = true;
		}
	}

	// Step 3: Count the missing numbers
	resArrSize = 0;
	for (int i = 0; i <= n; i++) {
		if (!present[i]) {
			resArrSize++;
		}
	}

	// Step 4: Allocate memory for the result array and fill it
	int* missingNumbers = new int[resArrSize];
	int index = 0;
	for (int i = 0; i <= n; i++) {
		if (!present[i]) {
			missingNumbers[index++] = i;
		}
	}

	// Free the dynamically allocated memory for the present array
	delete[] present;

	return missingNumbers;
}

void main1() {
	cout << "Please enter a sequence of positive integers, each in a separate line.\nEnd your input by typing -1." << endl;

	const int MAX_SIZE = 999; // Limitation: Maximum 999 numbers can be entered
	int numbers[MAX_SIZE];
	int num, count = 0;

	// Read the sequence of numbers
	while (cin >> num && num != -1) {
		if (count < MAX_SIZE) {
			numbers[count++] = num;
		}
		else {
			cout << "Maximum input limit reached." << endl;
			break;
		}
	}

	cout << "Please enter a number you want to search." << endl;
	int searchNum;
	cin >> searchNum;

	bool found = false;
	for (int i = 0; i < count; i++) {
		if (numbers[i] == searchNum) {
			if (!found) {
				cout << searchNum << " shows in line(s) ";
				found = true;
			}
			cout << i + 1 << ", ";
		}
	}

	if (!found) {
		cout << searchNum << " does not show at all in the sequence." << endl;
	}
	else {
		cout << "\b\b." << endl; // Replace the last comma with a period
	}
}

void main2() {
	cout << "Please enter a sequence of positive integers, each in a separate line.\nEnd your input by typing -1." << endl;
	vector<int> numbers;
	int num, searchNum;
	bool found = false;

	// Read the sequence of numbers
	while (cin >> num && num != -1) {
		numbers.push_back(num);
	}

	cout << "Please enter a number you want to search." << endl;
	cin >> searchNum;

	for (size_t i = 0; i < numbers.size(); i++) {
		if (numbers[i] == searchNum) {
			if (!found) {
				cout << searchNum << " shows in line(s) ";
				found = true;
			}
			cout << i + 1 << ", ";
		}
	}
	if (!found) {
		cout << searchNum << " does not show at all in the sequence." << endl;
	}
	else {
		cout << "\b\b." << endl; // Replace the last comma with a period
	}
}

int main() {
	// Question 1
	string sentence = "You can do it";
	int wordsArrSize = 0;
	// Call the function
	string* wordsArray = createWordsArray(sentence, wordsArrSize);

	// Print the result
	cout << "Array size: " << wordsArrSize << endl;

	for (int i = 0; i < wordsArrSize; i++) {
		cout << wordsArray[i] << endl;
	}

	// Free the allocated memory
	delete[] wordsArray;

	// Question 2
	int arr[] = { 3, 1, 3, 0, 6, 4 };
	int n = 6;
	int resArrSize = 0;
	// Call the function
	int* missingNumbers = findMissing(arr, n, resArrSize);

	// Print the result
	cout << "Missing numbers: ";

	for (int i = 0; i < resArrSize; i++) {
		cout << missingNumbers[i] << " ";
	}

	cout << endl;
	// Free the allocated memory
	delete[] missingNumbers;

	// Question 3
	// Uncomment the version you want to test
	main1(); // Version without vector
	// main2(); // Version with vector

	return 0;
}
