#include <iostream>
#include <string>
#include <limits>
#include <iomanip>

using namespace std;

const int SIZE = 3;

// user details stored in arrays
string names [SIZE] = {"john", "Mary", "Peter"};
string accountNumbers [SIZE] = {"1001", "1002", "1003"};
string pins [SIZE] = {"1111", "2222", "3333"};
double balances [SIZE] = {5000.00, 3000.00, 2000.00};

// Function to find an account
int findAccount(string account)
{
    for (int i = 0; i < SIZE; i++)
    {
        if (accountNumbers[i] == account)
        {
            return i;
        }
    }
    return -1;
}
// Function to verify PIN
bool verifyPIN(int index)
{
    string pin;
    cout<<"Enter your pin: ";
    cin>>pin;

    if (pins [index] == pin)
    {
        return true;
    }

    cout<<"Incorrect PIN!"<<endl;
    return false;
}
// Function to display menu
void displayMenu()
{
    cout<<"\n===== GCC BANK ====="<<endl;
    cout<<"1. Deposit"<<endl;
    cout<<"2. Withdraw"<<endl;
    cout<<"3. Send Cash"<<endl;
    cout<<"4. Check Balance"<<endl;
    cout<<"5. Exit"<<endl;
    cout<<"Enter choice: ";
}
// Function to deposit money
void deposit()
{
    string account;
    double amount;

    cout<<"Enter account number: ";
    cin>>account;

    int index = findAccount(account);

    if (index == -1)
    {
        cout<<"Account does not exist!"<<endl;
        return;
    }

    if (!verifyPIN(index))
        return;

    cout<<"Enter deposit amount: ";
    if (!(cin>>amount))
    {
        cout<<"Invalid amount!"<<endl;
        cin.clear();

        cin.ignore(numeric_limits<streamsize>:max(), '\n');
        return;
    }

    if (amount > 0)
    {
        balances[index] += amount;
        cout<<"Deposit successful!"<<endl;
        cout<<"New balance: R"<<balances[index]<<endl;
    }
    else
    {
        cout<<"Amount must be more than 0!"<<endl;
    }
}
// Function to withdraw money
void withdraw()
{
    string account;
    double amount;

    cout<<"Enter account number: ";
    cin>>account;

    int index = findAccount(account);

    if (index == -1)
    {
        cout<<"Account does not exist!"<<endl;
        return;
    }

    if (!verifyPIN(index))
        return;

    cout<<"Enter withdrawal amount: ";

    if (!(cin>>amount))
    {
        cout<<"Invalid amount!"<<endl;
        cin.clear();

        cin.ignore(numeric_limits<sreamsize>:max(), '\n');
        return;
    }

    if (amount <= 0)
    {
        cout<<"Amount must be more than 0!"<<endl;
    }
    else if (amount > balances[index])
    {
        cout<<"Insufficient balance!"<<endl;
    }
    else
    {
        balances[index] -= amount;
        cout<<"Withdrawal successful!"<<endl;
        cout<<"Remaining balance: R"<<balances[index]<<endl;
    }
}
// Function to send cash
void sendCash()
{
    string senderAccount,receiverAccount;
    double amount;

    cout<<"Enter your account number: ";
    cin>>senderAccount;

    int sender = findAccount(senderAccount);

    if (sender == -1)
    {
        cout<<"Sender account does not exist!"<<endl;
        return;
    }

    if (!verifyPIN(sender))
        return;

    cout<<"Enter receiver account number: ";
    cin>>receiverAccount;

    int receiver = findAccount(receiverAccount);

    if (receiver == -1)
    {
        cout<<"Receiver account does not exist!"<<endl;
        return;
    }

    if (sender == receiver)
    {
        cout<<"You cannot send cash to your own account!"<<endl;
        return;
    }

    cout<<"Enter amount to send: ";
    if (!(cin>>amount))
    {
        cout<<"Invalid amount!"<<endl;
        cin.clear();

        cin.ignore(numeric_limits<streamsize>:max(), '\n');
        return;
    }

    if (amount <= 0)
    {
        cout<<"Amount must be more than 0!"<<endl;
    }
    else if(amount > balances[sender])
    {
        cout<<"Insufficient balance!"<<endl;
    }
    else
    {
        balances[sender] -= amount;
        balances[receiver] += amount;

        cout<<"Cash sent successfully!"<<endl;
        cout<<"Your new balance: R"<<balances[sender]<<endl;
    }
}
// Function to check balance
void checkBalance()
{
    string account;

    cout<<"Enter account number: ";
    cin>>account;

    int index = findAccount(account);

    if (index == -1)
    {
        cout<<"Account does not exist!"<<endl;
        return;
    }

    if (!verifyPIN(index))
        return;

    cout<<"\nAccount holder: "<<names[index]<<endl;
    cout<<"Account number: "<<accountNumbers[index]<<endl;
    cout<<"Current balance: R"<<balances[index]<<endl;
}
// Main function


int main()
{
    int choice;

    cout<<fixed<<setprecision(2);
    do
    {
        displayMenu();

        if (!(cin >>choice))
        {
            cout<<"Invalid input! Enter a number from 1 to 5."<<endl;
            cin.clear();

            cin.ignore(numeric_limits<streamsize>:max(), '\n');
            continue;
        }
        switch (choice)
        {
        case 1:
            deposit();
            break;

        case 2:
            withdraw();
            break;

        case 3:
            sendCash();
            break;

        case 4:
            checkBalance();
            break;

        case 5:
            cout<<"Thank you for using GCC BANK!"<<endl;
            break;

        default:
            cout<<"Invalid menu choice! Try again."<<endl;
        }
    }  while (choice != 5);

    return 0;
}
