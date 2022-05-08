#include "main.h"
#include <iostream>
#include "data.h"

using namespace std;

void switch_handler(int choice, vector<ActiveBus> activebus, vector<ActiveBus> history)
{
    switch (choice)
    {
    case 0:
        printHomeScreen(activebus, history);
        break;
    case 1:
        appointSeat(activebus,history);
        break;
    case 2:
        scheduleBus(activebus, buses, routes, history);
        break;
    case 3:
        showactivebus(activebus, history);
        break;
    case 4:
        printHistoryPage(activebus, history);
        break;
    default:
        exit (0);
    }
}