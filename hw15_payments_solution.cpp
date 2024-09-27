#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <iomanip>

struct Node {
    std::string name;
    double paid;
    double owed;
    Node* next;

    Node(std::string n, double p) : name(n), paid(p), owed(0), next(nullptr) {}
};

class LinkedList {
public:
    LinkedList() : head(nullptr), target(0) {}

    void addNode(std::string name, double paid) {
        Node* newNode = new Node(name, paid);

        if (!head) {
            head = newNode;
        }
        else {
            Node* temp = head;

            while (temp->next) {
                temp = temp->next;
            }

            temp->next = newNode;
        }
    }

    void calculateOwedAmounts() {
        double totalPaid = 0;
        int count = 0;
        Node* temp = head;

        while (temp) {
            totalPaid += temp->paid;
            count++;
            temp = temp->next;
        }

        target = totalPaid / count;
        temp = head;

        while (temp) {
            temp->owed = target - temp->paid;
            temp = temp->next;
        }
    }

    void printInstructions() {
        Node* temp = head;
        std::vector<Node*> owesMoney;
        std::vector<Node*> isOwedMoney;

        while (temp) {
            if (temp->owed > 0) {
                owesMoney.push_back(temp);
            }
            else if (temp->owed < 0) {
                isOwedMoney.push_back(temp);
            }

            temp = temp->next;
        }

        for (auto& debtor : owesMoney) {
            for (auto& creditor : isOwedMoney) {

                if (debtor->owed == 0) break;

                double amount = std::min(debtor->owed, -creditor->owed);

                if (amount > 0) {
                    debtor->owed -= amount;
                    creditor->owed += amount;
                    std::cout << debtor->name << ", you give " << creditor->name << " $" <<
                        std::fixed << std::setprecision(2) << amount << std::endl;
                }
            }
        }

        temp = head;

        while (temp) {
            if (temp->owed == 0 && !isInTransaction(temp, owesMoney, isOwedMoney)) {
                std::cout << temp->name << ", you don't need to do anything" << std::endl;
            }

            temp = temp->next;
        }

        std::cout << "In the end, you should all have spent around $" << std::fixed <<
            std::setprecision(2) << target << std::endl;
    }

private:
    Node* head;
    double target;

    bool isInTransaction(Node* node, const std::vector<Node*>& owesMoney,
        const std::vector<Node*>& isOwedMoney) {
        for (const auto& debtor : owesMoney) {
            if (debtor == node) return true;
        }

        for (const auto& creditor : isOwedMoney) {
            if (creditor == node) return true;
        }

        return false;
    }
};

int main() {
    std::string filename;
    std::cout << "Enter the filename: ";
    std::cin >> filename;
    std::ifstream file(filename);

    if (!file) {
        std::cerr << "Error opening file" << std::endl;

        return 1;
    }

    LinkedList list;
    std::string line;

    while (std::getline(file, line)) {
        std::istringstream iss(line);
        double paid;
        std::string name;

        iss >> paid;
        std::getline(iss >> std::ws, name);
        list.addNode(name, paid);
    }

    list.calculateOwedAmounts();
    list.printInstructions();

    return 0;
}
