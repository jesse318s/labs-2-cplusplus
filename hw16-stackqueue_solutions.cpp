#include <iostream>
#include <fstream>
#include <stack>
#include <string>
#include <unordered_map>

bool isMatchingPair(char open, char close) {
    std::unordered_map<char, char> matchingPairs = {
        {'{', '}'},
        {'(', ')'},
        {'[', ']'}
    };

    return matchingPairs[open] == close;
}

bool isSymbolBalanced(std::ifstream& file) {
    std::stack<char> symbols;
    std::string word;
    bool inBeginEndBlock = false;

    while (file >> word) {
        if (word == "begin") {
            inBeginEndBlock = true;
        }
        else if (word == "end") {
            if (!symbols.empty()) return false;

            inBeginEndBlock = false;
        }
        else if (inBeginEndBlock) {
            for (char ch : word) {
                if (ch == '{' || ch == '(' || ch == '[') {
                    symbols.push(ch);
                }
                else if (ch == '}' || ch == ')' || ch == ']') {
                    if (symbols.empty() || !isMatchingPair(symbols.top(), ch)) return false;

                    symbols.pop();
                }
            }
        }
    }

    return symbols.empty();
}

int main() {
    std::ifstream file("example.pas");

    if (!file.is_open()) {
        std::cerr << "Failed to open file." << std::endl;

        return 1;
    }

    if (isSymbolBalanced(file)) std::cout << "Symbols are balanced." << std::endl;
    else std::cout << "Symbols are not balanced." << std::endl;

    file.close();

    return 0;
}


#include <iostream>
#include <vector>
#include <stdexcept>

template <typename T>
class VectorQueue {
private:
    std::vector<T> data;
    size_t start;

public:
    VectorQueue() : start(0) {}

    void push(const T& value) { data.push_back(value); }

    void pop() {
        if (empty()) throw std::out_of_range("Queue is empty");

        start++;

        if (start == data.size()) {
            data.clear();
            start = 0;
        }
    }

    T& front() {
        if (empty()) throw std::out_of_range("Queue is empty");

        return data[start];
    }

    bool empty() const { return start == data.size(); }

    size_t size() const { return data.size() - start; }
};

int main() {
	VectorQueue<int> queue;

	queue.push(1);
	queue.push(2);
	queue.push(3);

	while (!queue.empty()) {
		std::cout << queue.front() << std::endl;
		queue.pop();
	}

	return 0;
}
