//  intro.h
//  Stop Gambling

#include <iostream>

using namespace std;

void printIntro(void)
{
    cout << "\n\t\t------------------------------\n";
    cout << "\t\t\tSTOP GAMBLING!\n";
    cout << "\t\t------------------------------\n\n";
    
    cout << "The rules are simple. You've been given a chance to repay all your debt."
         << "\nTen thousand dollars has generously been given to you by those above."
         << "\nYou're able to gamble as you wish, and if you get low on funds, you may choose to sell one of your limbs."
         << "\nEach different limb has a specified amount of value. If you lose too many limbs, your health will go down and you die."
         << "\nIf you lose all your funds, you're dead. Are you willing to take a high risk chance?\n\n"
         << "Choice (y/n): ";
}
