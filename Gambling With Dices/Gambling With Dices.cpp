#include <string>
#include <iostream>
#include <time.h>
#include <chrono>
#include <thread>
#include <windows.h>


using namespace std;
using namespace this_thread;
using namespace chrono;

void SpaceLine();
void ExplainingRules();
void Gambling(int x, int y, int z);
void TimeDelay(int time);
void Color(int typeColor);
void YesNoColored();
void MainCode();

int main()
{
    HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
    
    SetConsoleTextAttribute(color, 7);
    srand(time(NULL));

    MainCode();
}

void SpaceLine()
{
    cout << "---------------------------------------------------------------\n";
}

void ExplainingRules()
{
    SpaceLine();

    bool understandRules = false;
    string Answer;
    bool TypeCorrectly;
    
    cout << "Welcome player to the gambling game.\n" << endl;

    TimeDelay(10);
    while (understandRules == false)
    {
        TypeCorrectly = false;

        cout << "We will roll a dice of 6 a number of 3 times." << endl;
        TimeDelay(50);

        cout << "In order to hit the "; 
        
        //Color for JackPot
        Color(10);
        cout << "JackPot";
        Color(7);

        cout << " you need to get in all the rolls the same number." << endl;
        TimeDelay(50);

        cout << "If you get different numbers you lose." << endl;

        SpaceLine();
        
        TimeDelay(100);
        
        while (TypeCorrectly == false)
        {
            cout << "Do you understand the rules ? ";
            YesNoColored();

            cin >> Answer;

            if (Answer == "Yes")
            {
                system("CLS");

                SpaceLine();

                cout << "Perfect then lets start playing !!" << endl;
                understandRules = true;
                TypeCorrectly = true;
            }
            else if (Answer == "No")
            {
                SpaceLine();
                understandRules = false;
                TypeCorrectly = true;
            }
            else
            {
                system("CLS");
                cout << "Make sure you type it correctly." << endl;
                SpaceLine();
            }
        }
    }

    SpaceLine();

}

void Gambling(int x, int y, int z)
{
    HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);

    for (int i = 0; i < 3; i++)
    {
        TimeDelay(100);

        switch (i)
        {
        case 0:
        {
            cout << "Roll " << i + 1 << " is: " << x << endl;
            break;
        }
        case 1:
        {
            cout << "\nRoll " << i + 1 << " is: " << y << endl;
            break;
        }
        case 2:
        {
            cout << "\nRoll " << i + 1 << " is: " << z << endl;
            break;
        }
        default:
            break;
        }
    }

    TimeDelay(10);

    if (x == y && x == z)
    {
        SpaceLine();
        
        Color(10);
        cout << "JackPot !!" << endl;
        Color(7);
    }
    else
    {
        SpaceLine();
       
        Color(4);
        cout << "Good luck next time." << endl;
        Color(7);
    }

    SpaceLine();
}

void TimeDelay(int time)
{
    sleep_for(nanoseconds(time));
    sleep_until(system_clock::now() + seconds(1));
}

void Color(int typeColor)
{
    HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(color, typeColor);
}

void YesNoColored()
{
    Color(10);

    cout << "Yes";
    Color(7);

    cout << "/";
    Color(4);

    cout << "No" << endl;
    Color(7);
}

void MainCode()
{
    bool Playing = true;
    string Answer;

    ExplainingRules();

    TimeDelay(100);

    while (Playing == true)
    {
        bool CorrectAnswer = false;

        Gambling(rand() % 6 + 1, rand() % 6 + 1, rand() % 6 + 1);

        TimeDelay(100);

        while (CorrectAnswer == false)
        {
            cout << "Do you want to play again ? ";
            YesNoColored();

            cin >> Answer;

            if (Answer == "Yes")
            {
                system("CLS");

                CorrectAnswer = true;
                Playing = true;

                SpaceLine();
            }
            else if (Answer == "No")
            {
                cout << "See you next time!" << endl;
                Playing = false;
                CorrectAnswer = true;
                SpaceLine();
            }
            else
            {
                CorrectAnswer = false;
                cout << "Make sure you type it correctly." << endl;
                SpaceLine();
            }
        }
    }
}