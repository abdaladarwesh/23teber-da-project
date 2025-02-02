#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// تعريق هيكل بيانات المستخدم
struct User {
    string name;
    long long id = 0;
    long long phone_num;
    int money;
    string password;
};
vector<User> users; // قائمة المستخدمين الديناميكية

// دالة لعرض بيانات جميع المستخدمين (للإداري فقط)
void displayAllUsers(const vector<User> &users) {
    if (users.empty()) {
        cout << "\nNo users available.\n";
        return;
    }
    cout << "\n===== All Users Data =====\n";
    for (const auto& user : users) {
        cout << "Name: " << user.name << "\n";
        cout << "ID: " << user.id << "\n";
        cout << "Phone number: " << user.phone_num << "\n";
        cout << "Balance: " << user.money << " EGP\n";
        cout << "-------------------------\n";
    }
}

// دالة لإدارة العمليات الخاصة بالمستخدم العادي
void userOperations(User& user) {
    int operation;
    do {
        cout << "\nChoose your operation:\n";
        cout << "1- Check Balance\n";
        cout << "2- Deposit\n";
        cout << "3- Withdraw\n";
        cout << "4- Transfer Money \n";
        cout << "5- Return to Main Menu\n";
        cout << "6- Exit\n";
        cout << "Enter your choice: ";
        cin >> operation;

        switch (operation) {
        case 1: 
        {
            bool con = true;
            int numsOfTrying = 3;
            while (con)
            {
                if (numsOfTrying != 0)
                {
                    string checkPassword;
                    cout << "please enter your password : ";
                    cin >> checkPassword;
                    if (checkPassword == user.password)
                    {
                        cout << "Your current balance: " << user.money << " EGP\n";
                        con = false;
                    }
                    else
                    {
                        cout << "worng password please try again\n";
                        numsOfTrying--;
                    }
                }
                else
                {
                    cout << "too Many attempts entering the wrong password , signing out.....\n";
                    return;
                }
            }

            break;
        }
        case 2: {
            int deposit;
            cout << "Enter the amount to deposit: ";
            cin >> deposit;
            user.money += deposit;
            cout << "Deposit successful! New balance: " << user.money << " EGP\n";
            break;
        }
        case 3: {
            int withdraw;
            cout << "Enter the amount to withdraw: ";
            cin >> withdraw;
            if (withdraw <= user.money) {
                bool con = true;
                int numsOfTrying = 3;
                while (con)
                {
                    if (numsOfTrying != 0)
                    {
                        string checkPassword;
                        cout << "please enter your password : ";
                        cin >> checkPassword;
                        if (checkPassword == user.password)
                        {
                            user.money -= withdraw;
                            cout << "Withdraw successful! New balance: " << user.money << " EGP\n";
                            con = false;
                        }
                        else
                        {
                            cout << "worng password please try again\n";
                            numsOfTrying--;
                        }
                    }
                    else
                    {
                        cout << "too Many attempts entering the wrong password , signing out.....\n";
                        return;
                    }
                }

            }
            else {
                cout << "Insufficient balance! you want to withdraw " << withdraw << " EGP Current balance : " << user.money << " EGP\n";
            }
            break;
        }
        case 4: {
            long long usernum;
            cout << "Enter the number you want to trnsfer to : ";
            cin >> usernum;
            auto it = find_if(users.begin(), users.end(), [&](const User u) {return usernum == u.phone_num;});
            if (it != users.end())
            {

                int amountTransfer;
                cout << "enter the amount : ";
                cin >> amountTransfer;
                if (amountTransfer <= user.money)
                {
                    int numsOfTrynig = 3;
                    bool cond = true;
                    while (cond) {
                        if (numsOfTrynig != 0) {

                            string CheckingPassword;
                            cout << "enter the password : ";
                            cin >> CheckingPassword;
                            if (CheckingPassword == user.password)
                            {
                            user.money -= amountTransfer;
                            it->money += amountTransfer;
                            cout << "transfer successful! your balance now is " << user.money << endl;
                            cond = false;
                            }
                            else {
                                cout << "wrong password please try again\n";
                                numsOfTrynig--;
                            }
                        }
                        else
                        {
                            cout << "too Many attempts entering the wrong password , signing out.....\n";
                            return;
                        }
                    }
                }
                else
                {
                    cout << "Insufficient balance ! you want to transfer " << amountTransfer << " EGP and your balance is " << user.money << " EGP" << endl;
                }
            }
            else
            {
                cout << "non exsisting user please try again";
            }
            break;
        }

        case 5:
            cout << "Returning to Main Menu...\n";
            return; // الرجوع إلى القائمة الرئيسية
        case 6:
            cout << "Exiting... Goodbye!\n";
            exit(0); // إنهاء البرنامج بالكامل
        default:
            cout << "Invalid choice! Try again.\n";
        }
    } while (operation != 5);
}

int main() {
    const long long id_admin = 123; // ID الخاص بالمدير
    const string adminPassword = "admin123"; // كلمة مرور المدير

    while (true) {
        cout << "Enter your Phone Number: ";
        long long num_guest;
        cin >> num_guest;

        if (num_guest == id_admin) {
            string password;
            cout << "Enter admin password: ";
            cin >> password;

            if (password == adminPassword) {
                cout << "\nWelcome, Administrator!\n";

                int adminChoice;
                do {
                    cout << "\n===== Admin Menu =====\n";
                    cout << "1- View All Users\n";
                    cout << "2- Return to Main Menu\n";
                    cout << "Enter your choice: ";
                    cin >> adminChoice;

                    switch (adminChoice) {
                    case 1:
                        displayAllUsers(users);
                        break;
                    case 2:
                        cout << "Returning to Main Menu...\n";
                        break; // الخروج من قائمة المدير والعودة إلى القائمة الرئيسية
                    default:
                        cout << "Invalid choice! Try again.\n";
                    }
                } while (adminChoice != 2);
            }
            else {
                cout << "Invalid password! Access denied.\n";
            }
        }
        else {
            cout << "Is this a new account or an existing account? (1- New, 2- Existing): ";
            int accountType;
            cin >> accountType;

            if (accountType == 2) {
                string password;
                cout << "Enter your password: ";
                cin >> password;

                // البحث عن المستخدم
                auto it = find_if(users.begin(), users.end(), [&](const User& user) {
                    return user.phone_num == num_guest && user.password == password;
                    });

                if (it != users.end()) {
                    // تم العثور على المستخدم
                    cout << "\nWelcome back, " << it->name << "!\n";
                    userOperations(*it);
                }
                else {
                    cout << "No matching account found! Please check your credentials.\n";
                }
            }
            else if (accountType == 1) {
                // إنشاء حساب جديد
                User newUser;
                newUser.phone_num = num_guest;
                cout << "Enter a password for your new account: ";
                cin >> newUser.password;
                newUser.money = 50; // الرصيد الافتراضي
                cout << "Enter your name: ";
                cin >> newUser.name;
                users.push_back(newUser);
                cout << "\nWelcome, " << newUser.name << "! Your account has been created.\n";
                userOperations(newUser);
            }
            else {
                cout << "Invalid choice! Returning to the main menu.\n";
            }
        }
    }

    return 0;
}

