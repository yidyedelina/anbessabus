#include "main.h"
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;
int calculateFreeSeat(string passenger[]);
void assignSeat(int i, ActiveBus bus, string message);
void appointSeatPageHeader(ActiveBus bus);
/**
 * @brief allow us to assign a given to assign a seat from active buses
 * 
 * @param buses active buses
 */
void appointSeat(vector<ActiveBus> buses)
{
    printHomeScreenHeader("Assign Seat For a Passenger");
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
    cout << "Price";
    charPrinter(' ', 20);
    cout << "No of Free Seat" << endl;
    for(int i = 0; i < buses.size(); i++)
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
    int i;
    charPrinter(' ', 30);
    cout << "Please enter your choice:";
    cin>>i;
    assignSeat(i, buses[i - 1], "");
}
/**
 * @brief it calculate the number of free seat available for a given bus
 * 
 * @param passenger: an array of passenger info on a given buse
 * @return int the number of free seat
 */
int calculateFreeSeat(string passenger[])
{
    int freeSeat = 0;
    for(int i = 0; i < SEAT_S; i++)
    {
        if(passenger[i].compare(" ") == 0)
        {
            freeSeat++;
        }
    }
    return freeSeat;
}
/**
 * @brief an extension function for appointSeat
 * 
 * @param i the seat number we need to assing
 * @param bus the structure of a bus we need to assing for custome
 * @param message the message we need to show when the error or success happen
 */
void assignSeat(int i, ActiveBus bus, string message)
{
    appointSeatPageHeader(bus);
    string *passenger = bus.passenger;
    for(int i = 0; i < SEAT_S; i++)
    {
        charPrinter(' ', 30);
        cout << "["  << setw(2) << right <<i << "]" << ' ';
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
    charPrinter('\n', 3);
    charPrinter(' ', 40);
    cout << "There are " << calculateFreeSeat(bus.passenger) << " empty seat in the Bus No " << bus.route.number << "\n \n"; 
    charPrinter(' ', 40);
    cout << message << endl;
    charPrinter(' ', 40);
    cout << "Please Enter The seat you want to assign:";
    int seatNo;
    string passengerName;
    cin>>seatNo;
    if(seatNo > 60)
    {
        string msg = "Please Enter a seat number less than 60";
        assignSeat(i, bus, msg);
    }
    if(passenger[seatNo].compare(" ") != 0)
    {
        string msg = "The place is already taken";
        assignSeat(i, bus, msg);
    }
    cout << endl;
    charPrinter(' ', 40);
    cout << "Please Enter The name of the passenger:";
    cin >> passengerName;
    passenger[seatNo] = passengerName;
    string msg = "Seat No : " + to_string(seatNo) + " Assigned to " + ' ' + passengerName;
    assignSeat(i, bus, msg);
}

void appointSeatPageHeader(ActiveBus bus)
{
    int a;
    system("clear");
    charPrinter(' ', 30);
    charPrinter('*', 125);
    cout << '\n';
    charPrinter(' ', 30);
    cout << "Driver:" << right << setw(30) << bus.bus.driverName;
    charPrinter(' ', 10);
    cout << "Arrival Time:" << setw(10) << bus.arrivatAt;
    charPrinter(' ', 10);
    cout << "Departure Time:" << setw(10) << bus.departureAt << endl;
    cout << '\n';
    charPrinter(' ', 30);
    cout << "From:" << setw(32) << bus.route.from;
    charPrinter(' ', 10);
    cout << "To:" << setw(15) << bus.route.end;
    charPrinter(' ', 15);
    cout << "Ticket Price:" << setw(10) << bus.route.price << "ETB" << endl;
    charPrinter(' ', 30);
    charPrinter('*', 125);
    cout << '\n';
}