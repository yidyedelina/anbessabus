#include "main.h"
#include <iostream>
#include <iomanip>
using namespace std;


void printHistoryPage(vector<ActiveBus> activebus, vector<ActiveBus> history)
{
    printHomeScreenHeader("History of Buses Leave The Station");
    if (history.empty())
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
                printHomeScreen(activebus, history);
        }
    }
    else
    {
        charPrinter(' ', 100);
        cout << "History Page" << endl;
        charPrinter('\n', 3);
        charPrinter(' ', 30);
        cout << "Plate Number";
        charPrinter(' ', 20);
        cout << "departure At";
        charPrinter(' ', 20);
        cout << "Terminal";
        charPrinter(' ', 20);
        cout << "No of Free Seat" << endl;
        for (int i = 0; i < history.size(); i++)
        {
            charPrinter(' ', 30);
            cout << "[" << i + 1 << "]";
            cout << setw(8) << left << history[i].bus.plateNumber;
            charPrinter(' ', 21);
            cout << setw(16) << left << history[i].departureAt;
            charPrinter(' ', 11);
            cout << setw(16) << left << history[i].route.end;
            charPrinter(' ', 12);
            cout << history[i].route.price;
            charPrinter(' ', 22);
            cout << calculateFreeSeat(history[i].passenger) << endl;
            cout << endl;
        }
    }

}