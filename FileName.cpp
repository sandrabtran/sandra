// By: hussein, jehad, sandra

#include <iostream>    
#include <iomanip>     
#include <string>   

using namespace std;

void showMenu();
void checkBalance(double balance);
double deposit(double balance);
double withdraw(double balance);
void currencyExchange(double balance);
void pause();
int main() {
    string username;
    int pin;
    double balance = 1500.00;


    cout << "===== Welcome to PAU ATM =====\n";
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter PIN: ";
    cin >> pin;

    if (username != "user" || pin != 1234) {
        cout << "Access Denied. Invalid informations.\n";
        return 0;
    }


    int choice;
    do {
        showMenu();
        cin >> choice;

        switch (choice) {
        case 1:
            checkBalance(balance);
        
        case 2:
            balance = deposit(balance);
           
        case 3:
            balance = withdraw(balance);
            break;
        case 4:
            currencyExchange(balance);
            break;
        case 0:
            cout << "Thank you for using PAU ATM. Goodbye!\n";
            break;
        default:
            cout << "Invalid option. Try again.\n";
        }


        if (choice != 0) {
            pause();
        }

    } while (choice != 0);
    return 0;

}void showMenu() {
    cout << "\n=== Main Menu ===\n";
    cout << "1. Check Balance\n";
    cout << "2. Deposit Money\n";
    cout << "3. Withdraw Money\n";
    cout << "4. Currency Exchange\n";
    cout << "0. Exit\n";
    cout << "Choose an option: ";
}

void checkBalance(double balance) {
    cout << fixed << setprecision(2);
    cout << "Your current balance is: ₪" << balance << endl;
}

double deposit(double balance) {
    double amount;
    cout << "Enter amount to deposit: ₪";
    cin >> amount;

    if (amount > 0) {
        balance += amount;
        cout << "Successfully deposited ₪" << amount << ".\n";
    }
    else {
        cout << "Invalid amount.\n";
    }

    return balance;
}

double withdraw(double balance) {
    double amount;
    cout << "Enter amount to withdraw: ₪";
    cin >> amount;

    if (amount > 0 && amount <= balance) {
        balance -= amount;
        cout << "Successfully withdrew ₪" << amount << ".\n";
    }
    else {
        cout << "Invalid or insufficient balance.\n";
    }

    return balance;
}

void currencyExchange(double balance) {
    const double ILS_to_USD = 0.27;
    const double ILS_to_EUR = 0.25;
    const double ILS_to_JOD = 0.19;

    int option;
    cout << "\n--- Currency Exchange ---\n";
    cout << "Your balance: ₪" << fixed << setprecision(2) << balance << endl;
    cout << "1. Convert to USD ($)\n";
    cout << "2. Convert to EUR (€)\n";
    cout << "3. Convert to JOD (د.ا)\n";
    cout << "0. Return to Menu\n";
    cout << "Choose an option: ";
    cin >> option;

    switch (option) {
    case 1:
        cout << "USD: $" << balance * ILS_to_USD << endl;
        break;
    case 2:
        cout << "EUR: €" << balance * ILS_to_EUR << endl;
        break;
    case 3:
        cout << "JOD: د.ا" << balance * ILS_to_JOD << endl;
        break;
    case 0:
        break;
    default:
        cout << "Invalid choice.\n";
    }
}

void pause() {
    cout << "\nPress Enter to continue...";
    cin.ignore();
    cin.get();
}