#include "main.h"
#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;
void eraseActiveBus(int n, vector<ActiveBus> buses, vector<ActiveBus> history);

void showactivebus(vector<ActiveBus> buses, vector<ActiveBus> history)
{
    printHomeScreenHeader("Active Buses");
    if (buses.empty())
    {
        charPrinter(' ', 30);
        cout << "There are no active buses add schedule" << endl;
        charPrinter(' ', 30);
        cout << "press any number to go back to Home:";
        int n;
        cin >> n;
        switch(n)
        {
            default:
                printHomeScreen(buses, history);
        }
    }
    else
    {
        charPrinter(' ', 100);
        cout << "Active Buses" << endl;
        charPrinter('\n', 3);
        charPrinter(' ', 30);
        cout << "Plate Number";
        charPrinter(' ', 20);
        cout << "Initial";
        charPrinter(' ', 20);
        cout << "Terminal";
        charPrinter(' ', 20);
        cout << "No of Free Seat" << endl;
        for (int i = 0; i < buses.size(); i++)
        {
            charPrinter(' ', 30);
            cout << "[" << i + 1 << "]";
            cout << setw(8) << left << buses[i].bus.plateNumber;
            charPrinter(' ', 21);
            cout << setw(16) << left << buses[i].route.from;
            charPrinter(' ', 11);
            cout << setw(16) << left << buses[i].route.end;
            charPrinter(' ', 12);
            cout << buses[i].route.price;
            charPrinter(' ', 22);
            cout << calculateFreeSeat(buses[i].passenger) << endl;
            cout << endl;
        }
        charPrinter(' ', 30);
        cout << "press [0] to go back to Home" << endl
             << endl;

        charPrinter(' ', 30);
        cout << "Which Bus are going to Leave enter the number you choose:";
        int n;
        cin >> n;
        switch (n)
        {
        case 0:
            printHomeScreen(buses, history);
        default:
            eraseActiveBus(n, buses, history);
        }
    }
}

void eraseActiveBus(int n, vector<ActiveBus> buses, vector<ActiveBus> history)
{
    history.push_back(buses[n - 1]);
    buses.erase(buses.begin() + n - 1);
    showactivebus(buses, history);
}