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
    cout << "---------------------------------------------------------------";
}

void ExplainingRules()
{
    SpaceLine();

    bool understandRules = false;
    string Answer;
    
    cout << "\nWelcome player to the gambling game.\n" << endl;

    TimeDelay(10);
    while (understandRules == false)
    {
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

        cout << "\nDo you understand the rules ? ";
        YesNoColored();

        cin >> Answer;

        if (Answer == "Yes")
        {
            cout << "Perfect then lets start playing !!" << endl;
            understandRules = true;
        }
        else if (Answer == "No")
        {
            SpaceLine();
            understandRules = false;
        }
        else
        {
            cout << "Make sure you type it correctly." << endl;
            SpaceLine();
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
            cout << "\nRoll " << i + 1 << " is: " << x << endl;
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
        cout << "\nJackPot !!" << endl;
        Color(7);
    }
    else
    {
        SpaceLine();
       
        Color(4);
        cout << "\nGood luck next time." << endl;
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
            cout << "\nDo you want to play again ? ";
            YesNoColored();

            cin >> Answer;

            if (Answer == "Yes")
            {
                CorrectAnswer = true;
                Playing = true;
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