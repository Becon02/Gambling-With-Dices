#include <string>
#include <iostream>
#include <time.h>
#include <chrono>
#include <thread>
#include <stdlib.h>


using namespace std;
using namespace this_thread;
using namespace chrono;

void SpaceLine();
void ExplainingRules();
void Gambling(int x, int y, int z);
void TimeDelay(int time);

int main()
{
    srand(time(NULL));

    bool Playing = true;
    string Answer;

    ExplainingRules();

    TimeDelay(100);
    
    while (Playing == true)
    {
        Gambling(rand() % 3 + 1, rand() % 3 + 1, rand() % 3 + 1);
        
        TimeDelay(100);

        cout << "\nDo you want to play again ? " << ("\x1B[32mYes\033[0m") << "/" << ("\x1B[31mNo\033[0m") << endl;
        cin >> Answer;

        if (Answer == "Yes")
        {
            Playing = true;
        }   
        else if (Answer == "No")
        {
            cout << "See you next time!";
            Playing = false;
            SpaceLine();
        }
        else
        {
            cout << "Make sure you type it correctly." << endl;
            SpaceLine();
        }

    }

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

        cout << "In order to hit the " << ("\x1B[32mJackpot\033[0m") << " you need to get in all the rolls the same number." << endl;
        TimeDelay(50);

        cout << "If you get different numbers you lose." << endl;

        SpaceLine();
        
        TimeDelay(100);

        cout << "\nDo you understand the rules ? " << ("\x1B[32mYes\033[0m") << "/" << ("\x1B[31mNo\033[0m") << endl;
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
        cout << "\n" << ("\x1B[32mJackpot\033[0m") << endl;
        SpaceLine();
        exit(0);
    }
    else
    {
        SpaceLine();
        cout << "\n" << ("\x1B[31mGood luck next time\033[0m") << endl;
    }

    SpaceLine();
}

void TimeDelay(int time)
{
    sleep_for(nanoseconds(time));
    sleep_until(system_clock::now() + seconds(1));
}