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
            charPrinter(' ', 21);
            cout << setw(16) << left << history[i].route.end;
            charPrinter(' ', 22);
            cout << calculateFreeSeat(history[i].passenger) << endl;
            cout << endl;
        }
        int c;
        marker:
        charPrinter(' ', 30);
        cout << "Please enter your choice or [0] to go back home:";
        cin>>c;
        if(c == 0)
        {
            printHomeScreen(activebus, history);
        }
        else
        {
            string *passenger = history[c - 1].passenger;
            for(int i = 0; i < SEAT_S; i++)
            {
                charPrinter(' ', 30);
                cout << "["  << setw(2) << right <<i + 1 << "]" << ' ';
                if(passenger[i].compare(" ") == 0)
                {
                    cout << setw(20) << left << "Empty Seat";
                }
                else
                {
                    cout << setw(20) << left << passenger[i];
                }
                if( (i + 1) % 3 == 0)
                {
                    cout << '\n';
                }

            }
            
        }
        goto marker;
    }

}