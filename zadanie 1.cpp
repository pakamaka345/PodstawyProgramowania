#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    // Get the loan amount (X) and the number of months (M) from the user
    double X;
    int M;
    cout << "Enter the loan amount (in euros): ";
    cin >> X;
    cout << "Enter the number of months: ";
    cin >> M;

    // Calculate monthly interest rate (20% per annum)
    double monthly_interest_rate = X * 0.20; 

    // Calculate monthly installment and total loan value with interest
    double total_interest = 0;
    double total_loan_value = X/M;
    double unpaid_Capital = X;
    // Print installment for each month
    cout << "\nInstallments for each month:\n";
    cout << "Month\tInstallment\n";
    double interest = total_loan_value + monthly_interest_rate;
    cout << 1 << "\t" << fixed << setprecision(2) << interest << " euros\n";
    for (int i = 2; i <= M; i++) {
        
        unpaid_Capital -= interest;
        interest = total_loan_value + unpaid_Capital*0.20;
        total_interest += interest;
        cout << i << "\t" << fixed << setprecision(2) << interest << " euros\n";
        
    }

    // Print total loan value with interest
    cout << "\nTotal loan value with interest: " << fixed << setprecision(2) << (X + total_interest) << " euros\n";

    return 0;
}
