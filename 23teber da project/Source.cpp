#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// تعريف هيكل بيانات المستخدم
struct User {
    string first_name;
    string last_name;
    long long id = 0;
    string phone_num;
    int money;
    string password;
};
vector<User> users; // قائمة المستخدمين الديناميكية

// دالة لإدارة العمليات الخاصة بالمستخدم العادي
void userOperations(User& user)
{
    int operation;
    do {
        cout << "\nChoose your operation:\n";
        cout << "1- Check Balance\n";
        cout << "2- Deposit\n";
        cout << "3- Withdraw\n";
        cout << "4- Transfer Money \n";
        cout << "5- Change password \n";
        cout << "6- Show profile \n";
        cout << "7- Return to Main Menu\n";
        cout << "8- Exit\n";
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
                        cout << "worng password you have " << numsOfTrying << " attempts to enter the right password befor signing out please try again\n";
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
                    int deposit;
                    cout << "Enter the amount to deposit: ";
                    cin >> deposit;
                    user.money += deposit;
                    cout << "Deposit successful! New balance: " << user.money << " EGP\n";
                    con = false;
                }
                else
                {
                    cout << "worng password please try again\n";
                    numsOfTrying--;
                    cout << "worng password you have " << numsOfTrying << " attempts to enter the right password befor signing out please try again\n";
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
                            cout << "worng password you have " << numsOfTrying << " attempts to enter the right password befor signing out please try again\n";
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
            string usernum;
            cout << "Enter the number you want to transfer to : ";
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
                                cout << "worng password you have " << numsOfTrynig << " attempts to enter the right password befor signing out please try again\n";
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
                    break;
                }
            }
            else
            {
                cout << "non existing user please try again";
            }
            break;
        }
        case 5:
        {
            bool con = true;
            int numsOfTrying = 3;
            while (con)
            {
                if (numsOfTrying != 0)
                {
                    string checkPassword;
                    cout << "Please enter your current password: ";
                    cin >> checkPassword;
                    if (checkPassword == user.password)
                    {
                        string newPassword;
                        cout << "Enter your new password: ";
                        cin >> newPassword;
                        user.password = newPassword; // Update password
                        cout << "Password changed successfully!\n";
                        con = false;
                        return userOperations(user);
                    }
                    else
                    {
                        cout << "Wrong password! Please try again.\n";
                        numsOfTrying--;
                        cout << "You have " << numsOfTrying << " attempts remaining before signing out.\n";
                    }
                }
                else
                {
                    cout << "Too many incorrect attempts. Signing out...\n";
                    return;
                }
            }
            break;
        }
        case 6:
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
                        while (true)
                        {

                        int choice;
                        cout << "=========== " << user.first_name << " " << user.last_name << " profile ===========\n";
                        cout << "The full name " << user.first_name << " " << user.last_name << endl;
                        cout << "The phone number " << user.phone_num << endl;
                        cout << "The balance " << user.money << endl;
                        cout << "The password " << user.password << endl;
                        cout << "1- Return to main menu \n";
                        cout << "enter your choice : ";
                        cin >> choice;
                        if (choice == 1)
                        {
                            return userOperations(user);
                        }
                        else {
                            cout << "incorrect operation!\n";
                        }
                    }
                        con = false;
                        }
                    else
                    {
                        cout << "worng password please try again\n";
                        numsOfTrying--;
                        cout << "worng password you have " << numsOfTrying << " attempts to enter the right password befor signing out please try again\n";
                    }
                }
                else
                {
                    cout << "too Many attempts entering the wrong password , signing out.....\n";
                    return;
                }
            }

        }


        case 7:
            cout << "Returning to Main Menu...\n";
            return; // الرجوع إلى القائمة الرئيسية
        case 8:
            cout << "Exiting... Goodbye!\n";
            exit(0); // إنهاء البرنامج بالكامل
        default:
            cout << "Invalid choice! Try again.\n";
        }
    } while (operation != 5);
}

int main() {
    while (true) {
        string num_guest;
        bool validPhoneNumber = false;
        while (!validPhoneNumber) {
            cout << "Enter your Phone Number (must be 11 digits): ";
            cin >> num_guest;
            if (num_guest.length() == 11) {
                validPhoneNumber = true;
            }
            else {
                if (num_guest.length() > 11)
                {
                    cout << "Invalid phone number! The number is more than 11 digits Please enter exactly 11 digits.\n";
                }
                else if (num_guest.length() < 11)
                {
                    cout << "Invalid phone number! The number is less than 11 digits Please enter exactly 11 digits.\n";
                }
            }
        }

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
                cout << "\nWelcome back, " << it->first_name << "!\n";
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
            newUser.money = 0; // الرصيد الافتراضي
            cout << "Enter your first name: ";
            cin >> newUser.first_name;
            cout << "Enter your last name: ";
            cin >> newUser.last_name;
            users.push_back(newUser);
            cout << "\nWelcome, " << newUser.first_name + " " + newUser.last_name << "! Your account has been created.\n";
            userOperations(newUser);
        }
        else {
            cout << "Invalid choice! Returning to the main menu.\n";
        }
    }

    return 0;
}