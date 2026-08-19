#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cmath>
#include <iomanip>
using namespace std;

struct Payment {
	int month;
	double payment;
	double interest;
	double principal;
	double balance;
};

class Loan {
private: 
	double principal;
	double annualRate;
	int years;

	vector<Payment> schedule;
public:
	Loan(double p, double r, int y);

	double calculateMonthlyPayment();
	void buildSchedule();
	void printSchedule();
	void writeCSV(string filename);
};

int main(void) {
	double amount, rate;
	int years;

	cout << "*---* Loan Amortization Schedule Calculator *---*\n" << endl;

	cout << "Loan amount: ";
	cin >> amount;

	cout << "APR (%): ";
	cin >> rate;

	cout << "Years (3, 5, 7): ";
	cin >> years;

	cout << "\n*-----------* Your Payment Schedule *-----------*" << endl;

	Loan loan(amount, rate, years);

	loan.buildSchedule();

	loan.printSchedule();

	char save;
	cout << "\nSave to CSV? (y/n): ";
	cin >> save;

	if (save == 'y' || save == 'Y') {
		loan.writeCSV("loan-schedule.csv");
	}

	return (0);
}

Loan::Loan(double p, double r, int y){
	principal = p;
	annualRate = r;
	years = y;
}

double Loan::calculateMonthlyPayment() {
	double monthlyRate = (annualRate / 100.00) / 12.00;
	int totalPayments = years * 12;

	double numerator = principal * monthlyRate * pow(1 + monthlyRate, totalPayments);
	double denominator = pow(1 + monthlyRate, totalPayments) - 1;

	return numerator / denominator;
}
void Loan::buildSchedule() {
	schedule.clear();

	double balance = principal;
	double monthlyPayment = calculateMonthlyPayment();
	double monthlyRate = (annualRate / 100.00) / 12.00;
	double totalInterest = 0.0;
	int n = years * 12;

	for (int i = 1; i <= n; i++) {
		Payment p;

		double interest = balance * monthlyRate;
		double principalPaid = monthlyPayment - interest;

		if (principalPaid > balance) {
			principalPaid = balance;
			interest = balance * monthlyRate;
		}

		balance -= principalPaid;

		p.month = i;
		p.payment = monthlyPayment;
		p.interest = interest;
		p.principal = principalPaid;
		p.balance = balance;

		schedule.push_back(p);
		totalInterest += interest;
	}
	cout << "\nTotal interest paid: $" << totalInterest << endl;
 }

void Loan::printSchedule() {
	cout << fixed << setprecision(2);
	cout << "\nMonth | Payment | Interest | Principal | Balance\n";
	cout << "-------------------------------------------------\n";
	for (int i = 0; i < schedule.size(); i++) {
		cout << schedule[i].month << "  | $" << schedule[i].payment << "  | $" << schedule[i].interest << "  | $" 
			 << schedule[i].principal << "  | $" << schedule[i].balance << endl;
	}
}

void Loan::writeCSV(string filename) {
	ofstream file(filename);

	file << "Month,Payment,Interest,Principal,Balance\n";

	file << fixed << setprecision(2);
	for (int i = 0; i < schedule.size(); i++) {
		file << schedule[i].month << "," << schedule[i].payment << "," << schedule[i].interest << ","
			<< schedule[i].principal << "," << schedule[i].balance << "\n";
	}

	file.close();
}