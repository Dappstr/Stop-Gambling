/*
Created by Lane Beals on 10/26/21.
Stop Gambling game
WORK IN PROGRESS
*/

#include <iostream>
#include <fstream>
#include <ctime>
#include <string>
#include <stdlib.h>
#include "intro.h"

using std::cout; using std::cin; using std::string;

struct MyCharacter
{
    static int health;
    static int bankAccount;
    
    int limbDeduction;
    int debt = 200000;
    
    static string nameInput;
};
int MyCharacter::health = 100;
int MyCharacter::bankAccount = 10000;
string MyCharacter::nameInput;



// PROTOTYPES
void getName(MyCharacter&);
void makeFile(MyCharacter &charInfo, MyCharacter &starterBank);

void inputPrompt()
{
    MyCharacter characterObject;
    
    cout << "Current health: "  << characterObject.health;
    cout << "\nMoney in the bank: " << characterObject.bankAccount;
    cout << "\nEnter \"quit\" to quit.\n";
    cout << "\n$: ";
}

int generateNumber(void)
{
    srand( static_cast<unsigned int>(time(nullptr)));
    
    int num = (rand() % 10);
    return num;
}

int main(int argc, const char * argv[])
{
    MyCharacter characterName, bankObj;
    
    getName(characterName); // Get the users name to be saved in a file.
    makeFile(characterName, bankObj); // Create initial file.
    printIntro(); // Print the intro from intro.h
    
    char introChoice = 0;
    
    while(introChoice != 'y' && introChoice != 'n')
    {
        cin >> introChoice;

        cout << "Input unrecognized. Take a breath and try again.\n";
        cout << "Choice: ";
        
        if(introChoice == 'y')
        {
            cout << "\n\nVery well. Continuing!\n\n";
            break;
        }
        else if(introChoice == 'n')
        {
            cout << "\n\nVery well. Tread lightly and watch your back.\n\n";
            return 0;
        }
        
    }
    
    int moneyGambled = 0;
    
    MyCharacter debtRef;
    cout << "Your amount of debt is at $" << debtRef.debt << "\n";
    cout << "Input the amount of money you would like to wager.\n";
    
    string gameInput;
    
        do
        {
            inputPrompt(); // First function where user explicitly enters input.
            cin >> gameInput;
            
            /*
             BUGGED CODE
            try
            {
                stoi(gameInput);
            } catch(std::invalid_argument)
            {
                cout << "\nWrong input!\n";
            }
            
            if(stoi(gameInput))
            {
                moneyGambled = stoi(gameInput);
                bankObj.bankAccount = bankObj.bankAccount - moneyGambled;
                
                cout << "\nGuess the correct number between 1 and 10.\nYou:";
                cin >> gameInput;
                
                /*if(!stoi(gameInput))
                {
                    cout << "\nWrong input!\n";
                }*/
                try
                {
                    stoi(gameInput);
                }   catch (std::invalid_argument)
                    {
                        cout << "\nWrong input!\n";
                    }
                
                if (stoi(gameInput))
                {
                    int guessedNum = stoi(gameInput);
                    int rNum = generateNumber();
                    
                    if(guessedNum == rNum)
                    {
                        bankObj.bankAccount = bankObj.bankAccount + moneyGambled*2;
                        cout << "\nWell done! You guessed correctly.\n";
                    }
                    else
                    {
                        cout << "\nUnfortunately you were wrong.";
                    }
                    
                }
                
            /*
              
              */
            /*else
            {
                
            }*/
            
            
        } while(gameInput != "quit" && gameInput != "Quit");

    /*
    MyCharacter charInfo; MyCharacter refBank;
    makeFile(charInfo, refBank);
    */
    return 0;
}


void getName(MyCharacter &characterName)
{
    cout << "Enter name: ";
    getline( cin, characterName.nameInput, '\n' );
}

void makeFile(MyCharacter &charInfo, MyCharacter &refBank)
{
    ofstream gamefile("data.txt");
    
    gamefile << charInfo.nameInput;
    gamefile << "\n$" << refBank.bankAccount;
    
    gamefile.close();
}
