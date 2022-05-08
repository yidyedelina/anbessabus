#include "main.h"
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;
/**
 * printHomeScreen - print the first page of the application
 * Return: nothing
 */

void printHomeScreen(vector<ActiveBus> activebus, vector<ActiveBus> history)
{
    string menu[] = {"Appoint seat", "Schedule Bus Route", "Show Active Buses", "History"};
    string welcome = "TICKET RESERVATION SYSTEM";
    int size = sizeof(menu)/sizeof(menu[0]);
    printHomeScreenHeader(welcome);
    charPrinter('\n', 4);
    charPrinter(' ', 80);
    charPrinter('*', 40);
    cout << endl;
    for(int i = 0; i < size; i++)
    {   
        charPrinter(' ', 80);
        cout << '[' << i + 1 << ']' << ' ' << menu[i] << endl;
        cout << endl;
    }
    charPrinter(' ', 80);
    charPrinter('*', 40);
    charPrinter('\n', 4);
    charPrinter(' ', 90);
    cout << '[' << size + 1 << ']' << ' ' << "Exit" << endl;
    //accepting the user it;s choice;
    int choice;
    charPrinter(' ', 70);
    cout << "Please Enter your preference:" << ' ';
    cin>>choice;
    switch_handler(choice, activebus, history);
}

void charPrinter(char c, int n)
{
    for(int i = 0; i < n; i++)
    {
        cout << c;
    }
}

/**
 * printHeader - print the header message
 * @message: the message we need to print
 * Return: nothing
 */
void printHomeScreenHeader(string message)
{
    system("clear"); ///in window cls
    charPrinter(' ', 50);
    charPrinter('*', 100);
    cout << '\n';
    charPrinter(' ', 80);
    cout << "WELCOME TO ANBESSA TICKET RESERVATION SYSTEM" << endl;
    cout << endl;
    cout << setw(112) << message << endl;
    charPrinter(' ', 50);
    charPrinter('*', 100);
    cout << '\n';
}
