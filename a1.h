#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;
class calc
{
public:
    int counter = 0,temp = 0;                           // Useful for maintaining history of calculations
    float a, b, c, hold;                       // On time variables used for calculation
    float result[100], prevA[100], prevB[100]; //To Store the history of calculations
    char operators, prevOP[100];
    bool accept() // Inputs from user
    {
        cin >> a;
        cin >> operators;
        cin >> b;
        return true;
    }
    int operationidentify(bool input) // indentification of arithematic operation user wants to perform
    {
        if (input == true && operators != 0)
        {
            if (operators == '+')
            {
                add();
                MaintainHistory();
                continueop();
            }
            else if (operators == '-')
            {
                substract();
                MaintainHistory();
                continueop();
            }
            else if (operators == '*')
            {
                multiply();
                MaintainHistory();
                continueop();
            }
            else if (operators == '/')
            {
                division();
                MaintainHistory();
                continueop();
            }
            else if (operators == '%')
            {
                mod();
                MaintainHistory();
                continueop();
            }
            else
            {
                cout << "Could not determine the operation";
            }
        }
        else
        {
            cout << "Arithematic operation invalid...";
        }
        return 0;
    }
    int operationidentify(char operators) // indentification of arithematic operation user wants to perform
    {
        if (operators == '+')
        {
            add();
            MaintainHistory();
            continueop();
        }
        else if (operators == '-')
        {
            substract();
            MaintainHistory();
            continueop();
        }
        else if (operators == '*')
        {
            multiply();
            MaintainHistory();
            continueop();
        }
        else if (operators == '/')
        {
            division();
            MaintainHistory();
            continueop();
        }
        else if (operators == '%')
        {
            mod();
            MaintainHistory();
            continueop();
        }
        else
        {
            cout << "Could not determine the operation";
        }

        return 0;
    }
    int add()
    {
        float res = 0;
        cout << "Addition" << endl;
        res = a + b;
        hold = res;
        cout << "=" << res;
        return 0;
    }
    int substract()
    {
        float res = 0;
        cout << "Subtraction" << endl;
        res = a - b;
        hold = res;
        cout << "=" << res;
        return 0;
    }
    int multiply()
    {
        float res = 0;
        cout << "Multiplication" << endl;
        res = a * b;
        hold = res;
        cout << "=" << res;
        return 0;
    }
    int division()
    {
        float res = 0;
        cout << "Division" << endl;
        res = a / b;
        hold = res;
        cout << "=" << res;
        return 0;
    }
    int mod()
    {
        float res = 0;
        cout << "Reminder" << endl;
        res = (int)a % (int)b;
        hold = res;
        cout << "=" << res;
        return 0;
    }
    int continueop()
    {
        char operators;
        cin >> operators;
        if (operators == 'E')
        {
            cout << operators;
            exit(0);
        }
        else if (operators == 'L')
        {
            ShowMaintainHistory();
        }
        else if (operators == 'S')
        {
            StoreMaintainedHistory();
        }
        else
        {
            a = hold;
            cin >> b;
            operationidentify(operators);
        }
        return 0;
    }
    int MaintainHistory()
    {
        prevA[counter] = a;
        prevB[counter] = b;
        prevOP[counter] = operators;
        result[counter] = hold;
        counter++;
        return 0;
    }
    int ShowMaintainHistory()
    {
        cout << "Logs" << endl;
        for (int i = 0; i < counter; i++)
        {
            cout << prevA[i] << prevOP[i] << prevB[i] << "=" << result[i];
            cout << endl;
        }
        cout << "Do you want to save calculation locally";
        char choice;
        cin >> choice;
        if (choice == 'Y')
        {
            StoreMaintainedHistory();
        }
        else
        {
            cout << "Press any key to exit...";
            cin>>temp;
        }

        cin>>temp;
        return 0;
    }
    int StoreMaintainedHistory()
    {
        ofstream fout;
        time_t now = time(0);
        char *dt = ctime(&now);
        fout.open("Logs.txt", ios::app);
        fout << "---------------------------------------------------------------------------------------------------" << endl;
        fout << dt;
        fout << "---------------------------------------------------------------------------------------------------" << endl;

        for (int i = 0; i < counter; i++)
        {
            fout << prevA[i] << prevOP[i] << prevB[i] << "=" << result[i];
            fout << endl;
        }
        fout.close();
        cout << "Saved in current directory. File named 'Logs.txt'" << endl;
        cout << "Press any key to exit...";
        cin>>temp;
        return 0;
    }
};
class calcUI
{
public:
    void infoblock()
    {
        for (int i = 0; i < 97; i++)
        {
            cout << "|";
        }
        cout << endl;
        cout << "\t\t\t\tSimple calculator" << endl;
        cout << "\t\t\t\tDeveloped By Dhruv Salve" << endl;
        cout << "\t\t\t\tSailent Feature" << endl;
        cout << " 1. Goes upto 100 steps for now. \n 2. Powerpacked console calculator.\n 3. Can save calculation on a file." << endl;
        for (int i = 0; i < 97; i++)
        {
            cout << "|";
        }
        cout << endl;
    }
    void notesblock()
    {
        cout << "\t\t\t\tCommands:" << endl;
        cout << "'E' : To Exit\n'L' : To see past calcualtions in current session.\n'S' : To store past calcualtions in current session.\n\n";
        cout << "Note: * Above commands only works after atleast one calculation." << endl;
        for (int i = 0; i < 97; i++)
        {
            cout << "|";
        }
        cout << endl;
        cout << "\t\t\t\tArithematic Operator:" << endl;
        cout << "'+' : To perform addition.\n'-' : To perform substraction.\n'*' : To perform multiplication.\n'/' : To preform division\n'%' : To findout reminder" << endl;
        for (int i = 0; i < 97; i++)
        {
            cout << "|";
        }
        cout << endl;
    }
};
