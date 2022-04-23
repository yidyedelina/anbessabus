#include <iostream>
#include <string>
#include "main.h"
using namespace std;



void scheduleBus(vector<ActiveBus> activebus, Bus buses[], Route routes[])
{
    int plateNumber;
    string arriveAt;
    string departureAt;

    printHomeScreenHeader("Appoint A Bus Schedule");
    charPrinter('\n', 5);
    PLATE_NUMBER:
    charPrinter(' ', 50);
    //accepting data from the user
    cout << "Please Enter the Plate Number you want to assign the passenger:";
    cin >> plateNumber;
    cout << endl;
    Bus bus = searchBus(plateNumber, buses);
    if(bus.plateNumber == 0)
    {
        cout << "There is No bus with this plate please try again" << endl;
        goto PLATE_NUMBER;
    }
    charPrinter(' ', 50);
    cout << "Enter the time the bus arrive the station in format hour:minutes ex(08:30):";
    cin >> arriveAt;
    cout << endl;
    charPrinter(' ', 50);
    cout << "Enter the time the bus leave the station in format hour:minutes ex(08:30):";
    cin >> departureAt;
    cout << endl;

    // asssigning the values we accept from the users
    string passenger[60];
    

    Route route = searchRoute(bus.number, routes);
    ActiveBus appointBus;
    appointBus.bus = bus;
    appointBus.arrivatAt = arriveAt;
    appointBus.departureAt = departureAt;
    appointBus.route = route;
    fillSeatArray(appointBus.passenger);
    activebus.push_back(appointBus);
    charPrinter('\n', 3);
    charPrinter(' ', 50);
    cout << "The bus which has the plate number" << plateNumber << "arrive at" << arriveAt << "departure at" << departureAt << endl;
    charPrinter(' ', 50);
    cout << "Successfully Assigned" << endl;
    charPrinter('\n', 3);
    charPrinter(' ', 50);
    int choice;
    cout << "Please Enter [0] to go back to home [1] to assign a schedule again [3] to exit:" << endl;
    cin >> choice;
    if(choice == 3)
    {
        exit(1);
    }
    switch_handler(choice, activebus);
}

Bus searchBus(int plateNumber, Bus buses[])
{
    for(int i = 0; i < TOTAL_BUS; i++)
    {
        if(plateNumber == buses[i].plateNumber)
        {
            return buses[i];
        }
    }
    return buses[0];
}
Route searchRoute(int number, Route routes[])
{
    for(int i = 0; i < ROUTE_S; i++)
    {
        if(number == routes[i].number)
        {
            return routes[i];
        }
    }
    return routes[0];
}
void fillSeatArray(string passenger[])
{
    for(int i = 0; i < SEAT_S; i++)
    {
        string *p = new string(" ");
        passenger[i] = *p;
    }
}