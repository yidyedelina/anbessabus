#include "main.h"
#include <iostream>
#include "data.h"

using namespace std;


void switch_handler(int choice, vector<ActiveBus> activebus)
{
    switch (choice)
    {
    case 0:
        printHomeScreen(activebus);
        break;
    case 1:
        appointSeat(activebus);
        break;
    case 2:
        scheduleBus(activebus, buses, routes);
        break;
    default:
        cout << "under construction (:" << endl;
    }
}