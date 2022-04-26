#if !defined(MAIN_H)
#define MAIN_H
#include <string>
#include <vector>
using namespace std;
/**
 * @brief Bus - Hold the data about single bus
 * @number: the number that identifies where the bus coming from
 * @plateNumber: a unique plate number given to the bus
 * @driveName: the name of the driver of a specific bus
 */
#define TOTAL_BUS 1000
#define SEAT_S 60
#define ROUTE_S 112
struct Bus
{
    int number;
    int plateNumber;
    string driverName;
};

/**
 * @brief Routes: holds information about The routes a specific bus number follow
 * @from: initial place the bus departure
 * @end: arrival place
 * @through: the place in between the departure and arrival place
 */
struct Route
{
    int number;
    string from;
    string end;
    string through;
    string km;
    float price;
};
/**
 * @brief ActiveBus - Holds information about 
 * @Bus: a structure holds info about the bus
 * @arriveAt: the time the bus arrive the station
 * @departureAt: the time the bus leave the station
 */
struct ActiveBus
{
    Bus bus;
    string arrivatAt;
    string departureAt;
    string passenger[SEAT_S];
    Route route;
};

void printHomeScreenHeader(string message);
void charPrinter(char c, int n);
void printHomeScreen(vector<ActiveBus> activebus, vector<ActiveBus> history);
void switch_handler(int choice, vector<ActiveBus> activebus, vector<ActiveBus> history);
void scheduleBus(vector<ActiveBus> activebus, Bus buses[], Route routes[], vector<ActiveBus> history);
Bus searchBus(int plateNumber, Bus buses[]);
Route searchRoute(int number, Route routes[]);
Bus* getBusArray();
void appointSeat(vector<ActiveBus> buses);
void fillSeatArray(string passenger[]);
void showactivebus(vector<ActiveBus> buses, vector<ActiveBus> history);
int calculateFreeSeat(string passenger[]);
void printHistoryPage(vector<ActiveBus> active, vector<ActiveBus> history);

#endif
