// Question 1
#include <iostream>
#include <map>
#include <cctype> // And Question 2
#include <sstream>
// Question 2
#include <algorithm> // And Question 3 and Question 4
// Question 3
#include <vector>

// Question 1
void countWordsAndLetters(const std::string& line) {
	std::map<char, int> map;
	std::istringstream iss(line);
	std::string word;
	int wordCount = 0;

	while (iss >> word) {
		++wordCount;
		for (char c : word) {
			if (isalpha(c)) {
				++map[tolower(c)];
			}
		}
	}

	std::cout << wordCount << " words\n";
	// Use an iterator to go through the map
	std::map<char, int>::iterator it = map.begin();
	while (it != map.end()) {
		std::cout << "Key: " << it->first
			<< ", Value: " << it->second << "\n";
		++it;
	}
}

// Question 2
bool areAnagrams(const std::string& str1, const std::string& str2) {
	std::string s1 = str1, s2 = str2;
	s1.erase(std::remove_if(s1.begin(), s1.end(), ::isspace), s1.end());
	s2.erase(std::remove_if(s2.begin(), s2.end(), ::isspace), s2.end());

	std::transform(s1.begin(), s1.end(), s1.begin(), ::tolower);
	std::transform(s2.begin(), s2.end(), s2.begin(), ::tolower);

	std::sort(s1.begin(), s1.end());
	std::sort(s2.begin(), s2.end());

	return s1 == s2;
}

// Question 3
int* getPosNums1(int* arr, int arrSize, int& outPosArrSize) {
	std::vector<int> posNums;
	for (int i = 0; i < arrSize; ++i) {
		if (arr[i] > 0) {
			posNums.push_back(arr[i]);
		}
	}
	outPosArrSize = posNums.size();
	int* outArr = new int[outPosArrSize];
	std::copy(posNums.begin(), posNums.end(), outArr);
	return outArr;
}

int* getPosNums2(int* arr, int arrSize, int* outPosArrSizePtr) {
	std::vector<int> posNums;
	for (int i = 0; i < arrSize; ++i) {
		if (arr[i] > 0) {
			posNums.push_back(arr[i]);
		}
	}
	*outPosArrSizePtr = posNums.size();
	int* outArr = new int[*outPosArrSizePtr];
	std::copy(posNums.begin(), posNums.end(), outArr);
	return outArr;
}

void getPosNums3(int* arr, int arrSize, int*& outPosArr, int& outPosArrSize) {
	std::vector<int> posNums;
	for (int i = 0; i < arrSize; ++i) {
		if (arr[i] > 0) {
			posNums.push_back(arr[i]);
		}
	}
	outPosArrSize = posNums.size();
	outPosArr = new int[outPosArrSize];
	std::copy(posNums.begin(), posNums.end(), outPosArr);
}

void getPosNums4(int* arr, int arrSize, int** outPosArrPtr, int* outPosArrSizePtr) {
	std::vector<int> posNums;
	for (int i = 0; i < arrSize; ++i) {
		if (arr[i] > 0) {
			posNums.push_back(arr[i]);
		}
	}
	*outPosArrSizePtr = posNums.size();
	*outPosArrPtr = new int[*outPosArrSizePtr];
	std::copy(posNums.begin(), posNums.end(), *outPosArrPtr);
}

// Question 4
void oddsKeepEvensFlip(int arr[], int arrSize) {
	std::stable_partition(arr, arr + arrSize, [](int i) { return i % 2 != 0; });
	std::reverse(std::partition_point(arr, arr + arrSize, [](int i) { return i % 2 != 0; }), arr + arrSize);
}

int main()
{
	std::cout << "Hello World!";
	
	return 0;
}
