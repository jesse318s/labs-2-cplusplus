#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Money {
public:
	Money(long dollars = 0, int cents = 0) : allCents(dollars * 100 + cents) {}

	Money operator +(const Money& amount2) const { return Money(0, allCents + amount2.allCents); }

	Money operator -(const Money& amount2) const { return Money(0, allCents - amount2.allCents); }

	bool operator ==(const Money& amount2) const { return allCents == amount2.allCents; }

	bool operator <(const Money& amount2) const { return allCents < amount2.allCents; }

	double get_value() const { return allCents / 100.0; }

	friend istream& operator >>(istream& ins, Money& amount) {
		char dot;
		long dollars;
		int cents;

		ins >> dollars >> dot >> cents;
		amount = Money(dollars, cents);

		return ins;
	}

	friend ostream& operator <<(ostream& outs, const Money& amount) {
		outs << "$" << amount.allCents / 100 << "." << amount.allCents % 100;

		return outs;
	}

private:
	long allCents;
};

class Check {
public:
	Check(int number = 0, Money amount = Money(), bool cashed = false)
		: number(number), amount(amount), cashed(cashed) {}

	friend istream& operator >>(istream& ins, Check& check) {
		ins >> check.number >> check.amount >> check.cashed;

		return ins;
	}

	friend ostream& operator <<(ostream& outs, const Check& check) {
		outs << "Check #" << check.number << ": " << check.amount << ", Cashed: " <<
			(check.cashed ? "Yes" : "No");

		return outs;
	}

	void setNumber(int number) { this->number = number; }
	int getNumber() const { return number; }

	void setAmount(Money amount) { this->amount = amount; }
	Money getAmount() const { return amount; }

	void setCashed(bool cashed) { this->cashed = cashed; }
	bool isCashed() const { return cashed; }

private:
	int number;
	Money amount;
	bool cashed;
};

bool static compareChecks(const Check& a, const Check& b) { return a.getNumber() < b.getNumber(); }

int main() {
	vector<Check> checks;
	vector<double> deposits;
	double oldBalance = 0, newBalance = 0;
	int numChecks = 0, numDeposits = 0;
	double totalDeposits = 0, totalCashedChecks = 0, calculatedNewBalance = 0;

	// Read old and new balance
	cout << "Enter the old balance: ";
	cin >> oldBalance;
	cout << "Enter the new balance: ";
	cin >> newBalance;

	// Read checks
	cout << "Enter the number of checks: ";
	cin >> numChecks;
	checks.resize(numChecks);

	for (int i = 0; i < numChecks; ++i) {
		cout << "Enter check #" << i + 1 << " (number amount cashed[0/1]): " << endl;
		cin >> checks[i];

		if (checks[i].isCashed()) totalCashedChecks += checks[i].getAmount().get_value();
	}

	// Read deposits
	cout << "Enter the number of deposits: ";
	cin >> numDeposits;
	deposits.resize(numDeposits);

	for (int i = 0; i < numDeposits; ++i) {
		cout << "Enter deposit #" << i + 1 << ": ";
		cin >> deposits[i];
		totalDeposits += deposits[i];
	}

	// Calculate expected new balance
	calculatedNewBalance = oldBalance + totalDeposits - totalCashedChecks;
	// Output totals and difference
	cout << "Total of cashed checks: $" << totalCashedChecks << endl;
	cout << "Total of deposits: $" << totalDeposits << endl;
	cout << "Expected new balance: $" << calculatedNewBalance << endl;
	cout << "Difference from actual new balance: $" << (newBalance - calculatedNewBalance) << endl;
	// Sort checks
	sort(checks.begin(), checks.end(), compareChecks);
	// Output lists of checks
	cout << "Cashed Checks:" << endl;

	for (const auto& check : checks) {
		if (check.isCashed()) cout << check << endl;
	}

	cout << "Uncashed Checks:" << endl;

	for (const auto& check : checks) {
		if (!check.isCashed()) cout << check << endl;
	}

	return 0;
}
